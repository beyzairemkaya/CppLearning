#include <iostream>

int main()
{
    int* ptr0 {}; // Create a null pointer
    std::cout << *ptr0 << '\n'; // Dereference the null pointer
    // null pointeri derefernce edemezsin undefinied behaviora yol açar
    /*
    Whenever you are using pointers, you’ll need to be extra careful that your code isn’t dereferencing null or dangling pointers, 
    as this will cause undefined behavior (probably an application crash).
    */

    int x { 5 };
    int* ptr { &x };

    if (ptr == nullptr) // explicit test for equivalence
        std::cout << "ptr is null\n";
    else
        std::cout << "ptr is non-null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n"); // explicit test for equivalence

    return 0;
}
/*
Similarly, pointers will also implicitly convert to Boolean values: a null pointer converts to Boolean value false, and a non-null pointer converts to Boolean value true. This allows us to skip explicitly testing for nullptr and just use the implicit conversion to Boolean to test whether a pointer is a null pointer. The following program is equivalent to the prior one:

#include <iostream>

int main()
{
    int x { 5 };
    int* ptr { &x };

    // pointers convert to Boolean false if they are null, and Boolean true if they are non-null
    if (ptr) // implicit conversion to Boolean
        std::cout << "ptr is non-null\n";
    else
        std::cout << "ptr is null\n";

    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // implicit conversion to Boolean

    return 0;
}
*/

// eğer pointerların özel özellkileirnikullanmicaksan refrransları tercih et çünkğ 
// Referanslar `null` değerine bağlanamadığı için `null` referanslar konusunda endişelenmemize gerek kalmaz. Ayrıca referanslar oluşturuldukları 
// anda geçerli bir nesneye bağlanmak zorunda oldukları ve sonradan başka bir nesneye yönlendirilemedikleri için, geçersiz (dangling) 
referansların oluşması daha zordur.