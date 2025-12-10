// ex01/main.cpp
#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.id = 42;
    data.name = "Hello serialization";
    data.value = 3.14159;

    Data *ptr = &data;

    std::cout << "Original pointer : " << ptr << std::endl;
    std::cout << "Data content     : id=" << data.id
              << ", name=" << data.name
              << ", value=" << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized value : " << raw << std::endl;

    Data *restored = Serializer::deserialize(raw);
    std::cout << "Restored pointer : " << restored << std::endl;
    std::cout << "Restored content : id=" << restored->id
              << ", name=" << restored->name
              << ", value=" << restored->value << std::endl;

    if (restored == ptr)
        std::cout << "Pointers are equal: serialization/deserialization OK." << std::endl;
    else
        std::cout << "Pointers differ: something went wrong." << std::endl;

    return 0;
}
