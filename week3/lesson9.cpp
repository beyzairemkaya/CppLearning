#include <iostream>

int main(){
    int a {5};
    int b{5};
    {
        int a {30};
        // When inside the nested block, there’s no way to directly access the shadowed variable from the outer block.
        b=40;
        // inner blok içinde tekrar bir a tanımlayabilirisn ya da outer bloktaki değişkenin değerini dğeiştirebilirsin
        std::cout<< "a: "<<a<<" b: "<<b<<"\n";
    }
    std::cout<< "a: "<<a<<" b: "<<b<<"\n";
    // değeri değiştirisen değer outerda da dğeilir ama inner içindei a nın scope u bitti
}