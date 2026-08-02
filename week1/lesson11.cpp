// header files include ile dahil edilir soruce file gibi birlikte compile edilmez
// header files .h uzantılır

// diyelim ki add.cpp deki fonksiyonları main.cpp de kullanmak istiyoruz bu durumda öncelikle kullnacağın
// fonksiyonların adlarını tek tek mainde forward declaration yapman gerekir 
// bu durumda bizde diyoruz ki add.h adlı bir dosya olsun içinde fonksiyon iismleri onu maincpp ye include edelim

#include "add.h"
// "" untma

// deneme1.cpp, deneme2.cpp ve deneme2.h ı oku

