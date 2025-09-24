#include "Serializer.hpp"

int main() {
    Data data = {"test"};
    Data *ptr = &data;
    uintptr_t num =  Serializer::serialize(ptr);
    Data *addr =  Serializer::deserialize(num);
    std :: cout << &data << std::endl;
    std :: cout << addr << std::endl;
    std :: cout << data.name << std::endl;
    std :: cout << addr->name << std::endl;
}