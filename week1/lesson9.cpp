#include <iostream>

// Namespaces

// namespaces ler aslında javadaki packageler gibidir aynı iisimli fonksiyonların çatısmasını önler
// örneğin std:: cout diye kullanırken std bir namespaces dir 
// br namespaces tanımlarken içinde sadece fonskiyon ve değişkenlerin isimleri olmalı ama çalıştırılabilir kod olmamlı
// ::  scope resolution operator.
//  :: koymuyosak otomatik olarak global scope gelir

#include <iostream>

namespace Math
{
    void print()
    {
        std::cout << "Math\n";
    }
}

namespace Physics
{
    void print()
    {
        std::cout << "Physics\n";
    }
}

int main()
{
    Math::print();
    Physics::print();
}

// bir namescpace veya bir class a ait olmayan fonksiyonlar ve değişkenler globaldir
int c(){return 3;} // global fonksiyon

int d{};
int e{6}; // global variableri initialeze ederek veya ewtmeyerek kullanabilirsin ama kullanmamamn daha iyi olur
// e++;
// bu tür işlemleri global scope da yapamazsın

/*
#include <iostream> // imports the declaration of std::cout into the global scope

using namespace std; // makes std::cout accessible as "cout"

int cout() // defines our own "cout" function in the global namespace
{
    return 5;
}

int main()
{
    cout << "Hello, world!"; // Compile error!  Which cout do we want here?  The one in the std namespace or the one we defined above?

    return 0;
}
*/
// using namespace yapısıda kullanilabilir ama dedği gibi daha sonra conflict e yol açabileceği için kullanmamak en iyisiidir