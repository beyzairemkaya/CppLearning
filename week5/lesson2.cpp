/*
Cast	               Description	                                                                                                   Safe?
static_cast            Performs compile-time type conversions between related types.	                                               Yes
dynamic_cast           Performs runtime type conversions on pointers or references in an polymorphic (inheritance) hierarchy	       Yes
const_cast	           Adds or removes const.	                                                                                       Only for adding const
reinterpret_cast	   Reinterprets the bit-level representation of one type as if it were another type	                               No
C-style casts	Performs some combination of static_cast, const_cast, or reinterpret_cast.	                                           No

const_cast and reinterpret_cast should generally be avoided because they are only useful in rare cases and can be harmful if used incorrectly
*/
# include <iostream>

int main(){

    int n {7};
    int d {2};
    double result {(double)n/d};
    std::cout<<result<<"\n";
    // ama C style farklı castların kombinasyonu oldugu için kullanamk beklendmedik sonuçlara yol açabilir bu yüzden olabildiğince kaçın
    // There is one thing you can do with a C-style cast that you can’t do with C++ casts: C-style casts can convert a derived 
    // object to a base class that is inaccessible (e.g. because it was privately inherited).
    std::cout << static_cast<int>('c')<<"\n";
    int x { 10 };
    int y { 4 };

    // We want to do floating point division, so one of the operands needs to be a floating point type
    // std::cout << double{x} / y << '\n'; // okay if int is 32-bit, narrowing if x is 64-bit
    // bizde narrowing conversion verdi mesela
    // bu yöntemde unsigned int {} falanda çeviremzsin o yüzden en iyuiis hiç uğraşmadan static cast kullanmak

}