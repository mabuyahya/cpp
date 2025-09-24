#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}
Serializer::Serializer(const Serializer & tt){
    (void ) tt;
}

Serializer & Serializer::operator=(const Serializer & tt){
    (void ) tt;
    return(*this);
}


uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t aSnum = reinterpret_cast<uintptr_t>(ptr);
    return (aSnum);
}

Data* Serializer::deserialize(uintptr_t num){
    Data* asPtr = reinterpret_cast<Data*>(num);
    return(asPtr); 
}