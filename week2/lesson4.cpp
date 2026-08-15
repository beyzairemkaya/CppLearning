// signed integer negatif pozitif 0 değerlerini tutabilirken unsigned non negativeleri tutabilir sadece
signed int x{};
// bu şekildede tanımlayabilirsin ama c++ da zaten default olarak signeddir o yüzden yazmman daha iyi
// 8 bitlik se -128 den 127 ye kadar değer tutar -(2n-1-1) to +(2n-1-1).
#include <iostream>

int main()
{
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    // mesela -2147483648 oldu
    std::cout << x << '\n';
    // c++ dada javaada oldugu gibi integer division olayı var inti inte böllersen sonuç int olur
    std ::cout<< 4/3<<"\n";

    // unsigned int  y{-8};
    // bunda narrowing conversion hatası verir ama şöyle yapsan 2^8-8 den karşılığını bulup getirecek o yüzden {} kullan hep
    unsigned int y=-8;
    std ::cout<< y<<"\n";

    unsigned int z{4294967295}; // max değer
    std ::cout<< z+1 <<"\n"; // modüler aritmetik kullanır yani başa döner 0 yazdırır
    std ::cout<< z+2 <<"\n"; // devam eder 1 yazdırır

    // geriye dönemk de mümkündür örneğin
    unsigned int m {0};
    std ::cout<< m-1 <<"\n"; // max değer
    std ::cout<< m-2 <<"\n"; // max değerin 1 eksiği diye devam eder

    

    return 0;
}
/*
01111111 11111111 11111111 11111111
+                                   1
-------------------------------------
10000000 00000000 00000000 00000000
two's compliment kullanıldığı için böyle oldu
*/

// When no negative numbers are required, unsigned integers are well-suited for networking and systems with little memory, 
// because unsigned integers can store more positive numbers without taking up extra memory.

// coğunlukla unsigned int kullanılmaması önerilir çünkü signed intler unsigned a göre 0 dan her iki yönden de çok uzaktır 
// overflow olması zorlaşır. örn unsignedda 2-3 bile sıkıntı çıkarabilir

/*
unsigned ve signed ile işlem yaparsan signed unsigned a çevrilir
#include <iostream>

// assume int is 4 bytes
int main()
{
	unsigned int u{ 2 };
	signed int s{ 3 };

	std::cout << u - s << '\n'; // 2 - 3 = 4294967295

	return 0;
*/
/*
unsigned int i{3};

while (i >= 0)
{
    std::cout << i << '\n';
    --i;
}
bu döngünün sonsuza kadar devam edeceğine dikkat et max rakama gidecek pozitis olan asla negatif olmauyacak 
*/
/*
Sonuç olarak bazı case ler dışında unsigned dan kaçın
istisnalar:
First, unsigned numbers are preferred when dealing with bit manipulation (covered in chapter O -- that’s a capital ‘o’, not a ‘0’). 
They are also useful when well-defined wrap-around behavior is required (useful in some algorithms like encryption and random number generation)

Second, use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing. We’ll talk more about 
this in the lessons on arrays and array indexing.

Also note that if you’re developing for an embedded system (e.g. an Arduino) or some other processor/memory limited context, use of unsigned
numbers is more common and accepted (and in some cases, unavoidable) for performance reasons.
*/

// Eğer int tipini sabitlemek istiyorsan bunun için std kullan
/*
std::int8_t	    1 byte signed	   -128 to 127	Treated like a signed char on many systems. See note below.
std::uint8_t	1 byte unsigned	0 to 255	    Treated like an unsigned char on many systems. See note below.
std::int16_t	2 byte signed	-32,768 to 32,767	
std::uint16_t	2 byte unsigned	0 to 65,535	
std::int32_t	4 byte signed	-2,147,483,648 to 2,147,483,647	
std::uint32_t	4 byte unsigned	0 to 4,294,967,295	
std::int64_t	8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	
std::uint64_t	8 byte unsigned	0 to 18,446,744,073,709,551,615	
*/
// ama fix width her zaman iyi bir çözüm değildir mesela bilgisayarın 64 bitdir std::int32_t kullanman yavaşlatır bilgisiyarı
// ama bunlar çok küçük problemler o yüzden tam olarak 32 bit gerekiyorsa 32 bit kullan yoksa int kullan geç
// Donanımla çalışıyorsan (STM32, Arduino, CAN, sensörler) → Fixed-width tipleri kullan. ama normal masaüstü uygulamsıysa int kullan geç
