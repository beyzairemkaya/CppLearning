#include<iostream>

// Cpp de static linkage i etkiler eğer bir değişkeni static yyaaprsan linkage e onu diğer obj dosyaalrına açma demiş olursun
static int var_1 {8};
// diğer bir dosyada yine var_1 kullanırsın bunları çağırdın dosyada ise conflict olmaz static oldukları için
// bu değişken global varianles with internal linkage  yani internalvariables
// Const and constexpr global variables have internal linkage by default (and thus don’t need the static keyword  if it is used, 
// it will be ignored).
// çünkü mesela iki .h doasyında p ye ihtiyacın var const double pi = 3.14159; siye kullanıcamn sonrada çakışma olacak pi1 pi2
// demekde saçma olur
constexpr int g_x {7};
// int add(int x, int y); // forward declaration for function a

// diğer değişkenler zaten default olarak external dır ama cont ve constexpr larıda external yapmak istersen extern kullanabilirsin
extern constexpr int g_y {6};

// int g_abc;
extern int g_abc; // forward decleretionumuzu yaparken başka dosyada var git ondan al demeliyiz extern ile yoksa yukardaki gibi 0la 
// başlatır ve mıltiple definition hatası verir 
extern int g_abc2;


// externi 2 yerde kullandık 
// 1) başka dosaydan değişken çaüğırmak istediğimizde
// 2) eğişkeni tanımladığın dosyada const olarak tanımloıyorsan dışarıya açılabileceğini belirtmek için

// f you want to define an uninitialized non-const global variable, do not use the extern keyword, 
// otherwise C++ will think you’re trying to make a forward declaration for the variable.
int main(){
    std::cout<<g_x<<"\n";
    // 7 yazdırdı ve herhangibir çakışma bildirmedi
    // local değişkenmiş gibi düşün 7 burdaki kapsamda 9 dış kapsamda 7 yi yazdırdı main burda oldugu için
    // std::cout << add(3, 4) << '\n';
    // This program won’t link, because function add is not accessible outside of add.cpp.

    // !! diğer dosyadan özelolarak ulaşman gereken bir değer yoksa best practice olarak static ver gepsine
    // ya static yap yada constexro yap öyle static olsun
    // std::cout<<g_abc<<"\n";
    // g_abc yi diğer dosyadan görebilmesi için extern olmalı burda mültiple definition hatasoı verdi
    std::cout<<g_abc2<<"\n";
    std::cout<<g_abc<<"\n";
}

/*
extern int g_y;                 // forward declaration for non-constant global variable
extern const int g_y;           // forward declaration for const global variable
extern constexpr int g_y;       // not allowed: constexpr variables can't be forward declared

*/
