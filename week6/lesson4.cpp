#include <iostream>
void not_okey(int& a){
    std::cout<<"not_okey\n";
}
void its_okey(const int& a){
    std::cout<<"okey\n";
}
// Favor passing by const reference over passing by non-const reference unless you have a specific reason 
// to do otherwise (e.g. the function needs to change the value of an argument).
void print_double(const double& a){
    
    std::cout<<a<<"\n";
}

int main(){
    // normalde referanslar modifiable değerlere balanmak ister çünkü referans üzerinden değiştrebilirisn bu yüzden 
    // x=20 dersen x i değiştirebilirisn ama 20 yi değiştriemezsin x e bağlanır 20 ye bağlanmaz
    // ama eğer refransıd a const yaparsan bu sefer bağlanırsın
    const int& ref1 {7};
    // bu saayede eğer fonksiyon parametrelerini const yaparsan içine her şeyi alır 
    its_okey(3);
    // not_okey(3);

    // şimdi ne demiştik eğer type checkinge uyuyorsa farklı tipten bir refransı const oalrak alabilir sadece n
    // yanı nasıl
    print_double(3);
    // şimdi int i double kendi çevirir ama yine temp object oluşturmak zorunda kalır refransın avantajı gider
    // bu yüzden typlara dikkat et ki boşu boşuna yer kaplamayalım

}
/*
For most C++ beginners, the choice of whether to use pass by value or pass by reference isn’t very obvious. Fortunately, there’s a 
straightforward rule of thumb that will serve you well in the majority cases.

Fundamental types and enumerated types are cheap to copy, so they are typically passed by value.
Class types can be expensive to copy (sometimes significantly so), so they are typically passed by const reference.
Best practice

As a rule of thumb, pass fundamental types by value and class types by const reference.

If you aren’t sure what to do, pass by const reference, as you’re less likely to encounter unexpected behavior.
Tip

Here’s a partial list of other interesting cases:

The following are often passed by value (because it is more efficient):

Enumerated types (unscoped and scoped enumerations).
Views and spans (e.g. std::string_view, std::span).
Types that mimic references or (non-owning) pointers (e.g. iterators, std::reference_wrapper).
Cheap-to-copy class types that have value semantics (e.g. std::pair with elements of fundamental types, std::optional, std::expected).
Pass by reference should be used for the following:

Arguments that need to be modified by the function.
Types that aren’t copyable (such as std::ostream).
Types where copying has ownership implications that we want to avoid (e.g. std::unique_ptr, std::shared_ptr).
Types that have virtual functions or are likely to be inherited from (due to object slicing concerns, covered in lesson 25.9 -- Object slicing)
*/
/*
**C++ Parametre Aktarımı (Değer ve Referans Karşılaştırması)**

Fonksiyonlara parametre aktarırken veri tipinin boyutu ve kullanım amacı kritik rol oynar. `int`, `double`, `bool` gibi 8 bayttan küçük 
ilkel tiplerde **Pass by Value** tercih edilmelidir; çünkü bu küçük değerler doğrudan CPU register'larına sığar, tek adımda okunur ve kopyalar 
bağımsız olduğundan derleyici *aliasing* (aynı bellek alanına birden fazla isimle erişilme) riski görmeyerek kodu agresif şekilde optimize eder. 
Bu tipleri gereksiz yere referansla geçmek, arka planda bir adres oluşturup her seferinde RAM'e ekstra bir erişim (indirection) zorunluluğu 
doğurarak performansı düşürür. Buna karşın `std::string`, `std::vector` veya büyük nesnelerde derin kopyalama maliyeti çok yüksek olduğu için 
**`const Type&` (Pass by const Reference)** kullanılmalıdır. `const &` yapısı hem büyük veriyi kopyalamadan orijinal adresi üzerinden 
doğrudan okumayı sağlar hem de sıradan referansların aksine kalıcı değişkenlerin (lvalue) yanında geçici değerlere ve ifadelere (rvalue) de 
sorunsuzca bağlanarak güvenli, evrensel bir erişim sunar.
*/
/*
Best practice

Prefer passing strings using std::string_view (by value) instead of const std::string&, unless your function calls other functions 
that require C-style strings or std::string parameters.
*/
/*
Argument Type	std::string_view parameter	const std::string& parameter
std::string	Inexpensive conversion	Inexpensive reference binding
std::string_view	Inexpensive copy	Expensive explicit conversion to std::string
C-style string / literal	Inexpensive conversion	Expensive conversion
With a std::string_view value parameter:

If we pass in a std::string argument, the compiler will convert the std::string to a std::string_view, which is inexpensive, so this is fine.
If we pass in a std::string_view argument, the compiler will copy the argument into the parameter, which is inexpensive, so this is fine.
If we pass in a C-style string or string literal, the compiler will convert these to a std::string_view, which is inexpensive, so this is fine.
As you can see, std::string_view handles all three cases inexpensively.

With a const std::string& reference parameter:

If we pass in a std::string argument, the parameter will reference bind to the argument, which is inexpensive, so this is fine.
If we pass in a std::string_view argument, the compiler will refuse to do an implicit conversion, and produce a compilation error. We can use static_cast to do an explicit conversion (to std::string), but this conversion is expensive (since std::string will make a copy of the string being viewed). Once the conversion is done, the parameter will reference bind to the result, which is inexpensive. But we’ve made an expensive copy to do the conversion, so this isn’t great.
If we pass in a C-style string or string literal, the compiler will implicitly convert this to a std::string, which is expensive. So this isn’t great either.
Thus, a const std::string& parameter only handles std::string arguments inexpensively.
*/
/*
#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view sv)
{
    std::cout << sv << '\n';
}

void printS(const std::string& s)
{
    std::cout << s << '\n';
}

int main()
{
    std::string s{ "Hello, world" };
    std::string_view sv { s };

    // Pass to `std::string_view` parameter
    printSV(s);              // ok: inexpensive conversion from std::string to std::string_view
    printSV(sv);             // ok: inexpensive copy of std::string_view
    printSV("Hello, world"); // ok: inexpensive conversion of C-style string literal to std::string_view

    // pass to `const std::string&` parameter
    printS(s);              // ok: inexpensive bind to std::string argument
    printS(sv);             // compile error: cannot implicit convert std::string_view to std::string
    printS(static_cast<std::string>(sv)); // bad: expensive creation of std::string temporary
    printS("Hello, world"); // bad: expensive creation of std::string temporary

    return 0;
}
    Derleyici mecbur kalır: Arka planda geçici (temporary) bir std::string nesnesi oluşturur, 
    RAM'in heap bölgesinden yer ayırır, metni oraya kopyalar, referansı ona bağlar ve fonksiyon bitince o nesneyi yok eder.
*/
/*
2. Metni Parçalama (Substring) FarkıBir metnin sadece bir kısmını (örneğin ilk 5 harfini) bir fonksiyona göndermek istediğini düşün:const 
std::string& ile:s.substr(0, 5) dediğin an, std::string sana yepyeni bir std::string nesnesi kopyalayıp üretir. O parçayı referansla geçsen 
bile, o parçanın oluşması için yeni bellek ayrılıp harfler kopyalanmıştır ($O(N)$ maliyet).std::string_view ile:sv.substr(0, 5) dediğinde tek 
bir bayt bile kopyalanmaz. Başlangıç adresini 0'da tutar, uzunluğu 5 yapar ($O(1)$ maliyet). 1 GB'lık devasa bir metnin içinden 10 karakteri 
sıfır maliyetle anında cımbızlayıp fonksiyona gönderebilirsin.3. CPU Seviyesindeki Hız (Pointer Takibi)Bir önceki soruda konuştuğumuz dolaylı 
erişim (indirection) kuralı burada da geçerlidir:const std::string&: Bir referanstır. CPU fonksiyona girdiğinde önce referansın adresine bakar, 
sonra o adresteki std::string nesnesine gider, sonra da std::string'in içindeki asıl metin işaretçisine gider. Yani RAM'de arka arkaya 2-3
zıplama yapar.std::string_view: Kendisi zaten sadece bir pointer ve boyuttur (toplam 16 bayt). 
Register'lara sığar. Fonksiyona doğrudan değer olarak (by-value) kopyalanır. Fazladan adres çözme adımıyla uğraşmaz.
*/