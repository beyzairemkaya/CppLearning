#include <iostream>
#include <cstdint>

int main(){
    // implicit cast conversion
    // int i {7.5};
    // treat warning as errors dediğimiz için hata veriri ama açmazsan o ayarı 7 olarak yazar
    double db {5};
    std::cout<<db<<"\n"; // std cout 5.0 ı 5 olarak yazdığı için yazırmadı yoks implicit type conversion yaptı
    
    // peki değer kaybetme umrumuzda değilse uyarı vermeden type conversion nasıl yaptırırrız
    // burda treat warning as eerroru kapatabilirsin am oda çok iyi bir yol değildir
    // en iyisi explicit type conversion yapmaktır
    // static_cast<new_type>(expression) 

    double db2{7.8};
    std::cout<<static_cast<int>(db2)<<"\n";
    // uyarı vermeden dönüşiümü yaptı

    //char ın int değerini de şu şekilde çeeriz
    char ch {100};
    std::cout<<ch<<": "<<static_cast<int>(ch)<<"\n";

    // static_cast kullanarak signed ve unsigned dönüşümlerinide yapabilirsin
    int a{7};
    unsigned int b {static_cast<unsigned int>(a)};
    // unsigned int c {a}; bu satıra narrowing conversion hatası verir

    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

    unsigned int u { 4294967295 }; // largest 32-bit unsigned int
    std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20
    // wrapped durumlara geri döner two's compelemnt yoluyla

    // std::int8_t, std::uint8_t char gibi davranır demiştik
    std::int8_t m {65};
    std::cout<<m<<"\n";
    // 65 değil A yazdırdı bazoı sistemlerde 65 de yazdırabilir ama kesinlik yok
    // yine static castla çözeriz bu problemi
    std::cout<<static_cast<int>(m)<<"\n"; // böyle yazdırılır

    std::cout << "Enter a number between 0 and 127: ";
    std::int8_t myInt{};
    std::cin >> myInt;

    std::cout << "You entered: " << static_cast<int>(myInt) << '\n';
    /*
    Here’s what’s happening. When std::int8_t is treated as a char, the input routines interpret our input as a sequence of characters, 
    not as an integer. So when we enter 35, we’re actually entering two chars, '3' and '5'. Because a char object can only hold one character, 
    the '3' is extracted (the '5' is left in the input stream for possible extraction later). Because the char '3' has ASCII code point 51, 
    the value 51 is stored in myInt, which we then print later as an int.
    In contrast, the other fixed-width types will always print and input as integral values.
    */

    return 0;



}