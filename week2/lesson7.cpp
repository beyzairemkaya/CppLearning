#include <iostream>

int main(){
    bool a {}; // otomatik olarak false intialize eder
    // 0 false 1 true unutma
    bool b {true};
    std::cout<<a<<"\n";
    std::cout<<b<<"\n";
    // true false olarak yazdırmal istiyorsan boolalpha kullan 
    std::cout<<std::boolalpha;
    // bundan sonra thepsi true false oalrak yazar unutma
    std::cout<<!true<<"\n"; // false
    // kapatmak için
    std::cout<<std::noboolalpha;
    std::cout<<!true<<"\n"; // 0

    std::cout<<std::boolalpha;
    bool c {0}; // bu şekildede başlatabilrisn ama true false olarak başlatmak daha iyi
    std::cout<<c<<"\n";

    // normalde 0 false diğer tüm intler true ama dediğim gibi çok kullanma
    // copy initialization buna izin verir
    bool d=8;
    std::cout<<d<<"\n";
    // ama direct list initialization izin vermez aşağıdaki kod narrowing converison hatası verr
    // bool d {8};

    //std::cin ile girdi alma
    std::cout<<"enter true to failure enter 1 to continue ";
    bool e {true}; // boş başlatsak false initialize edecek
    std::cin>> e;
    std::cout<<e<<"\n";
    // false yazdırdı neden 
    // Sayısal Beklenti: 0 yazarsan false, 1 (veya sıfır dışı bir sayı) yazarsan true kabul edilir.
    // Ekrana harfle true yazdığında std::cin bunu sayıya çeviremez. 
    // İşlem başarısız olur (failure mode), değişkene varsayılan değeri olan false (0) atanır ve std::cin girdi almayı durdurur.
    // yani bu hali ile 0 yada 1 yada bambaşka bir sayı bekliyor metin beklemesini istiyorsan
    // std::cin i de boolalphaya çevşrmen gerek7
    std::cin>>std::boolalpha;
    // bu koddan sonra sayısal girdi girersen false yapıp failure moduna geçer tekrardan
    // Enabling std::boolalpha for input will only allow lower-cased false or true to be accepted. 
    // Variations with capital letters will not be accepted. 0 and 1 will also no longer be accepted.
    std::cout<<"enter true ";
    bool f {true};
    std::cin>> f; 
    std::cout<<f<<"\n";

    int g {7}; // 0 olmadığı için 1 evaluate edilir
    if (g) std::cout<<"heh heh";
    else std::cout<<"ühü ühü";
    // normal bir int değeri if stament içinde bool a otomatik çevrilir

    int h {0}; // 0 olmadığı için 1 evaluate edilir
    if (h) std::cout<<"heh heh";
    else std::cout<<"ühü ühü";

    // if (x) means “if x is non-zero/non-empty”.

    
    
}