// tüm kodlar önce preprocessor dan geçer bu # ile başlayan kodlrın çözümlendiği dönemdir
// örneğin #include
#include <iostream>
// define ile macros tanımlarız 
// derleyici kodu görmeden önce yapılan metin değiştirme işlemidir.
// iki tip macro vardır birinciis object like macros ve ikincici function like macros

// object like macro ya bir örnek
#define PI 3.14159
// modern c++ da bunuh yerine constexpr double PI{3.1415926}; tercih edilir
// PI diye bir değişken oluşturulmadığına dikkat et sadece metin değiştirilir

// function like macro 
// #define SQUARE(x)=x*x = yok unutma direkt metin alacak
#define SQUARE(x) x*x

// ama function like macrolarda bir sıkıntı çıkıyor gerçekten direkt kopyala yapıştır yapıyor ve matematik bilmiyor
int main(){
    int a {SQUARE(5)};
    // beklenildiğim gibi 25 çıkar
    int b {SQUARE(2+3)};
    // 2+3*2+3 e çeviriir matematiği c++ yapar doğla olarak sonuç 11 çıkar
    std::cout<<a<<" "<<b;
}