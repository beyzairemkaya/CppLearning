#include <iostream>
auto add(int x, int y)
{
    return x + y;
}
// int döndüreceği kesin zaten
auto add2(auto x, auto y)
{
    return x + y;
    // temptale yerine kullanılabilir
    // direkt burda type deduction yapmıyorn zaten kendiside template haline getiriyor sonra template nin yaptıgı
    // type deductionu yapıyor
}
/*
auto someFcn(bool b)
{
    if (b)
        return 5; // return type int
    else
        return 6.7; // return type double
}
// böyle olmaz ama tek tip return etmeli
*/


int main(){
    const int a { 5 }; // a has type const int
    auto b { a };      // b has type int (const dropped)
    const auto b2 { a }; // b has type const int (const dropped but reapplied)
    auto s { "Hello, world" }; // s will be type const char*, not std::string
    using namespace std::literals; // easiest way to access the s and sv suffixes

    auto s1 { "goo"s };  // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    auto s2 { "moo"sv }; // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
    /*
    Use type deduction for your variables when the type of the object doesn’t matter.
    Favor an explicit type when you require a specific type that differs from the type of the initializer, or when your object is used 
    in a context where making the type obvious is useful.
    */
   std::cout<<add2(8,9)<<" "<<add2(8.8,1.3)<<"\n";



}
/*

auto foo();

int main()
{
    std::cout << foo() << '\n'; // the compiler has only seen a forward declaration at this point

    return 0;
}

auto foo()
{
    return 5;
}
    bu şekilde kullanamazsın ama başlangıçt return  type ı bilmediğ için hata verir forward declartaiton yapmayıp direkt fon ksiyonu 
    yukarda yazman gerekecek
*/
/*
#include <type_traits> // for std::common_type

std::common_type_t<int, double> compare(int, double);         // harder to read (where is the name of the function in this mess?)
auto compare(int, double) -> std::common_type_t<int, double>; // easier to read (we don't have to read the return type unless we care)
*/