#include "BitcoinExchange.hpp"

void BitcoinExchange::parseFile(std::string fileName){
    readData(fileName, FILEDATA_MODE);
    validateData(FILEDATA_MODE);
}

int BitcoinExchange::validValue(std::string value){
    size_t i = 0;
    int dotCount = 0;
    int digitCount = 0;
    if (value[0] == '+' || value[0] == '-') {
        if (value.size() == 1) 
            return 0;
        i = 1;
    }

    for (; i < value.size(); ++i) {
        if (value[i] == '.') {
            if (++dotCount > 1)
                return 0;
        } else if (std::isdigit(value[i])) {
            ++digitCount;
        } else {
            return 0;
        }
    }
    if (value[value.size() - 1] == '.')
        return 0;
    if (digitCount == 0)
        return 0;
    return 1;
}

int BitcoinExchange::checkAllDigit(std::string year, std::string month, std::string day){
    for (size_t i = 0; i < year.size(); i++)
    {
        if (!std::isdigit(year[i]))
            return (0);
    }
    for (size_t i = 0; i < month.size(); i++)
    {
        if (!std::isdigit(month[i]))
            return (0);
    }
    for (size_t i = 0; i < day.size(); i++)
    {
        if (!std::isdigit(day[i]))
            return (0);
    }
    return (1);
}

int BitcoinExchange::validDate(std::string date){
    int count = 0;
    for (size_t i = 0; i < date.size(); i++){
        if (date[i] == '-')
            count++;
    }
    if (count != 2)
        return (0);
    int pos[2];
    pos[0] = date.find_first_of("-");
    pos[1] = date.find_last_of("-");
    std::string year = trem(date.substr(0, pos[0]));
    std::string month = trem(date.substr(pos[0] + 1, pos[1] - pos[0] - 1));
    std::string day = trem(date.substr(pos[1] + 1));
    if (year.empty() || month.empty() || day.empty())
        return (0);
    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return (0);
    if (!checkAllDigit(year, month, day))
        return (0);
    int yearI = std::atoi(year.c_str());
    int monthI = std::atoi(month.c_str());
    int dayI = std::atoi(day.c_str());
    if (yearI < 0 || yearI > 2025 || monthI < 1 || monthI > 12 || dayI < 1 || dayI > 31)
        return (0);
    return (1);
}

std::string BitcoinExchange::trem(std::string str){
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return ("");
    int len = str.find_last_not_of(" \n \t") - first + 1;
    return(str.substr(first, len));
}

int BitcoinExchange::checkHeader(std::string str, std::string del, std::string first, std::string secand){
    size_t delIndex = str.find(del);
    if (delIndex == std::string::npos)
        return (0);
    if (first != trem(str.substr(0, delIndex)))
        return (0);
    if (secand != trem(str.substr(delIndex + 1)))
        return (0);
    return (1);
}

int BitcoinExchange::checkLine(std::string str, int mode){
    std::string del = (mode == DATABASE_MODE ? "," : "|");
    size_t delIndex = str.find(del);
    if (delIndex == std::string::npos)
        return (0);
    std::string date = trem(str.substr(0, delIndex));
    std::string value = trem(str.substr(delIndex + 1));
    if (date.empty() || value.empty())
        return (0);
    if (!validDate(date) ||  !validValue(value))
        return (0);
    if (mode == DATABASE_MODE){
        dataBaseMap[date] = std::atof(value.c_str());
    }
    else{
        if (std::atof(value.c_str()) <= 0 || std::atof(value.c_str()) >= 1000)
        {
            if (std::atof(value.c_str()) <= 0)
                return (NOTPOS);
            else 
                return (TOOLARG);
        }
        fileDate = date;
        fileValue = std::atof(value.c_str());
    }
    return (1);
}

void    BitcoinExchange::validateData(int mode){
    size_t i = 0;
    size_t end = 0;
    size_t len = 0;
    std::string line;

    std::string del = (mode == DATABASE_MODE ? "," : "|");
    std::string first = "date";
    std::string secend = (mode == DATABASE_MODE ? "exchange_rate" : "value");
    std::string data = (mode == DATABASE_MODE ? dataBase : fileData);

    int errorKind;
    end = data.find("\n", i);
    if (end == std::string::npos)
        end = data.size();
    len = end - i;
    line = data.substr(i, len);
    if (!checkHeader(line, del, first, secend))
    {
        std::cout << "Error: bad header => " << line << std::endl;
        throw std::runtime_error("Bad header");
    }
    i = end + 1;
    while (i < data.size())
    {
        end = data.find("\n", i);
        if (end == std::string::npos)
            end = data.size();
        len = end - i;
        line = data.substr(i, len);
        i = end + 1;
        errorKind = checkLine(line, mode);
        if (errorKind != 1 && mode == DATABASE_MODE)
        {
            std::cout << "Error: bad input " << line << std::endl;
            throw std::runtime_error("Bad database input");
        }
        else if (mode == FILEDATA_MODE)
        {
            if (errorKind == NONE)
            {
                std::cout << "Error: bad input " << line << std::endl;
            }
            else if (errorKind == NOTPOS)
            {
                std::cout << "Error: not a positive number.\n";
            }
            else if (errorKind == TOOLARG)
            {
                std::cout << "Error: too large a number.\n";
            }
            else if (errorKind == 1){
                std::map<std::string, float>::const_iterator it = dataBaseMap.lower_bound(fileDate);
                if (it->first == fileDate || it == dataBaseMap.begin())
                {
                    std::cout << fileDate << " => " << fileValue << " = " << fileValue * it->second << std::endl;
                }
                else
                {
                    --it;
                    std::cout << fileDate << " => " << fileValue << " = " << fileValue * it->second << std::endl;
                }
            }
        }
    }
}

void    BitcoinExchange::readData(std::string fileName, int mode){
    std::ifstream    file(fileName.c_str());
    if (!file || !file.is_open()){
        std::cout << "Error: could not open file. : " << fileName << std::endl;
        file.close();
        throw std::runtime_error("could not open file.");
    }
    std::ostringstream dataBaseStream;
    dataBaseStream << file.rdbuf();
    if (mode == DATABASE_MODE)
        dataBase = dataBaseStream.str();
    else 
        fileData = dataBaseStream.str();
}

BitcoinExchange::BitcoinExchange()
{
    readData("data.csv", DATABASE_MODE);
    validateData(DATABASE_MODE);
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    readData(fileName, DATABASE_MODE);
    validateData(DATABASE_MODE);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &tt)
{
    dataBaseMap = tt.dataBaseMap;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &tt)
{
    if (this != &tt)
        dataBaseMap = tt.dataBaseMap;
    return(*this);
}