#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cout << "the arg should be 1\n";
        return(1);
    }
    Harl test;
    std::string input = argv[1];
    test.complain(input);
}