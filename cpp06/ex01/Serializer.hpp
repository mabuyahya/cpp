#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include  <string>
#include  <stdint.h>
#include  <iostream>

struct Data
{
    std::string name;
};


class Serializer
{
private:
    Serializer();
    ~Serializer();
    Serializer(const  Serializer  &);
    Serializer & operator=(const  Serializer  &);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t num);
};



#endif