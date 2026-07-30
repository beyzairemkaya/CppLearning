#include <iostream>
//functions

/* 
 int main(){
    // The function initiating the function call is the caller, and the function being called (executed) is the callee. 
    // A function call is also sometimes called an invocation, with the caller invoking the callee.
    std ::cout << b();
}
int c(){
    return 2;
}
int b(){
    int x=c();
    return x;
}
*/
// bu hali ile scope hatası verir c++ baştan sona okur java gibi önce verileri toplamaz 
// bu yüzden forward declaration yapman gerekir
int b();
int c();
int main(){
    // The function initiating the function call is the caller, and the function being called (executed) is the callee. 
    // A function call is also sometimes called an invocation, with the caller invoking the callee.
    std ::cout << b();
}
int b(){
    int x=c();
    return x;
}
int c(){
    return 2;
}
/*
küçük projelerde forward declation kullanırsın büyük projelerde ise header dosyaların olur math.h gibi
İçinde genellikle şunlar bulunur:
Fonksiyon bildirimleri (declaration)
Sınıf tanımları (class)
Struct'lar
Enum'lar
Sabitler
Template'ler
Yani "Burada böyle şeyler var." bilgisini verir.
*/

// c++ de nested functions yok ama nested classlar var

/*
#include <iostream>

void greet() {
    std::cout << "Merhaba\n";
}

int main() {
    greet();
}

Burada:

main() → caller
greet() → callee

Çünkü main, greet'i çağırıyor.*/

// başka fonsl,yonlarda main i çağıramazsın function call yapamazsın  veya function overload yapmazsın void main() gibi

