# include <iostream>
# #include <bitset>
int main(){
    // ne sistemi kullanırsan kullan 10 tabandır octal sistemde 10 1 tane 8 demek mesela
    // c++ da octal sistemmi kullanmak için sayının başına 0 koyarsın
    int nm {012};
    // 8+2 =10 luk sistemdeki 10 std cout da 10 yazdırır
    std::cout<<nm<<"\n";
    std::cout<<025<<"\n"; // 8*2+5=21 yazdırır

    // octal az kullanılır hexadecimalı öğrenelim
    // 0x veya 0X prefx i kullanılır (0x daha yaygın)
    // 0 1 2 3 4 5 6 7 8 9 A B C D E F , 10
    // küçük harfleide kullanabilirisn ama büyük harfler daha yayhın
    std::cout<<0x1F<<"\n"; // 31 
    /*
    Consider a 32-bit integer with binary value 0011 1010 0111 1111 1001 1000 0010 0110. 
    Because of the length and repetition of digits, that’s not easy to read. In hexadecimal, this same value would be: 3A7F 9826, 
    which is much more concise. For this reason, hexadecimal values are often used to represent memory addresses or raw data in memory 
    (whose type isn’t known).
    */

    // std cout decimalde yazdırı ama istersen octa veya hexadeciamlde yazdırabilrisin
    std::cout<<std::oct<<14<<"\n";
    std::cout<<std::hex<<100<<"\n";
    // bir kere uygulandımı yeni kural uygulana kadar ondan devam eder decinale dönmemiz gerek
    std::cout<<std::dec;

    // std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1100'0101 }; // binary literal for binary 1100 0101
	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101

	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n'; // create a temporary std::bitset and print it

    
}

int mn()
{
    // Prior to C++14, there is no support for binary literals. However, hexadecimal literals provide us with a useful 
    // workaround (that you may still see in existing code bases):
    int bin{};    // assume 16-bit ints
    bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
    bin = 0x0002; // assign binary 0000 0000 0000 0010 to the variable
    bin = 0x0004; // assign binary 0000 0000 0000 0100 to the variable
    bin = 0x0008; // assign binary 0000 0000 0000 1000 to the variable
    bin = 0x0010; // assign binary 0000 0000 0001 0000 to the variable
    bin = 0x0020; // assign binary 0000 0000 0010 0000 to the variable
    bin = 0x0040; // assign binary 0000 0000 0100 0000 to the variable
    bin = 0x0080; // assign binary 0000 0000 1000 0000 to the variable
    bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
    bin = 0x00B3; // assign binary 0000 0000 1011 0011 to the variable
    bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable

    return 0;
}


int mn2()
{
    int bin{};        // assume 16-bit ints
    bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

    int bin2 { 0b1011'0010 };  // assign binary 1011 0010 to the variable
    long value { 2'132'673'462 }; // much easier to read than 2132673462
    // Because long literals can be hard to read, C++14 also adds the ability to use a quotation mark (‘) as a digit separator.


    return 0;
}
/*
n C++20 and C++23, we have better options for printing binary via the new Format Library (C++20) and Print Library (C++23):

#include <format> // C++20
#include <iostream>
#include <print> // C++23

int main()
{
    std::cout << std::format("{:b}\n", 0b1010);  // C++20, {:b} formats the argument as binary digits
    std::cout << std::format("{:#b}\n", 0b1010); // C++20, {:#b} formats the argument as 0b-prefixed binary digits

    std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23, format/print two arguments (same as above) and a newline

    return 0;
}
This prints:

1010
0b1010
1010 0b1010
*/