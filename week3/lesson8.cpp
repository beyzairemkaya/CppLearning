#include <utility>
#include<iostream>
// Prefer defining global variables inside a namespace rather than in the global namespace.
// Consider using a “g” or “g_” prefix when naming global variables (especially those defined in the global namespace), 
// to help differentiate them from local variables and function parameters.


// Non-constant global variables
int g_x1;                 // defines non-initialized global variable (zero initialized by default)
int g_x2 {};              // defines explicitly value-initialized global variable
int g_x3 { 1 };           // defines explicitly initialized global variable

// Const global variables
// const int g_y1;           // error: const variables must be initialized
const int g_y2 { 2 };     // defines initialized global const

// Constexpr global variables
// constexpr int g_y3;       // error: constexpr variables must be initialized
constexpr int g_y4 { 3 }; // defines initialized global constexpr

int g_x4;       // no explicit initializer (zero-initialized by default)
int g_y {};    // value initialized (resulting in zero-initialization)
int g_z { 1 }; // list initialized with specific value
namespace Foo // Foo is defined in the global scope
{
    int g_x {}; // g_x is now inside the Foo namespace, but is still a global variable
}

void my_swap(int x, int y){
    int temp{x};
    x=y;
    y=temp;
    
}



int main(){
    int x {8};
    int y{9};
    my_swap(x,y);
    // Değerler içeriye kopya (pass by value) olarak gittiği için main içindeki asıl değişkenler değişmedi.
    std::cout<<x<<" "<<y<<"\n";

    int temp{x};
    x=y;
    y=temp;
    std::cout<<x<<" "<<y<<"\n";
    /*
    int main() {
    int x {8};
    {
        x = 99; // Yeni int tanımlanmadığı için dıştaki x doğrudan değişir
    }
    // x artık 99'dur
    }
    Fonksiyon çağrısı ise nested scope gibi çalışmaz; parametreler (int x, int y) her zaman o fonksiyonun kendi yerel değişkenleri olarak 
    sıfırdan oluşturulur.
    
    */

    // aynı işlevi gören fonksiyon var zaten utility den std::swap
    std::swap(x,y);
    std::cout<<x<<" "<<y<<"\n";


}