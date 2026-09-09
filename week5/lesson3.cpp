#include <iostream>

using TestScore = int;
TestScore gradeTest(){
    return 90;

}
/*
In our experience, creating a type alias just to document the return type of a single function isn’t worth it (use a comment instead). 
But if you have multiple functions passing or returning such a type, creating a type alias might be worthwhile.
*/

int main(){
    // type allias yet tutucuudur mesela
    using Distance=double;
    // artık Distance double yerine tutulur tabii bunu yapma sebebimiz double yerine kullanmak değil
    // çok uzun oldugunda veya sonradan değişebilecek şeyler olduunda namespace içinde Fizik::mat::x gibi yer tutmak için
    // ayrıca scopeları önemli mesela burda sadece main içnde istersen header dosyasının içindede tutabiliridin alliasları
    // The following aliases are identical
    typedef long Miles;
    using Miles = long
    // typedef de alliasın eski hali ama syntax olarak allias lar daha anlaşılır oldugu için onları kullan
}
/*
### Özet — Platform bağımsız kodlamada type alias

C++'ta `int`, `short`, `long` gibi temel türlerin boyutları platforma göre değişebildiği için, platform bağımsız kodlarda belirli bir bit 
genişliğini garanti etmek amacıyla **type alias** kullanılabilir. Örneğin `int8_t`, `int16_t`, `int32_t` gibi isimler, farklı platformlarda 
uygun temel türe (`char`, `short`, `int`, `long`) alias edilerek aynı genişliği sağlar. Modern C++'ta `<cstdint>` içindeki `std::int8_t`, 
`std::int16_t`, `std::int32_t`, `std::uint32_t` gibi **fixed-width integer** türleri zaten bu mantıkla tanımlanmış type alias'lardır. 
Önemli bir detay olarak, `std::int8_t` çoğu sistemde `signed char`'ın alias'ıdır; bu nedenle `std::cout << x` ile yazdırıldığında sayı 
yerine ASCII karakteri gösterebilir (örneğin `97` → `a`).

*/