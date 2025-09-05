#ifndef FILECONTANT_HPP
#define FILECONTANT_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 


class FileContant {
    private:
        std::string fileContant;
        std::string fileName;
    public:
        FileContant( std::string fileName );
        void readFileContant();
        void  printFileContact();
        void fileContantReplace( std::string s1, std::string s2 );
        void outputFileContantToFile();
};


#endif 