#include <iostream>
#include <string>
#include "Array.hpp"

#define SEP "------------------------------------------------------------"

static void ok(const std::string& msg)   { std::cout << "[OK]   " << msg << std::endl; }
static void fail(const std::string& msg) { std::cout << "[FAIL] " << msg << std::endl; }

template <typename T>
void printArray(Array<T> const& arr, const std::string& name)
{
    std::cout << name << " (size=" << arr.size() << "): ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

struct TestStruct
{
    int  n;
    char c;
};

std::ostream& operator<<(std::ostream& os, TestStruct const& s)
{
    os << s.n << s.c;
    return os;
}

int main(void)
{
    std::cout << "\n" << SEP << std::endl;
    std::cout << "EX02 - ARRAY<T> TESTS" << std::endl;
    std::cout << SEP << "\n" << std::endl;

    // 1) Default constructor
    std::cout << "1) Default constructor (empty array)" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    if (empty.size() == 0) ok("Default constructor creates an empty array");
    else fail("Default constructor size should be 0");
    std::cout << SEP << std::endl;

    // 2) Out of bounds
    std::cout << "2) Out of bounds (must throw std::exception)" << std::endl;
    try
    {
        (void)empty[5];
        fail("Accessing empty[5] should throw, but didn't");
    }
    catch (const std::exception& e)
    {
        ok(std::string("Exception thrown: ") + e.what());
    }
    std::cout << SEP << std::endl;

    // 3) Read/Write with operator[]
    std::cout << "3) operator[] (read & write)" << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i;

    printArray(intArray, "intArray");
    if (intArray[0] == 0 && intArray[4] == 4) ok("Write/read through operator[] works");
    else fail("operator[] read/write seems incorrect");
    std::cout << SEP << std::endl;

    // 4) Works with another simple type
    std::cout << "4) Template works with another type (double)" << std::endl;
    Array<double> doubleArray(5);
    for (unsigned int i = 0; i < doubleArray.size(); i++)
        doubleArray[i] = i * 0.5;

    printArray(doubleArray, "doubleArray");
    ok("Array<double> compiles and runs");
    std::cout << SEP << std::endl;

    // 5) Copy constructor (deep copy)
    std::cout << "5) Copy constructor (deep copy check)" << std::endl;
    Array<int> copy(intArray);

    // modify original to check deep copy
    intArray[0] = 999;

    std::cout << "After modification: intArray[0]=999" << std::endl;
    std::cout << "copy[0] should stay 0" << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;
    std::cout << "copy[0]     = " << copy[0] << std::endl;

    if (copy[0] == 0) ok("Deep copy OK (copy not affected)");
    else fail("Not a deep copy (copy changed with original)");
    std::cout << SEP << std::endl;

    // 6) Assignment operator (deep copy)
    std::cout << "6) Assignment operator (deep copy check)" << std::endl;
    Array<int> assigned;
    assigned = copy;

    copy[1] = 888;

    std::cout << "After modification: copy[1]=888" << std::endl;
    std::cout << "assigned[1] should stay 1" << std::endl;
    std::cout << "copy[1]     = " << copy[1] << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;

    if (assigned[1] == 1) ok("Deep assignment OK (assigned not affected)");
    else fail("Not a deep assignment (assigned changed with source)");
    std::cout << SEP << std::endl;

    // 7) Const instance access
    std::cout << "7) Const instance (read-only operator[])" << std::endl;
    const Array<int> constArr(assigned);
    printArray(constArr, "constArr");
    ok("Const array can be read through operator[] const");
    std::cout << SEP << std::endl;

    // 8) Complex type
    std::cout << "8) Complex type (user-defined struct)" << std::endl;
    Array<TestStruct> structArr(3);
    structArr[0] = (TestStruct){0, 'a'};
    structArr[1] = (TestStruct){1, 'b'};
    structArr[2] = (TestStruct){2, 'c'};

    printArray(structArr, "structArr");
    ok("Array<struct> compiles and runs");
    std::cout << "\n" << SEP << std::endl;
    std::cout << "END" << std::endl;
    std::cout << SEP << std::endl;

    return 0;
}
