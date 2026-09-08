#include <bitset>
#include <iostream>

// Bit Operatörleri

int main(){
    // left shift  :    x<<n x in bitleri n adım sola kayar yeni bitler 0 dır
    // right shift :    x>>n x in bitleri n adım sağa kayar yeni bitler 0 dır
    // bitwise NOT :    ~x  tüm bitler tersine döner
    // bitwise AND :    x&y bit bit bakar ikiisde 1 se o bit için 1 yapar 1010 1001 =) 1000
    // bitwise OR  :    x|y ikiisnden biri 1 se 1 dir  1010 1001 =) 1011
    // bitwise XOR :    x^y corresponding bitler farklı ise 1 döner  1010 1001 =) 0011

    // To avoid surprises, use the bitwise operators with unsigned integral operands or std::bitset.
    // 0101<<3 0100 olur 3.bitteki1 sonsuza kaadar kayboldu bit boyutuu aşmaz

    std::bitset<4> bits {0b1001};
    std::cout<<(bits<<2)<<" "<< bits <<" "<<(bits>>3)<<"\n";
    // dikkat () kullanmayı unutsaydın bits2 yani 10012 yazdırıdır unutma o yüzden
    // bitin kendisini değiştirmez yeni değişken atamalaısın
    std::bitset<4> bits2 {bits<<3};
    std::cout<<bits2<<"\n";
    // bit alanı bitmedikçe left shift iki ile çarpma rigt shif ikiye bölme oluguna fikka et 
    // sola kaydırıken herkes 2 katı fazk-lasına gidiyor 4 den 8 e gibi sağa kaydırıken de yarısınıa ama 1000<<1 yapasean sonuç 0 olur

    std::bitset<4> b4{ 0b100 }; // b4 is 0100
    std::bitset<8> b8{ 0b100 }; // b8 is 0000 0100

    std::cout << "Initial values:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << "\n\n";

    b4 = ~b4; // flip b4 to 1011
    b8 = ~b8; // flip b8 to 1111 1011

    std::cout << "After bitwise NOT:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';

    

    // bitwise not bitleri tersine çevirir eğer integera çevirmek istersen doğal oalrakboyuta bağlı farklı sonuçalr üretir
    // to_ulong std bitset in içinde gelir int e çevirmek istesrn bundan static cast yapmalısın

    std::cout<<(std::bitset<4>(0b1000)|std::bitset<4>(0b1010)|std::bitset<4>(0b1001))<<"\n";
    // sadece iki tane değil istediğin akdar girebilirisn or da 1 tane 1 olması yeterli o bit columnunda and ise 1 olması için hepsi 1 olmalı
    std::cout<<(std::bitset<4>(0b1000)&std::bitset<4>(0b1010)&std::bitset<4>(0b1001))<<"\n";

    // The last operator is the bitwise XOR (^), also known as exclusive or.
    std::cout<<(std::bitset<4>(0b1000)^std::bitset<4>(0b1010)^std::bitset<4>(0b1001))<<"\n";
    // 1000^1010= 0010 0010^1001=1011 gruplama sağdan sola
    // normalde sıralma önemli değilde side effects varsa önemli

    // direkt assigment yapabilirsin

    std::cout<<"---bit3---\n";
    std::bitset<4> bits3 {0b1111};
    // 0b yazmayı hep unjtuyorsun sonra int olarak işlem yapıyor sende ne yapıyor bu diyorsun 
    bits3 >>= 1;
    std::cout<<bits3<<"\n";
    bits3<<=2;
    std::cout<<bits3<<"\n";

    std::bitset<4> bits4 {0b1011};
    std::bitset<4> bits5 {0b1010};

    bits4|=bits5;
    std::cout<<"---bits4---\n"<<bits4<<"\n";
    // bits4=1011
    bits4&=bits5;
    std::cout<<bits4<<"\n";
    // bits4=1010
    bits4^=bits5;
    std::cout<<bits4<<"\n";

    // atama ve diğer bitwise operatörleri binary ama bitwise not unary bu yüzden atama operatörü yok ama şöyle yapabilirisn
    bits4= ~bits4;
    std::cout<<bits4<<"\n";
    
    


}
/*
BİTE SAKLAYBİLECEĞİNDEN DAHA FAZLA DEĞER VERİRSEN NE OLUR
Yine 0b önekini yazmadığın için derleyici 1111 değerini onluk (decimal) "Bin Yüz On Bir" sayısı olarak okudu.

Adım Adım Ne Oldu?
Onluk Sayı Algılandı: Yazdığın 1111 sayısı ikilik tabanda 0b10001010111 değerine eşittir.

4 Bite Kırpıldı: <4> bitlik alan açtığın için bitset bu sayının sadece en sağdaki 4 bitini aldı:

Son 4 bit: 0111 (Başlangıç değerin aslında 1111 değil 0111 oldu).

Sağa 1 Kaydırıldı (>>= 1):

Elindeki 0111 değerini 1 basamak sağa kaydırdığında en sağdaki 1 dışarı düştü, soluna 0 eklendi ve sonuç 0011 oldu.
*/
/*
* **Olay:** 8-bitlik (`uint8_t`) bir değişkene bit işlemi (`~`, `<<`, `&`, `|`) yaptığın an C++ onu otomatik olarak **32-bit `int**` seviyesine 
yükseltir (*Integral Promotion*).
* **Sorun:**
* `~` yaptığında sol tarafa eklenen 24 adet sıfır da `1`'e dönüşür.
* Sonuç artık 8-bit değil **32-bit** olduğu için, bunu doğrudan `{}` ile 8-bitlik bir değişkene atayamazsın (derleyici daralma/veri kaybı hatası 
verir).


* **Çözüm:** Baştaki fazlalık 24 biti çöpe atıp yalnızca hedeflediğin 8 biti almak için `static_cast<std::uint8_t>(...)` kullanılır.

Bit işlemleri yaparken beklenmedik tür dönüşümlerinden ve hatalardan kaçınmak için ya doğrudan **`unsigned int` / `uint32_t**` ya da baştan 
beri konuştuğumuz **`std::bitset`** kullanmak en temiz yoldur.
*/