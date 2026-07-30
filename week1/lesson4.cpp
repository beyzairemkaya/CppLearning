// opearatörs
#include <iostream>

int main(){
    // Bir operatörün üzerinde işlem yaptığı değer sayısına (operand sayısına) operatörün aritesi (arity) denir.
    // 5 + 3 derken opearandlar 2 tane (5,3) operatör 1 tane (+)
    // 4 çeşidi vardır
    // Unary(1 operatör) -x, ++x, --x, !flag, *x , &x 
    // Binary a==b a+b std::cout << x
    // Ternary cpp de sadece condition ? x : y yapısı var int max = (a > b) ? a : b;
    // Nullary (Sıfır operand) sadece throw operatöründ ekullanılır
    /*
    In C++, the term “side effect” has a different meaning: it is an observable effect of an operator or function beyond producing a 
    return value.
    Since assignment has the observable effect of changing the value of an object, this is considered a side effect. 
    We use certain operators (e.g. the assignment operator) primarily for their side effects (rather than the return value those
     operators produce). In such cases, the side effect is both beneficial and predictable (and it is the return value that is often 
     incidental).*/
    /*
    For the operators we call primarily for their side effects (e.g. operator= or operator<<), it’s not always obvious what return values
    they produce (if any). For example, what return value would you expect x = 5 to have?
    Both operator= and operator<< (when used to output values to the console) return their left operand. Thus, x = 5 returns x, 
    and std::cout << 5 returns std::cout. This is done so that these operators can be chained.
    For example, x = y = 5 evaluates as x = (y = 5). First y = 5 assigns 5 to y. This operation then returns y, which can then be 
    assigned to x.
    std::cout << "Hello " << "world!" evaluates as (std::cout << "Hello ") << "world!". This first prints "Hello " to the console. 
    This operation returns std::cout, which can then be used to print "world!" to the console as well.*/
    
    int x{3};
    std:: cout<<(x=5)<<"\n";
    // x=5 x'e 5' i atar ve 5 return eder bu yzüen 5 yazdırılır 
    int a=b=5;
    // bunu yapabilirsin çünkü b=5 5 döndürür o da a ya eşitlenir a = (b = 5); = sağdan sola ilişkilidir

    // expressionlar literlller (5,"abc"), atama işlemlerifonksiyon atamaları olabilir
    // sonuçta tek bir değer üreten tüm kod parçaları expressiondur.
    // expresionlar ; içermez içerenler statmentdır örn int x=2+3; statment , 2+3 expression 

    // !!! int x=5; dediğinde üretilen değer 5 dir x in 5 e eşitlenmesi ise side effectir
    // Statements are used when we want the program to perform an action. Expressions are used when we want the program to calculate a value.
    return 0;
}