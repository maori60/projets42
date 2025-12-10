// ex01/Serializer.cpp
#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(const Serializer &)
{
    return *this;
}
Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    // ICI : cast spécifique de l'exo : reinterpret_cast
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    // On reconvertit l'entier en pointeur
    return reinterpret_cast<Data *>(raw);
}
