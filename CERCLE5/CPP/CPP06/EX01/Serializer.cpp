#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    // Required by the subject: Data* -> uintptr_t using reinterpret_cast
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    // Required by the subject: uintptr_t -> Data* using reinterpret_cast
    return reinterpret_cast<Data *>(raw);
}
