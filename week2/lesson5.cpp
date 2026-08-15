#include <cstdint> // for fast and least types
#include <iostream>

int foo(){
    return 0;
}

int main(){
    // biliyorsun ki hangi veri tipinin en hızlı olup hangisinin en az yer kaplayacağı işletim sisteminden sistmeine değişebiklir 
    // bu sorunu çözmek için iki veri tipi tanımlanmıs fast and least
    
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
    // std:: int_least8_t en az 8 bitlik en az yer kaplayan veri tipini ayarlar
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    // std:: int_least16_t en az 16 bitlik en az yer kaplayan veri tipini ayarlar
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
    // std:: int_fast8_t en az 8 bitlik en hızlı veri tipini ayarlar
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
    // std:: int_fast8_t en az 16 bitlik en hızlı veri tipini ayarlar
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

    // ama bunları kullanarak yazdığın kodlar sistemden sisteme değişebileceği için kullanmamanı öneriyorum
    std::uint_fast16_t sometype { 0 };
    // uint unsigned int unutma
    sometype = sometype - 1; // intentionally overflow to invoke wraparound behavior

    std::cout << sometype << '\n';
    // mesela bizde 65535 verdi
    // 2^16-1
    // FARKLI SİSTEMLERDE FARKLI DAVRANABİLDİĞİ İÇİN UZAK DUR

    // decltype verilen type ın yerine geçer mesela
    int x{5};
    decltype(x) y {7}; // bu int y{7} demek decltype(x)=int oldu
    // tabii b u kullanım manasız nasıl kullandığımızı aşağıda göstereceğim
    
    // auto veri tipini bilmediğinde veya veri tipi çok uzun oldugunda uzuzn uzun yazmak yerine kullanılır
    // derleyici type ı çıkaraır ve atar .Aslında istersen int char her şeyin yerinede kullanabilrisn ama iyi bir alışkanlık değil
    auto z = foo();// foo nun ne döndürdüğünü bilmediğimizi varsayalım
    // decltype(z)
    /*
    auto foo() -> decltype(bar())
{
    return bar();
}
    templatelerde falan göreceği,z şu an anlamadım boşver*/

    // sizeof ne döndürür
    std::cout<< typeid(sizeof(int)).name()<<"\n";
    // y unsigned long long la eşleşmiş her neyse
    // sizeof kısaca her zaman std::size_t döndürür
    // bu tür unsigned olacakır ama ne oldugu işletim sisteminden işletim sistemine değişir bizde long long çıktı mesela
    int k{10};
    std::size_t boyut (sizeof(k));
    std::cout<< boyut<<" byte\n";
    // 4 byt da saklanmış

    char c ='b';
    std::size_t boyut2 (sizeof(c));
    std::cout<< boyut2<<" byte\n";
    // char 1 byte
    /*
    Neden Düz int Yerine std::size_t Kullanılır?
    Düz int türü hem negatif değerler alabilir hem de 64-bit sistemlerde bile genellikle 4 byte (32-bit) ile sınırlı kalır. 
    Çok büyük bellek alanlarıyla veya dizilerle çalışırken 32-bit'lik bir int bellek adresini temsil etmeye yetmeyebilir ve veri kaybına (taşmaya)
    sebep olur. std::size_t ise bilgisayarın adresleyebileceği en büyük nesne boyutunu bile güvenle tutabilecek genişliktedir.
    */
   // std:.size_t <cstdint> importu gerektiriyor ama sizeof() gerektirmiyor

   std::cout<< sizeof(19)<<"\n";
   std::cout<< sizeof(int)<<"\n";
   std::cout<< sizeof(std::size_t)<<"\n";
   // bu şekilde de kullanabilirisn boyut adında değişken oluşturma sebebim std::size_t nin bir veri tipi oldugunu göstermekti

   // teorrdik olarak bir nesne std::size_t ın boyutunu geçemez
   // The sizeof operator must be able to return the byte-size of an object as a value of type std::size_t. 
   // Therefore, the byte-size of an object can be no larger than the largest value std::size_t can hold.
   // mesela biizm bilgisayarda std::size_t 8 byte çıktı yani 64 2^64 bitlik sayı sayabiliriz max
   // 1 GB~=2^30 byte 2^64/3^30 2^34 GB lık alan var 
   /*
   Adım adım ve en sade haliyle Byte'tan GB'a nasıl geçtiğimizi 3 adımda çözelim:

**1. Adım: Max Sayıyı Bulmak**
Bilgisayarında `std::size_t` 8 byte (yani 64 bit) çıktı. 64 bitlik bir kutunun içine yazabileceğin en büyük sayı **$2^{64}$** tanedir.

**2. Adım: Birimi Koymak**
`sizeof` işlemi bize sonucu her zaman **Byte** cinsinden verir. Yani elimizdeki kapasite doğrudan **$2^{64}$ Byte**'tır.

**3. Adım: Byte'tan GB'a Geçiş (Matematik Kısmı)**
Bilgisayarda dönüştürmeler $2$'nin kuvvetleriyle yapılır:

* $1 \text{ KB} = 2^{10} \text{ Byte}$
* $1 \text{ MB} = 2^{20} \text{ Byte}$
* $1 \text{ GB} = 2^{30} \text{ Byte}$

Elimizdeki toplam Byte sayısını ($2^{64}$), $1 \text{ GB}$'ın içindeki Byte sayısına ($2^{30}$) böleriz:

$$\frac{2^{64} \text{ Byte}}{2^{30} \text{ Byte}} = 2^{64 - 30} = 2^{34} \text{ GB}$$

Üslü sayılarda bölme yapılırken üsler çıkarıldığı için ($64 - 30 = 34$) geriye **$2^{34} \text{ GB}$** kalır.

$2^{34}$ sayısını normal sayıya çevirdiğimizde de karşımıza **$17.179.869.184 \text{ GB}$** (yaklaşık 17,1 milyar GB) çıkar.*/

/*
std::size_t teorik maksimum sınırı belirler, ancak gerçek hayatta bir nesne bu sınıra bile ulaşamadan şu engellere takılır:
Derleyici Kısıtlamaları: Bazı derleyiciler, iki pointer arasındaki farkı hesaplayan işaretli (ptrdiff_t) türlerle çakışmaması için 
maksimum nesne boyutunu std::size_t tavanının yarısı ile sınırlar.
Fiziksel RAM: Bilgisayarınızda o boyutta ardışık (kesintisiz) boş bellek alanı bulunmayabilir.
*/
/*
C++'ta sizeof adında bir ölçüm aleti var. 
Nesnelerin boyutunu Byte cinsinden ölçer.
sizeof, bulduğu sonucu tutmak için std::size_t adında bir değişken (sayı kutusu) kullanır.
64-bit sistemde bu kutunun içine yazılabilecek en büyük sayı 2^64-1'dir.
Kutudaki sayının birimi Byte olduğu için; C++'ın boyutunu ölçebileceği en büyük nesne de 2^64-1 Byte (yaklaşık 2^64 Byte) olur.
*/
/*
Harika, temel oturduğuna göre 8 byte'tan başlayıp büyük resme giden tüm zinciri adım adım bağlayalım:

1. **`sizeof`'un Boyutu = 8 Byte (64 Bit)**
* Bilgisayarında `sizeof(std::size_t)` çalıştırdığında **8** sonucunu aldın.
* Bu demektir ki derleyici `std::size_t` adındaki sayaç değişkeni için RAM'de 8 byte (yani $8 \times 8 = 64$ bit) alan ayırır.


2. **64 Bit'in Hafızadaki Sayı Kapasitesi**
* Elinde yan yana 64 tane "0/1" anahtarı var.
* Bu anahtarlarla üretebileceğin toplam kombinasyon sayısı **$2^{64}$** tanedir.
* Saymaya 0'dan başladığın için bu 8 byte'lık kutunun içine yazabileceğin en büyük sayı **$2^{64}-1$** olur.


3. **Birimi Koyma (`sizeof` Ölçümü)**
* `sizeof` operatörü nesnelerin boyutunu **Byte** cinsinden söyler (bit, kilogram veya santim değil).
* Sayaç kutunun içine yazılabilecek maksimum sayı $2^{64}$ olduğuna göre, bu sayacın ölçebileceği en büyük nesne boyutu da **$2^{64}$ Byte** olur.


4. **Byte'tan Gigabyte'a Geçiş**
* $1 \text{ GB} = 2^{30} \text{ Byte}$'tır.
* Elimizdeki $2^{64}$ Byte'ı $2^{30}$'a bölersek:

$$\frac{2^{64}}{2^{30}} = 2^{34} \text{ GB}$$


* $2^{34}$ sayısı yaklaşık **17,1 milyar GB** (yani 16 Exabyte) yapar.



**Özetle Büyük Resim**

RAM'inde sadece **8 Byte** yer kaplayan küçücük bir `std::size_t` değişkeni (etiketi), **17,1 milyar GB** boyutundaki devasa bir dizinin veya 
nesnenin boyutunu hafızasında tutabilir. C++ dili bu sayede 64-bit sistemlerde teorik olarak bu boyuta kadar olan tüm nesnelerin derlenmesine 
ve ölçülmesine izin verir.*/
/*
Devasa Verinin Kendisi ($2^{34} \text{ GB}$): RAM'in (veya disk belleginin) geniş bir alanına yayılır ve gerçekten $2^{34} \text{ GB}$ yer kaplar
std::size_t Değişkeni (8 Byte): RAM'de sadece 8 byte yer kaplayan minicik bir kutudur. 
Bu kutunun içine sadece verinin büyüklüğünü gösteren 17179869184 sayısı yazılır.*/
//  sizeof un içine yazılabilecek en geniş boyutun ramda ne kadar yer kapladıgını bulduk
// o yüzden dedik sizeof byte döndürü sizeof max döndürüğü rakam x ise max umum x byte lık yer kaplar

// When 8-bit and 16-bit applications were the norm, this limit imposed a significant constraint on the size of objects. 
// In the 32-bit and 64-bit era, this is rarely an issue, and therefore not something you generally need to worry about.

    return 0;

}