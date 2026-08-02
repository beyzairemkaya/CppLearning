#include "deneme2.h"
#include <iostream>

int main(){
    std::cout<<doub(3);
}

// .cpp DOsyalarını include etme

/*
There are number of reasons for this:
Doing so can cause naming collisions between source files.
In a large project it can be hard to avoid one definition rules (ODR) issues.
Any change to such a .cpp file will cause both the .cpp file and any other .cpp file that includes it to recompile, which can take a long time. Headers tend to change less often than source files.
It is non-conventional to do so.
*/

// Kendiyazdığımız header dosayları için "" sistemden gelenler için <> kullanırız
/*
When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t write ourselves. 
The preprocessor will search for the header only in the directories specified by the include directories. 
The include directories are configured as part of your project/IDE settings/compiler settings, and typically default to the directories 
containing the header files that come with your compiler and/or OS. The preprocessor will not search for the header file in your project’s 
source code directory.
*/

/*
Başka klasörlerde bulunan header dosyalarını doğrudan göreli yollarla (#include "headers/myHeader.h" gibi) eklemek mümkündür, 
ancak iyi bir yöntem değildir. Çünkü kodun, klasör yapısına bağımlı hale gelir ve klasör yapısı değişirse tüm #include satırlarını 
güncellemek gerekir.

Bunun yerine, derleyiciye veya IDE'ye header dosyalarının bulunduğu klasörleri "include path" (arama dizini) olarak tanıtmak daha 
doğru yaklaşımdır. Böylece kodunda sadece:

#include "myHeader.h"

yazarsın; derleyici dosyayı tanımladığın arama dizinlerinde kendisi bulur.

VS Code'da bu işlem tasks.json dosyasında derleyici argümanlarına şu satırı ekleyerek yapılabilir:

-I./source/includes

(-I ile yol arasında boşluk bırakılmaz.) Bu yöntem kodu daha taşınabilir, okunabilir ve klasör yapısı değişikliklerine karşı daha 
dayanıklı hale getirir.
*/
/*
The content of these transitive includes are available for use in your code file. However, you generally should not rely on the content of 
headers that are included transitively (unless reference documentation indicates that those transitive includes are required). 
The implementation of header files may change over time, or be different across different systems. If that happens, your code may only 
compile on certain systems, or may compile now but not in the future. This is easily avoided by explicitly including all of the header files 
the content of your code file requires.
Best practice
Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other 
headers.
*/

// diyelim ki b a ya ihtiyaç duyuyor sen kodunda önce a yı sonra b yi include ettin böylece b nin ihtiyaç duyduğu her şey hazır oldu
// eğer a nın içine b yi include etmeyi unuttuysan kodda derleme hatası almazsın ve sorunu görmen zorlaşır
// bu yüzden özelden genele include et

/*
The paired header file for this code file (e.g. add.cpp should #include "add.h")
Other headers from the same project (e.g. #include "mymath.h")
3rd party library headers (e.g. #include <boost/tuple/tuple.hpp>)
Standard library headers (e.g. #include <iostream>)
*/