#include <iostream>

int main(){
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    int x0 { 5 };
    int& ref2 { x0 };         // okay: non-const lvalue reference bound to a modifiable lvalue

    const int y { 5 };
    // int& invalidRef { y };  // invalid: non-const lvalue reference can't bind to a non-modifiable lvalue
    // int& invalidRef2 { 0 }; // invalid: non-const lvalue reference can't bind to an rvalue
    // çünkü noncost referance sonradan değiştirilebşlir demektir ama değiştiremezsin

    double d { 6.0 };
    // int& invalidRef { d };     // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization
    // double& invalidRef2 { x }; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)
    // çünkü intten double a çeviriken geçiçi nesne oluştruyor refrans da ona işaraet edecek ama onu nasıl dğeiştiresin bu yüzden
    // type checkinge uysa bile const olmalı refaranslar yoksa aradaki geçici objecti değiştirmeye çalışır

    int x1 { 5 };
    int y1 { 6 };

    int& ref3 { x1 }; // ref is now an alias for x

    ref3 = y1; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x1 << '\n'; // user is expecting this to print 5


    int x6 { 5 };          // x is a modifiable lvalue
    const int& ref6 { x6 }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref6 << '\n'; // okay: we can access the object through our const reference
    // ref6 = 7;                  // error: we can not modify an object through a const reference

    x6 = 6;

    short beyza {7};
    const int& irem {beyza};
    // cont olmak zrunda çünkü içinde temp object oluşturuyor onu dönüştürmez yen değer glince
    beyza=8;
    
    std::cout<< beyza<<irem<<"\n";
    irem temp object yüüznden 7 kaldı unutma temp object meselsini
    return 0;
}
// When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists. 
// Such a reference is called a dangling reference. Accessing a dangling reference leads to undefined behavior.


// bir referansın bir yer kaplamasına gerek yok Mümkünse derleyici, bir referansın geçtiği tüm yerleri o referansın işaret ettiği 
// öğeyle değiştirerek referansları ortadan kaldıracak şekilde eniyileme yapar.
// Derleyici Node örneğinin nerede ve hangi nesneyle bağlanacağını çalışma zamanına kadar bilemeyebilir; bu yüzden nesnenin içine 
// referansın adresini fiziksel olarak yazar.

/*
Because references aren’t objects, they can’t be used anywhere an object is required (e.g. you can’t have a reference to a reference, 
since an lvalue reference must reference an identifiable object). In cases where you need a reference that is an object or a reference 
that can be reseated, std::reference_wrapper (which we cover in lesson 23.3 -- Aggregation) provides a solution
*/

/*
Temporary objects are normally destroyed at the end of the expression in which they are created.

Given the statement const int& ref { 5 };, consider what would happen instead if the temporary object created to hold rvalue 5 was destroyed at the end of the expression that initializes ref. Reference ref would be left dangling (referencing an object that had been destroyed), and we’d get undefined behavior when we tried to access ref.

To avoid dangling references in such cases, C++ has a special rule: When a const lvalue reference is directly bound to a temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference.

#include <iostream>

int main()
{
    const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref << '\n'; // Therefore, we can safely use it here

    return 0;
} // Both ref and the temporary object die here


burda  zaten const olmadan int& ref {5} diye kullanamzsın çüünkü 5 değerini nasıl depiştiresin
*/

/*
Senaryo,Yaşam Süresi Uzar mı?,Sonuç
const T& r = T();,Evet,Geçici nesne doğrudan referansa bağlandı.
const auto& m = T().member;,Evet,Üyeye bağlanmak tüm T nesnesini yaşatır.
const T& r = funcReturningRef();,Hayır,Fonksiyon içinde ölen nesne geri getirilemez (Dangling).
T r = funcReturningValue();,Kapsam dışı,"Kopyalama/Taşıma (Copy/Move) gerçekleşir, referans değildir."
*/
/*
#include <iostream>

int g_x = 5; // Global, normal bir değişken (const DEĞİL)

int main() {
    // 1. constexpr referans tanımlıyoruz:
    // Derleyici derleme anında bilir: "ref1 daima g_x'in bellekteki adresini gösterecek."
    constexpr int& ref1 = g_x;

    // 2. Şimdi bu referans üzerinden değeri değiştirmeyi deneyelim:
    ref1 = 10; 

    // 3. Ekrana yazdıralım:
    std::cout << g_x; // Ekrana 10 yazar! Kod sorunsuz derlenir ve çalışır.
}
*/