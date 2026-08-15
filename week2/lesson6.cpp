#include <iostream>
#include <iomanip> // setprecision ve set::fixed için
int main(){
    // ondalıklı sayılarda intler gibi cpp bunara kesin bir veri boyutu tanımlazmaz
    // genel olarak float 4 byte double 8 bytle long double 8,12,16 byte olarak tanımlanır ama
    // 5.0 bir double dır o yüzden float olarak tanımlamak istersen yanına f harfi koyman gerek 
    float f {5.0f};
    double d {5.0};
    // yoksa veri kaybına yol açabilirsin
    std::cout <<d<<"\n";     //5
    std::cout <<3.000<<"\n"; //3
    // std::cot default oalrak . dan sonraı 0 sa atar int gibi yazdırır
    std::cout<<5.4<<"\n";
    std::cout<<879.34903400<<"\n";
    
    

    // C++'ta std::cout varsayılan olarak 6 anlamlı basamak kuralını uygular, ancak sayının büyüklüğüne göre gösterim şeklini otomatik değiştirir
    // Sayı 1 Milyondan küçükse: Normal ondalıklı formatta yazar.
    // Sayı 1 Milyon veya daha büyükse (ya da 0.0001'den küçükse): 6 basamak sınırına sığdıramadığı için otomatik olarak bilimsel gösterime 
    // (scientific notation) geçer.

    std::cout << 9876543.21<<"\n";

    
    double sayi = 879.34903400;
    // Toplam anlamlı basamak sayısını 10 yapar:
    std::cout << std::setprecision(10) << sayi << '\n';
    // Çıktı: 879.349034

    // Virgülden sonrasını tam 4 basamak olmaya zorlar:
    std::cout << std::fixed << std::setprecision(4) << sayi << '\n';
    // Çıktı: 879.3490

    // Dikkat sadece bulundukları satırı değil bu noktadan sonra yazdığın satorlarıda etkileyecekler

    // rounding errora dikkat et
    bool exp {0.2==0.1+0.1};
    std::cout<<std::boolalpha<<exp<<"\n";
    // 0.2 == 0.1 + 0.1 ifadesinin true veya false olması garanti değildir. 
    // Kullandığın derleyici ve yaptığı optimizasyonlar nedeniyle true çıkabilir
    std::cout<< std::setprecision(18);
    std::cout<<0.3<<"\n"<<0.2+0.1<<"\n";
    // std::boolalpha 0 ve 1 çıktılarını false true olarak yazdırır 0 false unutma
    // neyi optimize edip neyi etmeyeceğini bilemezsin

    // Inf, which represents infinity. Inf is signed, and can be positive (+Inf) or negative (-Inf).
    //NaN, which stands for “Not a Number”. There are several different kinds of NaN (which we won’t discuss here).
    // Signed zero, meaning there are separate representations for “positive zero” (+0.0) and “negative zero” (-0.0).
    // std::cout<<5/0<<"\n"; division by zero hatası
    std::cout<<5.0/0.0<<"\n"; // inf
    // Eğer bir sıfır olmayan floating point sayı 0.0'a bölünürse, sonuç ∞ (infinity) olsun. diye krual belirlemişler
    std::cout<<-5.0/0.0<<"\n";
    // std::cout<<0/0<<"\n";  // division by zero
    std::cout<<0.0/0.0<<"\n"; // nan
    double posinf { 5.0 / 0.0 };
    std::cout<<0.0/posinf<<"\n";
    




   
    

}
