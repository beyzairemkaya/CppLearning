#include <iostream>
#include <typeinfo>

// numeric promitiion (zaten yüksleme demek)
// daha alt tiplerden üst tiplere geçiş mesela short veya char ıjn intye geçmesi veya floatın double a geçmes
//her char değeri için bir int değeri olacağı için değişim güvenlidir
void printInt(int x ){
    std::cout<<x<<"\n";
}
void printDouble(double d)
{
    std::cout << d << '\n';
}
void print(unsigned int u) // note: unsigned
{
    std::cout << u << '\n';
}

int main(){
    printInt('A');
    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double
    // mesela altakiler promititon değil conversion çünkü
    std::cout << "Enter an integral value: ";
    int n{};
    std::cin >> n; // enter 5 or -5
    print(n);      // conversion to unsigned may or may not preserve value
    // - li rakam girersen wrep out olur hata vermez
    print(-7); // bu da hata vermez wrap out olur
    // int n2 { 5.0 }; // compile error norrawing conversion çünkü compile zamanında değerini bilmyoru unutma
    // constexpr int n2 { 5.0 };
    // constexpr double n3 {6.0};
    // int n4 {n3};
    // hepsi narrowing conversion aralığa uysa ve contexpr olsa bile
    int n22 = 5.0 ;
    constexpr int n2= 5.0 ;
    constexpr double n3 =6.0;
    int n4 =n3;
    // bu şekilde sorun yok ama brace intialiationda sorun avrdı 


    constexpr int n11{ 5 };   // note: constexpr
    unsigned int u1 { n11 };  // okay: conversion is not narrowing due to exclusion clause

    constexpr int n21 { -5 }; // note: constexpr
    // unsigned int u2 { n21 };  // compile error: conversion is narrowing due to value change
    // Some constexpr conversions aren’t considered narrowing


    // char short gibi tiplerle aritmetik işlem yaparken int e çevrilirler örneğin
    short a{ 4 };
    short b{ 5 };
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n'; // show us the type of a + b

    std::cout << std::boolalpha << (-3 < 5u) << '\n';
    // ikiside aynı typemoldugu iin unsigned a çevirlir -3 çok nüyük br sayı olur false döner
    /*
    In future lessons, we’ll encounter cases where it is useful to know what the common type of two type is. 
    std::common_type and the useful type alias std::common_type_t (both defined in the <type_traits> header) can be used for just this purpose.
    For example, std::common_type_t<int, double> returns the common type of int and double, and std::common_type_t<unsigned int, long> 
    returns the common type of unsigned int and long.

    */
   float j { 5.0 };
   // doubledan floata dönmezz deme literald e constexpr oldugu için hata vermez


    return 0;
    

}
/*
The integral promotion rules are more complicated.

Using the integral promotion rules, the following conversions can be made:
- signed char or signed short can be converted to int.
- unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type, or unsigned int otherwise.
- If char is signed by default, it follows the signed char conversion rules above. If it is unsigned by default, it follows the unsigned char 
conversion rules above.
- bool can be converted to int, with false becoming 0 and true becoming 1.
- Assuming an 8 bit byte and an int size of 4 bytes or larger (which is typical these days), the above basically means that bool, char, 
signed char, unsigned char, signed short, and unsigned short all get promoted to int.
Some widening type conversions (such as char to short, or int to long) are not considered to be numeric promotions in C++ (they are numeric 
conversions, which we’ll cover shortly in lesson 10.3 -- Numeric conversions). 
This is because such conversions do not assist in the goal of converting smaller types to larger types that can be processed more efficiently.
*/
/*
 int b { 'a' }; 
 chardan inte numaric promition

 long h { 5 }; 
 buda CONVERİSİON ÇÜNKÜ EN OPTİMİZE haline dönmüyor
 
*/