//Errors 

// macrolar ile debug modu yapabildiğimizi öğrenmiştirk

/*
eğer debug amacı ile bir lşeyler print ediyorsan std::cout değil std ::cerr kullan 
When printing information for debugging purposes, use std::cerr instead of std::cout. 
One reason for this is that std::cout may be buffered, which means a bit of time may pass between when you ask std::cout to output text 
and when it actually does. If you output using std::cout and then your program crashes immediately afterward, std::cout may or may not 
have actually output yet. This can mislead you about where the issue is. On the other hand, std::cerr is unbuffered, which means anything 
you send to it will output immediately. This helps ensure all debug output appears as soon as possible (at the cost of some performance, 
which we usually don’t care about when debugging).
Using std::cerr also helps make clear that the information being output is for an error case rather than a normal case.
*/
/*
**dbg**, C++ için geliştirilmiş, **header-only** bir debug kütüphanesidir. Kodun içine `dbg(x);` gibi hata ayıklama ifadeleri eklemeyi 
kolaylaştırır; değişken adlarını, değerlerini ve gerektiğinde satır bilgilerini ekrana yazdırabilir. `DBG_MACRO_DISABLE` adlı preprocessor
macro'su tanımlandığında ise tüm bu debug ifadeleri derleme sırasında otomatik olarak kaldırılır. Böylece aynı kodu değiştirmeden geliştirme
(debug) ve yayın (release) sürümleri arasında kolayca geçiş yapılabilir.

*/

// Logger

// Logger, debug ve çalışma bilgilerini konsola değil bir log dosyasına yazdırmak için kullanılır.
// C++ bu amaçla std::clog sunar. Varsayılan olarak std::cerr ile aynı çıktı akışına (stderr) yazar.
// Bu yüzden tek başına dosyaya yazmaz.
// Dosyaya yönlendirmek için örneğin:
// std::ofstream file("log.txt");
// std::clog.rdbuf(file.rdbuf());
// kullanılabilir.
// Ancak bu yöntem temel seviyededir. Bu yüzden gerçek projelerde plog, spdlog gibi
// üçüncü taraf logging kütüphaneleri daha yaygın olarak tercih edilir.
// std::cout → Normal program çıktısı.
// std::cerr → Hata mesajları.
// std::clog → Log mesajları.
// Yani davranışları varsayılan durumda benzese de, anlamsal olarak farklı amaçlarla kullanılmaları beklenir.

// Kodu çalıştırman için plog githubdan indrip include etmen lazım şu an uğraşmıyorum kullanacağımız zaman yaparız 
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput(){
    PLOGD << "getUserInput called";
    std :: cout<<"Enter a number: ";
    int x {};
    std cin >>x;
    return x;
}
int main(){
    plog::init(plog::debug, "Logfile.txt"); // initialize the logger
    // plog::none yaparsan kapanır log kaydetmez kodunda sadece bu kısmı değiştşrmen gerekir
    PLOGD "main called";
    std:: cout<< "You entered: "<< getUserInput();
}
// In larger or performance-sensitive projects, faster and more feature-rich loggers may be preferred, such as spdlog.
