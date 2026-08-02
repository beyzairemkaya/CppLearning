#include <iostream>
#define USE_YEN
// bu kısaca USE_YEN tanımla ve kullanılıyorsa hiçbir şeyle değiştir demektir 
// bu kullanımı anahtar gibi düşünebilirsin nerelerde kullanıldığını anlatmadan önce küçük bir örnek yazalım

int main()
{
    #ifdef USE_YEN
    std:: cout<< "there is USE_YEN\n";
    #endif

    #ifdef USE_BEYZA
    std:: cout<< "there is USE_BEYZA";
    // zaten soluk harflerle gösteriliyor daha compile edilmeden
    #endif

    // #if0 da burdan başlayan kodu derleme demek içinde multline comment olan kod satırlarını comment out yapamadığında kulanabilrisn
    #if 0
    // if yanlış zaten hep yanlış olacak
    int a {5};
    /*
    bla bala
    bla bla
    */
   int b{3};
   std:: cout<< a<<b;
   #endif
   // geçici olarak tekrar kullanılabilir yapmak istersen if 0 1 if 1 yaaparsın
   // başka durumlarda if 1 kullanmak mantıksız çünkü zaten koda karışmasanda çalışacaktı
   #if 1
   std :: cout<< "now works";
   #endif


}
// Since we defined PRINT_JOE to be nothing, how come the preprocessor didn’t replace PRINT_JOE in #ifdef PRINT_JOE with nothing and 
// exclude the output statement from compilation?
// In most cases, macro substitution does not occur when a macro identifier is used within another preprocessor command.
// bu durumda en başta USE_YEN tanımladığımız için ilk if satırı çalışacak ama ikincidi çalışmayacak

// örneğin debug modu için kodlar yazarsın en başa #define DEBUG eklersin debug moduyla işin bitince define debug satırını silersin 
// böylece tek tek kodu değiştirmene gerek kalmaz
// Windows'ta terminali temizleme komutu system("cls") iken, Linux'ta system("clear") komutudur.
/*
#ifdef _WIN32
    system("cls");   // Sadece Windows'ta derlenir
#elif __linux__
    system("clear"); // Sadece Linux'ta derlenir
#endif
*/ // şeklindede kullanabilrisn
// yada pro ve ücretsiz sürüm ayrımını yaparsın
// #ifndef MOTOR_H  // Eğer MOTOR_H daha önce tanımlanmadıysa... #define MOTOR_H
// bu sayade aynı header dosyalrını tekrar tekrar gömmezsin
// ifndef tanımlanmamaışsa demek

/*
#include = Kopyala/Yapıştır: Bir dosyadaki #define bilgisini başka bir dosyaya taşımak istiyorsan, onu bir Header (.h) dosyasına yazıp 
kullanacağın yere #include etmek zorundasın.

Kapsam (Scope) Sınırı: Bir .cpp dosyasına yazılan #define, sadece o dosyanın en alt satırına kadar geçerlidir. 
Çağırdığın yan fonksiyonların bulunduğu diğer .cpp dosyalarını etkilemez.
unction.cpp:

#include <iostream>

void doSomething()
{
#ifdef PRINT
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
}
main.cpp:

void doSomething(); // forward declaration for function doSomething()

#define PRINT

int main()
{
    doSomething();

    return 0;
}
The above program will print:

Not printing!
Alex.h:

#define MY_NAME "Alex"
main.cpp:

#include "Alex.h" // copies #define MY_NAME from Alex.h here
#include <iostream>

int main()
{
	std::cout << "My name is: " << MY_NAME << '\n'; // preprocessor replaces MY_NAME with "Alex"

	return 0;
}
*/
// neyi include edip neyi etmediğine dikkat et
