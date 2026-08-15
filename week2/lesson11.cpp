#include <iostream>
#include <typeinfo>

int weird(const int x){
    // x=8;
    // evet bu yaptığın hata verir içinde const yapabilirsin
    return x;
    /*
    int gibi basit tiplerde const int x yazmak yanlış/hata değildir, ama sadece görsel kalabalıktır.
    Büyük nesnelerde const std::string s yazmak C++'ın en büyük performans optimizasyonunu (Move) kilitler.
    Bu yüzden C++ standartlarında "Kafa karışmasın, kural basit olsun: Değerle aktarımlarda (pass by value) parametreye asla const yazmayın" 
    prensibi kabul edilmiştir.
    istersen const int originalX=x diye bsabitle sonradan
    */
}

int main(){
    // constant variable oluşturmak için
    const double gravity {9.8};
    double const gravity2 {9.8}; // iki türlü de olur ama ilk kullanım daha yaygın
    // gravity {7}; değer değiştireceksen = kullan parantezlerle sadece initializtomn yapıyoruz
    // gravity=7; error: assigment of read-only variable hatası
    // The type of an object includes the const qualifier, so when we define const double gravity { 9.8 }; the type of gravity is const double.
    std::cout << std::boolalpha << std::is_const_v<decltype(gravity)><<"\n";

    // constant variable non constanst variablerla initialize edilebilirr
    int age{7};
    const int constAge{age};
    std::cout <<"age: " <<age << " constAge: "<< constAge<<"\n";
    age=8;
    std::cout <<"age: " <<age << " constAge: "<< constAge<<"\n";
    // c++ value semantics oldugu için age değişince constage değişmez
    // EARTH_GRAVİTY(c alışkanlığı) veya kEarthGravity(k prefixi ile daha cpp özgü) şeklinde kullanabilirsin

    int w =weird(5);
    std::cout<<w<<"\n";




}
/*
SORU:  int age{7};
    const int constAge{age};
    std::cout <<"age: " <<age << " constAge: "<< constAge<<"\n";
    age=8;
    std::cout <<"age: " <<age << " constAge: "<< constAge<<"\n";
şimdi javasal düşünsem int primavite tip oldugu direkt değer kopyalandı ama benim yadığım bir sınıf yani object olsaydı adres kopyalanacaktı 
o zaman ege değiştirseydim constage ne olurdu cpp de durum ne

CEVAP: C++'ta varsayılan olarak sınıflar (objects) dahil her şey değer bazlıdır (Value Semantics).
Yani int yerine bir sınıf/nesne kullansaydın da hiçbir şey değişmezdi. age'i değiştirdiğinde constAge bundan etkilenmez, 
kendi bağımsız kopyasını korumaya devam ederdi.
1. C++ vs JavaScript Mantığı
JavaScript: Nesneler (Objects, Arrays) varsayılan olarak Referans Semantiğine (Reference Semantics) sahiptir. 
Değişken nesnenin kendisini değil, heap'teki bellek adresini tutar.
C++: Varsayılan olarak Değer Semantiğine (Value Semantics) sahiptir. MyClass constAge{age}; yazdığında C++ arka planda Kopyalama Yapıcısını 
(Copy Constructor) tetikler. RAM'de constAge için tamamen ayrı yeni bir alan tahsis eder ve age nesnesinin verilerini oraya birebir kopyalar.
ğer C++'ta JavaScript'teki gibi constAge'in age nesnesinin adresine bağlanmasını ve age değiştiğinde constAge üzerinden okunan değerin de 
güncellenmesini istiyorsan bunu Referans (&) veya İşaretçi (Pointer *) kullanarak açıkça belirtmelisin:

Referans (&) Kullanımı:

C++
int age{7};
const int& constAge{age}; // constAge artık age'in adresine bağlı bir "takma ad"dır.

age = 8;
std::cout << constAge; // Çıktı: 8 olur! (Adresi takip ettiği için değişti)
*/
/*
// YANLIŞ: Move optimizasyonunu kilitler, kopyalamaya zorlar.
const std::string getName() {
    return "Ahmet";
}

// DOĞRU: C++ bu geçici nesneyi sıfır maliyetle taşıyabilir (Move).
std::string getName() {
    return "Ahmet";
}
*/
// Best practice
// Make variables constant whenever possible. Exception cases include by-value function parameters and by-value return types, 
// which should generally not be made constant.
/*
C++23 itibarıyla dilde sadece 2 adet tip niteleyicisi vardır:
const: Değişkenin değerini sabitler, kod içinde değiştirilmesini engeller.
volatile: Derleyiciye "Bu değişkenin değeri benim yazdığım kodun dışında (donanım, işletim sistemi veya başka bir thread tarafından) her an 
değiştirilebilir" mesajı verir. Derleyicinin bu değişken üzerinde optimizasyon yapmasını (değeri register'a önbellekleyip RAM'den okumayı 
bırakmasını) engeller.
*/
/*
auto (Type Deduction) Kullanıldığında Sonek Neden Zorunlu Olur?
auto kullandığında değişkenin türünü sağ taraftaki değer belirler. Sonek koymazsan C++ varsayılan türleri seçer, 
sonek koyarsan tam istediğin türü oluşturur:

C++
auto a = 5;    // Sonek yok -> 'a' değişkeninin türü: int
auto b = 5u;   // 'u' soneki VAR -> 'b' değişkeninin türü: unsigned int
auto c = 5L;   // 'L' soneki VAR -> 'c' değişkeninin türü: long

auto s1 = "Ahmet";  // Sonek yok -> 's1' türü: const char* (C-style string)
auto s2 = "Ahmet"s; // 's' soneki VAR -> 's2' türü: std::string
Özetle; türü kendin yazıyorsan sonek zorunlu değildir. Ancak türü derleyicinin bulmasını istiyorsan (auto), derleyiciye doğru türü seçtirmek 
için bu sonekleri kullanırsın.
*/