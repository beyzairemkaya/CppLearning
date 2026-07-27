#include <iostream>

int main(){
    // initializion işlemini farklı şekillerde yapılabilir
    int x=0.7;
    std:: cout << x <<"\n";
    //(birlikte eklemede böyle olur unutma)

    // burda x=0 alınır cpp hata olarak görmez ve seni uyarmaz, veri kaybı olur
    // x (0.7) deesende 0 alır
    // int y {0.5};
    // std:: cout << y;
    // burda ise narrowing conversion hatası verir o yüzden bu atama şekli dah çok tercih edilir

    int a;
    std :: cout<< a<<'\n'; // ramdaki rastgele adres 
    // ayrıca int a; diye başlatırsan x  varsayılan 0 değeri ile değil ramda kalan son değerle başlatılır  
    // an indeterminate value (a value that is not predictable, sometimes called a “garbage value”).
    // bu yüzden bu yöntem daha güvenliidir
    int b{};
    std :: cout << b<<'\n';

    // Not , operatörü sırayla değerlendir demek örn 
    int c=(3,5);
    std:: cout<< c; // 5 yazırırönce c=3 sonra c=5 oldu
    
    int d (6);
    // direct initialization
    // c++ da classları myclass () şeklinde çağırırız örneğin generic de vs sıkıntu çıkmasın diye int gibi primative 
    // typlerı da bu şekilde initiaze edebilirsin. 
    // ama int () 0 değil int tipinde değer döndüren ve parametre almayan c adında bir FONKSİYON BİLDİRİMİ olark algılanır
    // int x () dersen  int döndüren x fonksiyonu olarak anlar
    // bu yüzden {} kullanmak en iyisi classlaerda {} ile sıkıntısız çalışır

    /*Özetle, parantezli ilklendirme (`()`) günümüzde iki temel nedenden ötürü varlığını sürdürür: 
    Birincisi, süslü parantezin (`{}`) verileri öncelikli olarak bir eleman listesi zannetme garipliğini aşarak `std::vector<int>(10, 5)` 
    örneğindeki gibi doğrudan sınıf kurucularını (constructor) çağırabilmektir; ikincisi ise C++ derleyicisinin `static_cast` gibi açık tür 
    dönüşümleri (type casting) yaparken arka planda dönüştürme işlemini tam olarak bu parantezli ilklendirme mekanizmasını kullanarak 
    gerçekleştirmesidir.*/
    // {10,5} i 10,5 listesi olarak algılar
    // (10,5) ise (5,5,5,5,5,5,5,5,5,5) plarak algılar 10 elamanlı 5 diizisi bu yüzden bazen () ihtiyacımız var

    /*: When should I initialize with { 0 } vs {}?
    Use direct-list-initialization when you’re actually using the initial value:
    int x { 0 };    // direct-list-initialization with initial value 0
    std::cout << x; // we're using that 0 value here
    Use value-initialization when the object’s value is temporary and will be replaced:
    int x {};      // value initialization
    std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless*/
    int e,f=5;
    // f=5 e sadece tanımlandı
    std:: cout<< e<<"\n"<<f;
    // e rastgale bir numara şu an f ise 5

    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
    [[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
    [[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused
    // hata vermemesi için [[maybe_unused]] kulllanabilirsin
    return 0;

}