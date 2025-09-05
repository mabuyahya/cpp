#include "FileContant.hpp"

FileContant::FileContant(std::string fileName)
{
    this->fileName = fileName;
}

void FileContant::readFileContant()
{
    std::ifstream infile(fileName.c_str());
    std::ostringstream stringStreamObj;

    if (!infile)
    {
        std::cout << "error opening " << fileName << " file\n";
        throw 2;
    }
    stringStreamObj << infile.rdbuf();
    fileContant = stringStreamObj.str();
    infile.close();
}
void FileContant::printFileContact() {
    std::cout << fileContant << "\n";
}


void FileContant::fileContantReplace(std::string s1, std::string s2){
    size_t matchPos;
    size_t searchPos;
    std::string finalString;
    matchPos = 0;
    searchPos = 0;
    for (int i = 0;true; i++)
    {
        matchPos = fileContant.find(s1, searchPos);
        if (matchPos == std::string::npos)
            break ;
        finalString += fileContant.substr(searchPos, matchPos - searchPos);
        finalString += s2;
        searchPos = matchPos + s1.length();
    }
    finalString += fileContant.substr(searchPos);
    fileContant = finalString;
}

void FileContant::outputFileContantToFile(){
    std::string outfileName =  fileName + ".replace";
    std::ofstream outfile(outfileName.c_str());
    if (!outfile)
    {
        std::cout << "can't open " << outfileName << " file\n";
        throw 3;
    }
    outfile << fileContant;
    outfile.close();
}