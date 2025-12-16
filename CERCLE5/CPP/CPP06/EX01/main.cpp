#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

static void sep()
{
    std::cout << "------------------------------------------------------------\n";
}

static void show(const char* label, Data* p)
{
    std::cout << label << " ptr=" << p;

    // Adapte si tes champs ont d'autres noms
    std::cout << " | id=" << p->id << " | name=" << p->name << "\n";
}

static bool sameContent(const Data& a, const Data& b)
{
    // Adapte si tes champs ont d'autres noms
    return (a.id == b.id && a.name == b.name);
}

static void runTest(const char* title, Data* original)
{
    sep();
    std::cout << title << "\n";
    sep();

    // Snapshot des données AVANT (copie de la structure, pour comparer)
    Data before = *original;

    show("Before      :", original);

    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Serialized  : raw=" << raw << "\n";
    show("After       :", restored);

    std::cout << "Pointer same: " << (original == restored ? "OK ✅" : "KO ❌") << "\n";
    std::cout << "Data same   : " << (sameContent(before, *restored) ? "OK ✅" : "KO ❌") << "\n";
}

int main()
{
    sep();
    std::cout << "CPP06 - ex01: Serialization (reinterpret_cast)\n";
    std::cout << "Goal: Data* -> uintptr_t -> Data* (same address, unchanged data)\n";
    sep();

    // TEST 1: stack
    Data a;
    a.id = 10;
    a.name = "stack_A";
    runTest("TEST #1 - Stack object", &a);

    // TEST 2: another stack object
    Data b;
    b.id = 100;
    b.name = "stack_B";
    runTest("TEST #2 - Another stack object", &b);

    // TEST 3: heap
    Data* c = new Data;
    c->id = 7;
    c->name = "heap_C";
    runTest("TEST #3 - Heap object", c);

    sep();
    std::cout << "Cleaning heap object...\n";
    delete c;
    sep();

    std::cout << "Conclusion: serialize/deserialize do not change anything; they only transport the address.\n";
    sep();
    return 0;
}
