#include <bitset>
#include <iostream>


int main(){
    // kodern bilgisayarlarda ulaşılabilir ne küçük memory uniti byte dır. bu yüzdenn bir nesen en azından 1 byte (8 bit olmalı)
    // bool değerlerde bu boş yere yer kaybına yol açar tabi bu durum beliirli durumlar haricinde çok önemli değildir
    // bu durumlar için 8 bool değerini pakatleyip saklayabilriz ki c++ bitleri tek tek değiştirebilelim diye bit manipulationunu sunar
    // A bit holding a 0 value is said to be “false”, “off”, or “not set”.
    // A bit holding a 1 value is said to be “true”, “on”, or “set”.
    // When a bit is changed from a 0 to a 1 or a 1 to a 0, we say it has been “flipped” or “inverted”.

    // signed int lerde son basamak +- belirttiği için unsigned int kullanacağız 
    // mesela 1.bit hayatta mı 2.bit susuz mu diye özellikleri var karşılık gelen sayısı da 28 ona göre durumunu öğrenenceğiz

    std::bitset<8> mybitset {}; // 8 bits in size means room for 8 flags
    // bellekte 8 bitlik alan ayır demiş olduk mesela 0b00000001 ama<4> deseydik ramda 0001 olarak saklanırdı
    
    // bit pozisyonları sağdan sola 76543210 diye

    std::bitset<8> bits {0b00000001}; // 0b bit oldugunu belli eder
    // test verilen bitin 0 mı 1 mi oldugunu söyler
    std::cout<<bits<<"\n"<<bits.test(0)<<" "<<bits.test(3)<<"\n";

    // bit game e git orda nasıl bir mantık kullandığımız görürsün bite oyunları için

    bits.flip(3);
    std::cout<<bits<<"\n";
    // flip ters çeviiri o biti

    // std::bitset hafıza kullanımı için değil hız için opitimize edilmiştir mesela <8> 1 byte kullanacığını söylese bile 
    // genelde 4 yada 8 byte kullanır
    /*
    Çoğu STL uygulamasında (GCC, Clang, MSVC) std::bitset arka planda dizi elemanı olarak tek bir unsigned long veya size_t tutar. 
    64-bit bir sistemde en küçük tamsayı bloğu 8 bayt (64 bit) olduğu için, sen 1 bit bile istesen arka planda en az 8 baytlık bir blok ayrılır.
    */

    // size() returns the number of bits in the bitset.
    // count() returns the number of bits in the bitset that are set to true.
    // all() returns a Boolean indicating whether all bits are set to true.
    // any() returns a Boolean indicating whether any bits are set to true.
    // none() returns a Boolean indicating whether no bits are set to true.

    std::cout << bits.size() << " bits are in the bitset\n";
    std::cout << bits.count() << " bits are set to true\n";

    std::cout << std::boolalpha;
    std::cout << "All bits are true: " << bits.all() << '\n';
    std::cout << "Some bits are true: " << bits.any() << '\n';
    std::cout << "No bits are true: " << bits.none() << '\n';

}