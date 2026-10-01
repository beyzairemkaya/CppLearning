#include <iostream>
int main(){
    int x=6;
    std::cout<<&x<<"\n";
    // hexadecimal oalrak adresi yazdırır

    // the deference operatorde verilen adresteki değeri çeker

    std::cout<<*(&x)<<"\n";
    int* a, b; // DİKKAT: a bir pointer'dır, ama b NORMAL bir int'tir!
    int* c, *d; // yapman gerekir ama sen direkt çoklu tanımlama yapma

    int* ptr ; // garbega adres tutar o yüzden bir değerle initialze et
    int* ptr2{};     // a null pointer (we'll discuss these in the next lesson)
    int* ptr3{ &x }; // a pointer initialized with the address of variable x

    std::cout<<*ptr<<"\n"; // mesela bu 2 tutuyormuş ne bileyim ne alaka
    std::cout << *ptr3 << '\n'; // use dereference operator to print the value at the address that ptr is holding (which is x's address)

    int** ptr4 {&ptr3};
    std::cout << *ptr4 << '\n';
    std::cout<<(&x)<<"\n";
    
    int i{ 5 };
    double d2{ 7.0 };

    int* iPtr{ &i };     // ok: a pointer to an int can point to an int object
    // int* iPtr2 { &d2 };   // not okay: a pointer to an int can't point to a double object
    double* dPtr{ &d2 };  // ok: a pointer to a double can point to a double object
    // double* dPtr2{ &i }; // not okay: a pointer to a double can't point to an int object

    // int* ptr{ 5 }; // not okay
    // int* ptr{ 0x0012FF7C }; // not okay, 0x0012FF7C is treated as an integer literal
    // With one exception, initializing a pointer with a literal value is disallowed:

    int* ptr5{ 0 };       // İSTİSNA: Geçerlidir! (Null pointer yapar)
    int* ptr6 = 0;        // Geçerlidir.

    // Literal olarak 0 vermek kafa karışıklığı yarattığı için (sayı mı yoksa adres mi?), C++11 ile birlikte bu işe özel bir literal getirildi: 
    // nullptr.
    int* ptr7{ nullptr };  // Modern ve en doğru kullanım

    /*
    ptr = ... (Yıldımsız): "Nereye baktığını değiştir" (Adres değişir, asıl veriye dokunulmaz).
    *ptr = ... (Yıldızlı): "Baktığı yerin içindeki değeri değiştir" (Adres aynı kalır, orijinal değişkenin değeri değişir).
    */
    int y {8};
    int f {9};
    int m {55};
    int* ptry {&y};
    *ptry=f; // pointerın gösterdiği  adresteki değeri değiştir
    std::cout<<"y: "<<y<<" ptry: "<<ptry<<"\n";
    ptry= &m;// pointerın nereye baktığını değiştir
    std::cout<<"y: "<<y<<" ptry: "<<ptry<<"\n";
    std::cout<<*ptry<<"\n"; // y hala 9 ama ptry 55 i gösteriyor


    int x0{ 5 };
    int* ptr0{ &x };

    std::cout << *ptr0 << '\n'; // valid

    {
        int y0{ 6 };
        ptr0 = &y0;

        std::cout << *ptr0 << '\n'; // valid
    } // y goes out of scope, and ptr is now dangling

    std::cout << *ptr0 << '\n'; // undefined behavior from dereferencing a dangling pointer

    // The above program will probably print:5 6 6
    // But it may not, as the object that ptr was pointing at went out of scope and was destroyed at the end of the inner block, 
    // leaving ptr dangling.





    
    
}
/*
Pointers and lvalue references behave similarly. Consider the following program:

#include <iostream>

int main()
{
    int x{ 5 };
    int& ref { x };  // get a reference to x
    int* ptr { &x }; // get a pointer to x

    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (5)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (5)

    ref = 6; // use the reference to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (6)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (6)

    *ptr = 7; // use the pointer to change the value of x
    std::cout << x;
    std::cout << ref;  // use the reference to print x's value (7)
    std::cout << *ptr << '\n'; // use the pointer to print x's value (7)

    return 0;
}
This program prints:

555
666
777
References must be initialized, pointers are not required to be initialized (but should be).
References are not objects, pointers are.
References can not be reseated (changed to reference something else), pointers can change what they are pointing at.
References must always be bound to an object, pointers can point to nothing (we’ll see an example of this in the next lesson).
References are “safe” (outside of dangling references), pointers are inherently dangerous (we’ll also discuss this in the next lesson)
*/