#include <iostream>
#include <string>
int main(){
    std::cout<<"Hi \n";
    // bu bir c style string litearal
    std::string name {"beyza"};
    // bu şimdi bir std::string
    // empty string hiçbir şey yazdırmaz
    std::string empty {};
    std::cout<<name<<empty<<name<<"\n";
    // std::string dynamic memory allaocation yaptığı için daha sonra değiştrip farklı uzunlukta bir değişken atayabilirisn 
    // c style da bunu yapamazsın bir kere tanımladıktan sonra değiştiremezsin 
    name="beyza irem kaya";
    std::cout<<"Beyza Irem yaz: ";
    std::string name2 {};
    std::cin >>name2;
    std::cout<<"meslegini gir ama giremedim demi:) : ";
    std::string meslek {};
    std::cin >> meslek;
    std::cout<<"your name is "<<name2<<"your job is "<<meslek<<"\n";
    // bunun sebebi cin in whitespace kadar görmesi bu sorunu getline ile çözeceğiz

    std::cout<<"Beyza Irem yaz: ";
    std::string name3 {};
    std::getline(std::cin >>std::ws ,name3);
    std::cout<<"meslegini gir: ";
    std::string job {};
    std::getline(std::cin>> std::ws ,job) ;
    std::cout<<"your name is "<<name3<<" your job is "<<job<<"\n";
    // If using std::getline() to read strings, use std::cin >> std::ws input manipulator to ignore leading whitespace. 
    // This needs to be done for each std::getline() call, as std::ws is not preserved across calls.
    // eğer std cin den sonra std get line kullanırsak bufferda \n kalacağı için direkt içbir şey alamdan durduru progrmaı
    /*
    std::string name1, name2;
    std::cin >> name1;             // "beyza" okundu, '\n' arabellekte KALDI.
    std::getline(std::cin, name2); // 'getline' baştaki '\n' karakterini ATLAMAZ!
    Arabellekteki '\n'yi görür görmez "boş satır girildi" sanıp hemen biter.
    bu yüzden getline kullanacağın her zmaan std::ws de kullan ws ; whitespaces, tab ve new line ı görmezden gelir
    Baştaki boşlukları atlar (Ignores leading whitespace): İster boşluk (space), ister sekme (tab \t), ister yeni satır (\n) olsun; 
    girdi akışının en başında yer alan tüm boşlukları görmezden gelir ve ilk geçerli karaktere kadar ilerler.
    Sonraki boşlukta durur (Stops at non-leading whitespace): Veriyi okumaya başladıktan sonra karşılaştığı ilk boşluk, 
    sekme veya yeni satır karakterinde okumayı durdurur. O boşluk karakterini girdi akışında (buffer) bırakır.
    */

    // stringlerin boyu düz length() ile bulunur
    std::string name4 {"beyza"};
    std::cout<<name4.length();
    // .length unsigned int döndürür genelde size_t tipinde int olarak kullanmak istiyorsan type castingi unutma
    int len {static_cast<int>(name.length())};
    // .length() direkt kaç karakter varsa onu döndürür null terminatoru saymaz unutma
    // name.lengthg=std::size(name) aynı zamnanda ama bu unsigneddöndürğü için -5 falan yapsa underflowa yol açar devasa sayılara gider çünlü
    // bundan korunmak için c20 ile gelen std::ssize(name) kullanabilirsin signed size 
    // ama yine int döndürme çok büyük olabileceği için yine ztatic caas kullanman gerek yani
    int len2 {static_cast<int>(std::ssize(name))}

    using namespace std::string_literals; // s suffixi için gerekli
    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
    // std::string {} yaparken c style literal hemen dönüştürülür ama auto kullnacaksan s lazım
    /*
    The “s” suffix lives in the namespace std::literals::string_literals.
    The most concise way to access the literal suffixes is via using-directive using namespace std::literals. 
    However, this imports all of the standard library literals into the scope of the using-directive, which brings in a bunch of stuff 
    you probably aren’t going to use
    We recommend using namespace std::string_literals, which imports only the literals for std::string.
    We discuss using-directives in lesson 7.13 -- Using declarations and using directives. 
    This is one of the exception cases where using an entire namespace is generally okay, because the suffixes defined within are 
    unlikely to collide with any of your code. Avoid such using-directives outside of functions in header files.
    */

    // constexpr std::string desteklenmiyor çoğunluka
    // constexpr std::string_view kullanabilirsin



}
/*
Bir std::string nesnesini fonksiyona değer ile (by value) gönderdiğinde veya baska bir değişkene atadığında derleyici şu iki yavaş işlemi 
yapmak zorunda kalır:

1. İşletim Sisteminden Yer İstemek (Heap Allocation): std::string metinleri RAM'in "Heap" bölgesinde tutar. 
Her yeni kopyada işletim sistemine gidilip "Bana yeni bir bellek alanı ayır" denir. İşletim sistemiyle iletişim kurmak işlemci için yavaş bir 
eylemdir.

2. Karakterleri Teker Teker Kopyalamak: Orijinal metindeki tüm harfler, yeni ayrılan bellek alanına tek tek kopyalanır. 
Metin uzadıkça maliyet artar.
void mesajYazdir(std::string s) { // ❌ Değer ile geçme (Pass by value)
    std::cout << s;
}

int main() {
    std::string metin = "Bu oldukça uzun bir metin...";
    mesajYazdir(metin); // 💥 BURADA KOPYALANIR!
}
Eski / Klasik Yöntem (const std::string&): Fonksiyona verinin kendisini değil, adresini (referansını) gönderirsin. Kopyalama yapılmaz.

Modern C++ Yöntemi (std::string_view): Bellekte yeni yer açmaz; metnin sadece başladığı bellek adresini ve karakter sayısını tutar. 
Tıpkı bir int gibi çok hafiftir ve sıfır kopyalama maliyetiyle çalışır.
*/

// ama std::string return ederken copy değil move semantıc yapar yani adresni taşır çünkü return ettikten sonra o adresi yıkacak zatyen bu yüzden
// raht rahat return edebilirsin