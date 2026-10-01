// A class type is a type that is a struct, class, or union
#include <iostream>

int return5(){
    return 5;
}

int main(){
    // lvalue genellikle adreslerini karşılaşrtırarak diğer birimlerden ayrıştırabileceğimiz birim
    // Since the introduction of constants into the language, lvalues come in two subtypes: a modifiable lvalue is an lvalue whose 
    // value can be modified. 
    // A non-modifiable lvalue is an lvalue whose value can’t be modified (because the lvalue is const or constexpr).
    int x{};
    const double d{};

    int y { x }; // x is a modifiable lvalue expression
    const double e { d }; // d is a non-modifiable lvalue expression
    // burda y ve e de lvalue tabii ki

    int x1{ 5 }; // 5 is an rvalue expression
    const double d1{ 1.2 }; // 1.2 is an rvalue expression

    int y1 { x }; // x is a modifiable lvalue expression
    const double e1 { d1 }; // d is a non-modifiable lvalue expression
    int z { return5() }; // return5() is an rvalue expression (since the result is returned by value)

    int w { x1 + 1 }; // x + 1 is an rvalue expression
    int q { static_cast<int>(d1) }; // the result of static casting d to an int is an rvalue expression

    // You may be wondering why return5(), x + 1, and static_cast<int>(d) are rvalues: 
    // the answer is because these expressions produce temporary values that are not identifiable objects.
    /*
    Unlike the other literals (which are rvalues), a C-style string literal is an lvalue because C-style strings 
    (which are C-style arrays) decay to a pointer. The decay process only works if the array is an lvalue (and thus has an address that 
    can be stored in the pointer). C++ inherited this for backwards compatibility.
    */
   /*
   T& → lvalue reference → lvalue'larla çalışır
   T&& → rvalue reference → rvalue'larla çalışabilir
   */
  // So as you can see, whether operator++ results in an lvalue or an rvalue depends on whether it is used as a prefix operator (
  // which returns an lvalue) or a postfix operator (which returns an rvalue)!

  


    return 0;
}