// Data Types

// standart Integer types short,int long, long long dur 
// Integral type lar ise standart integer typle la birlikte bellekte hafızada integer olarak saklanan diğer değerleride kapsar (bool ve char)
// Many of the types defined in newer versions of C++ (e.g. std::nullptr_t) use a _t suffix. This suffix means “type”, and it’s a common 
// nomenclature applied to modern types.
// If you see something with a _t suffix, it’s probably a type. But many types don’t have a _t suffix, so this isn’t consistently applied.
// void value; // won't work, variables can't be defined with incomplete type void
// compound data types struct arrays class pointer ve enum
// örrnğin java bir int 32 bit olacağını garnti ederken c++ san böyle bir garanti vermez
// farklı mimamrilerde farklı çalışır örneğin bir yerde bir int 4 diğer yerde 2 veya 8 olabilir
// c++ sadece minimum kaplayacağı yeri garanti edebilir örneğin int>=16 bit deriz
// char>=8, short>=16 ,int>=16, long>=32, long long>=64
// char and char8_t are exactly 1 byte (at least 8 bits). charın 1 byte olacağı kesin ama 1 byte ın kaç bit olacağı kesin değil

#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}

/*
sizeof does not include dynamically allocated memory used by an object. We discuss dynamic memory allocation in a future lesson.

On modern machines, objects of the fundamental data types are fast, so performance while using or copying these types should generally not be a 
concern.
You might assume that types that use less memory would be faster than types that use more memory. This is not always true. CPUs are often 
optimized to process data of a certain size (e.g. 32 bits), and types that match that size may be processed quicker. On such a machine, 
a 32-bit int could be faster than a 16-bit short or an 8-bit char.*/
