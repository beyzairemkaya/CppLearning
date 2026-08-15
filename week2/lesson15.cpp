#include <iostream>
#include <array>
int foo(){
    return 5;
}
constexpr int kareAl(int x) { // 'constexpr int x' yazmak C++ sözdiziminde HATADIR!
    return x * x;
}
constexpr int foo2(){
    return 3;
}
int foo3(const int x){
    // x runtime sabititidi istersen constexpre yapmaya çalış yapamazsın çünkü fonksiyon paramaetleri
    // constant expression  olmaaz runtime constatlarıdır 
    // Çünkü bir fonksiyon tek bir kez derlenir, ancak program çalışırken farklı farklı değerlerle defalarca çağrılabilir.
    // fonksiyon çağrılması runtime da olacağı için içine constexpr giremezsin !!!
    /*
    Eğer bir fonksiyona derleme anında kesinleşmiş sabit bir değer geçmek istiyorsan, parametre yerine Non-type Template Parameter (NTTP) 
    // kullanman gerekir:

C++
template <int N> // N derleme anında kesinleşir (NTTP)
void test() {
    std::array<int, N> arr; // ✅ Sorunsuz çalışır
}

int main() {
    test<5>(); // Değer şablon parametresi olarak verilir
}
    */
    return 5;
}
int max(int x, int y) // this is a non-constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

constexpr int cmax(int x, int y) // this is a constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}
int main(){
    // constexpr constant expression demektir
    // const sadece değeri sabitlerken constexpr hem değeri sabitler hemde bu değişkenin değeri compile time da bilinmelidir der
    // constexpr int x {foo()};
    // foo runtimeda çağıralacağı için compile time d bu değer bilinemez hata verir bu fonksiypn 
    // peki neden ihtiyaç duyuyoruz array boyutları bazı template parametreleri ve switch-case ifadeleri compile timeda kesinlikle bilinmelidir
    // amac++ bunun compile time da mı runtime damı tanımlanacağını garanti edemeyeceği için constexpr ihtiyacımız var
    constexpr int x {foo2()};
    // gördüğün gibi bir sıkıntı çıkarmadı 
    // mesela bir array boyutunu böyle bulabilirisn
    // std::array<int ,foo()> newArr; hata verir
    std::array<int ,foo2()> newArr; // sorunsuz derlenir
    // A few common cases where a compile-time evaluatable expression is required:
    // The initializer of a constexpr variable (5.6 -- Constexpr variables).
    // A non-type template argument (11.9 -- Non-type template parameters).
    // The defined length of a std::array (17.1 -- Introduction to std::array) or a C-style array (17.7 -- Introduction to C-style arrays).

    // Özetle: Bir değerin veya hesaplamanın girdileri kod yazılırken belliyse default tercihin constexpr olsun. 
    // Ancak kullanıcıdan, dosyadan veya dış bir sistemden gelen veriler için mecburen çalışma anı (runtime) kod yazacaksın.

    const int nm {7};
    const char ch {'a'};
    // const int ve const char derleme anında sab,t olacağı eksindir ama diğer değişkenler için bu garanti edilmez constexp kullanman gerekir

    int x1 = 5;
    constexpr int x2=6;
    const int a0 = x1;     // ✅ Derlenir (a çalışma anında 5 olur, bir daha değişmez).
    // constexpr int b = x1; // ❌ DERLEME HATASI! (x değişken olduğu için derleyici "b'yi derleme anında sabitleyemem" der).
    // x1 is not const hatası
    constexpr int b = x2;
    8 - 5.6;                     // constant expression (even though operands have different types)
    sizeof(int) + 1;             // constant expression (sizeof can be determined at compile-time)

    char a1 { 'q' };
    constexpr char a2 { 'q' };
    // constexpr int d { a1  * 2 }; 
    constexpr int d { a2  * 2 }; 
    // a is not a constant expression, so a * 2 is a non-constant expression.
    // d is a non-constant expression since the initializer is not a constant expression.
    int a { 5 };       // not const at all
    const int bi { a }; // clearly not a constant expression (since initializer is non-const)
    const int c { 5 }; // clearly a constant expression (since initializer is a constant expression)


    // KONUNUN ÖZETİ
    // bir değişkeni constexpr olarak tanımlamak isitorsan verdiğin değer constexp olmalı örneğin 5 gibi bir literal veya constexpr
    // döndüren bir fonskiyon
    // const int ve const char constexpr gibi davrnır ama diğer tüm türler için const değil constexpre yazman gerekir

    // const means that the value of an object cannot be changed after initialization. The value of the initializer may be known at 
    // compile-time or runtime. The const object can be evaluated at runtime.
    // constexpr means that the object can be used in a constant expression. The value of the initializer must be known at compile-time. 
    // The constexpr object can be evaluated at runtime or compile-time.
    // Unlike const, constexpr is not part of an object’s type. 
    // Therefore a variable defined as constexpr int actually has type const int (due to the implicit const that constexpr provides for objects).
    // std::string ve std::vector gibi tiplerin derleme zamanı sabiti (constexpr değişkeni) olarak doğrudan saklanamamasının temel nedeni 
    // dinamik bellek yönetimi (heap allocation) kullanmalarıdır.
    // Heap (Yığın) Çalışma Zamanına Aittir: std::vector ve std::string elemanlarını RAM'in "Heap" bölgesinde tutar. 
    // Heap ise program çalışırken işletim sistemi tarafından yönetilen bir bellek alanıdır. Derleyici, henüz çalışmayan bir program için 
    // işletim sisteminden Heap adresi alıp bunu .exe dosyasına sabitleyemez.

    const double db {1.2}; // runtime constant bu mesela

    // fonksiyon constextre olsa bile bu içine const expre paramtre verebileceğin anlamına gelmez 
    // Eğer girdileri ve çağrıldığı yer derleme anına uygunsa derleme anında çalış; 
    // değilse normal bir fonksiyon gibi runtime'da çalış" anlamına gelir
    // 1. Derleme anında çalışır:
    constexpr int a3 = kareAl(5); 

    // 2. Çalışma anında (runtime) çalışır:
    int n;
    std::cin >> n;
    int b4 = kareAl(n); // x parametresi runtime'da 'n' değerini alır!

    // constexpr fonksiyonlar constexpr değerler için çağrılmıyorsa normal fonksiyon gibi runtime da çağrılır unjtöa!!

    int m1 { max(5, 6) };            // ok
    const int m2 { max(5, 6) };      // ok
    // constexpr int m3 { max(5, 6) };  // compile error: max(5, 6) not a constant expression

    int m4 { cmax(5, 6) };           // ok: may evaluate at compile-time or runtime
    const int m5 { cmax(5, 6) };     // ok: may evaluate at compile-time or runtime
    constexpr int m6 { cmax(5, 6) }; // okay: must evaluate at compile-time





    


}

