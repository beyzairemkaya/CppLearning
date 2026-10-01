#include <iostream>

int main(){
    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y
    // const değerlerin pointerlarıda const olmalı ama bu sadece şunu engeller *ptr=9 falan pointırı başka yöne çevirebilriisn

    // const pointer yapmak için
    int m {6};
    int* const ptr2 {&m};
    // m yerine x yazsak hata verir consttan inte çeviremem x i diye
    // ptr2=&y; hata

    int xy{ 5 }; // non-const
    const int* ptr3 { &xy }; // ptr points to a "const int"

    // *ptr3 = 6;  // not allowed: ptr points to a "const int" so we can't change the value through ptr
    xy = 6; // allowed: the value is still non-const when accessed through non-const identifier x
}
/*
However, because the value being pointed to is non-const, it is possible to change the value being pointed to via dereferencing the const pointer:

int main()
{
    int x{ 5 };
    int* const ptr { &x }; // ptr will always point to x

    *ptr = 6; // okay: the value being pointed to is non-const

    return 0;
}
    Finally, it is possible to declare a const pointer to a const value by using the const keyword both before the type and after the asterisk:

int main()
{
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value

    return 0;
}
*/
/*
int main()
{
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself.  We can modify the value or the address.
    const int* ptr1 { &v };       // points to a "const int" but is not const itself.  We can only modify the address.
    int* const ptr2 { &v };       // points to an "int" and is const itself.   We can only modify the value.
    const int* const ptr3 { &v }; // points to a "const int" and is const itself.  We can't modify the value nor the address.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer

    return 0;
}
*/