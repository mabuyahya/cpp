#include "FileContant.hpp"

int main(int argc, char **argv) {
    if (argc != 4){
        std::cout << "the arg should be only 3 : filename , s1, s2\n";
        return (1);
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    FileContant test(filename);
    try {
        test.readFileContant();
    }
    catch(...) {
        return (1);
    }
    test.fileContantReplace(s1, s2);
    try {
        test.outputFileContantToFile();
    }
    catch(...) {
        return (1);
    }
}