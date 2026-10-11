#include <iostream>

int main(){
    // void*, belirli bir veri türüne bağlı olmayan genel amaçlı bir pointer'dır.
    int x = 10;
    double y = 3.14;

    void* ptr = &x; // Geçerli
    ptr = &y;       // Bu da geçerli!
    // Void pointer dereference edilemez!
    int x = 10;
    void* ptr = &x;

    // std::cout << *ptr; // ERROR!

    // Pointer'ı tekrar doğru türe dönüştürmeliyiz (casting).
    int* intPtr = static_cast<int*>(ptr);
    std::cout << *intPtr; // 10
    /*
    *ptr;       // ERROR: Dereference yapılamaz
    ptr[0];     // ERROR: Indexleme yapılamaz
    ptr + 1;    // ERROR: Pointer arithmetic yapılamaz
    */
}

/*
#include <cassert>
#include <iostream>

enum class Type
{
    tInt, // note: we can't use "int" here because it's a keyword, so we'll use "tInt" instead
    tFloat,
    tCString
};

void printValue(void* ptr, Type type)
{
    switch (type)
    {
    case Type::tInt:
        std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
        break;
    case Type::tFloat:
        std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and perform indirection
        break;
    case Type::tCString:
        std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no indirection)
        // std::cout will treat char* as a C-style string
        // if we were to perform indirection through the result, then we'd just print the single char that ptr is pointing to
        break;
    default:
        std::cerr << "printValue(): invalid type provided\n";
        assert(false && "type not found");
        break;
    }
}

int main()
{
    int nValue{ 5 };
    float fValue{ 7.5f };
    char szValue[]{ "Mollie" };

    printValue(&nValue, Type::tInt);
    printValue(&fValue, Type::tFloat);
    printValue(szValue, Type::tCString);

    return 0;
}
*/

/*
Void pointer miscellany

Void pointers can be set to a null value:

void* ptr{ nullptr }; // ptr is a void pointer that is currently a null pointer
Because a void pointer does not know what type of object it is pointing to, deleting a void pointer will result in undefined behavior. 
If you need to delete a void pointer, static_cast it back to the appropriate type first.

It is not possible to do pointer arithmetic on a void pointer. This is because pointer arithmetic requires the pointer to know what size
object it is pointing to, so it can increment or decrement the pointer appropriately.

Note that there is no such thing as a void reference. This is because a void reference would be of type void &, and would not know what 
type of value it referenced.

Although the above function seems like a neat way to make a single function handle multiple data types, 
C++ actually offers a much better way to do the same thing (via function overloading) that retains type checking to help prevent misuse. 
Many other places where void pointers would once be used to handle multiple data types are now better done using templates, which also offer 
strong type checking.
*/

