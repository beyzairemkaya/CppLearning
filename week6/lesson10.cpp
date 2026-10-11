#include <iostream>
#include <string>

const std::string& funcB (){
    static const std::string name {"beyza"};
    // return name&; böyle bir synax yok kendismi refransımı döndürüleceğini dönüş tipide belirttik
    return name;
}
const int& funcD(){
    static int s_0 {0};
    s_0++;
    return s_0;
}
int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}
/*
const int& funcInt(){
    return 5;
    // Ana fikir: Lifetime extension, temporary doğrudan referansa bağlanırsa olur; fonksiyon üzerinden referans geçirerek olmaz.
    // burda dangling referan olacak o yzüden 
    // mesela const std::string& name = std::string{"beyza"}; // ✅ lifetime uzardı
    lifetime etension sadece burda çalışıyor
    #include <iostream>

const int& returnByConstReference(const int& ref)
{
    return ref;
}

int main()
{
    // case 1: direct binding
    const int& ref1 { 5 }; // extends lifetime
    std::cout << ref1 << '\n'; // okay

    // case 2: indirect binding
    const int& ref2 { returnByConstReference(5) }; // binds to dangling reference
    std::cout << ref2 << '\n'; // undefined behavior

    return 0;
}
}
    */



int main(){
    // nasıl ki refransla verirken class nesnelerini copy etek paha ise return ederkende öyle o yüzden 
    // o yüzden return by referance tanımla refransı döndürün ama dangling olmamasına dikkat et static yapmalısın
    const std::string name=funcB();
    /*
    std::string name = funcB();         // ✅ Olur → kopya oluşturur kensisini değil kopyasını değiştirmiş olursun
    const std::string& name = funcB();  // ✅ Olur → const referans
    std::string& name = funcB();        // ❌ Olmaz → const'u kaldırmaya çalışır
    */
    const std::string& name2 = funcB();
    std::cout<<name<<"\n";
    std::cout<<name2<<"\n";
    // std::cout<< funcInt()<<"\n"; hata verir
    
    const int& id1 { funcD() }; // id1 is a reference
    std::cout << id1 << '\n';
    const int& id2 { funcD() }; // id2 is a reference

    std::cout << id1 << id2 << '\n';
    // non cost variabler kullanma çünkkü değiştirmeye çalışırsan referanstan deişeceği için ikiside değişir

    // bunları refrasn olarak değilde copy olarak kullansan sorun çözülür int oldugu için maliyetei de küçük
    // ama class kullansan dikkatlı ol tabi
    const int id3 { funcD() }; // id1 is a reference
    std::cout << id1 << '\n';
    const int id4 { funcD() }; // id2 is a reference

    std::cout << id3 << id4 << '\n';
    int a{ 5 };
    int b{ 6 };

    max(a, b) = 7; // refrsns döndüreceği  için  b yi direkt değitirir
    std::cout << a << b << '\n';

    
}
/*
The major advantage of return by address over return by reference is that we can have the function return nullptr if there is no valid 
object to return. For example, let’s say we have a list of students that we want to search. If we find the student we are looking for in the 
list, we can return a pointer to the object representing the matching student. If we don’t find any students matching, we can return nullptr 
to indicate a matching student object was not found.

The major disadvantage of return by address is that the caller has to remember to do a nullptr check before dereferencing the return value, 
otherwise a null pointer dereference may occur and undefined behavior will result. Because of this danger, return by reference should 
be preferred over return by address unless the ability to return “no object” is needed.

Best practice

Prefer return by reference over return by address unless the ability to return “no object” (using nullptr) is important.

Related content

If you need the ability to return “no object” or a value (rather than an object) 12.15 -- std::optional describes a good alternative.
*/

/*
There are quite a few cases where returning objects by reference makes sense, and we’ll encounter many of those in future lessons. 
However, there is one useful example that we can show now.

If a parameter is passed into a function by reference, it’s safe to return that parameter by reference. This makes sense: in order 
to pass an argument to a function, the argument must exist in the scope of the caller. When the called function returns, that object 
must still exist in the scope of the caller.

Here is a simple example of such a function:

#include <iostream>
#include <string>

// Takes two std::string objects, returns the one that comes first alphabetically
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
	std::string hello { "Hello" };
	std::string world { "World" };

	std::cout << firstAlphabetical(hello, world) << '\n';

	return 0;
}
*/
/*
Using pass by address instead of pass by reference can in some case help make out-parameters more obvious by requiring the caller to pass in the address of objects as arguments.

Consider the following example:

void foo1(int x);  // pass by value
void foo2(int& x); // pass by reference
void foo3(int* x); // pass by address

int main()
{
    int i{};

    foo1(i);  // can't modify i
    foo2(i);  // can modify i (not obvious)
    foo3(&i); // can modify i

    int *ptr { &i };
    foo3(ptr); // can modify i (not obvious)

    return 0;
}
*/
// şimdi void foo3(int* x);  foo3(&i); paramtre diyor ki verilen x bir adres olacak ordaki değeri al içine paramtre verdiğimizde neenin 
// adrresini veiryor işte

// ===== Pass by non-const reference (Foo&) ne zaman? =====
//
// Varsayılan: kopyadan kaçınmak için referans kullanıyorsan -> const Foo&
//
// Foo& kullanmanın mantıklı olduğu 2 durum:
//
// 1) In-out parametre: fonksiyon gelen nesneyi değiştirip geri veriyorsa.
//    void modifyFoo(Foo& inout);
//    - Çağrıda (modifyFoo(foo)) değişiklik belli olmaz -> fonksiyona iyi isim ver.
//    - Alternatif: Foo f(const Foo& in) + foo = f(foo);
//      -> daha okunaklı ama ekstra kopya maliyeti var.
//
// 2) Döndürülecek nesneyi kopyalamak çok pahalıysa (özellikle sık çağrılan,
//    performans-kritik kodda), return yerine çağıranın nesnesini doldur.
//    void generateExpensiveFoo(Foo& out);
//    Örnek: pahalı elemanlı büyük std::array / C-dizisi doldurmak.
//
// Not: Bunlar istisna. Kopyası bu kadar pahalı nesne nadirdir;
// normalde return ile döndür (RVO + move semantiği sayesinde genelde ucuz).