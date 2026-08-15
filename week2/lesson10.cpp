#include <iostream>
#include <iomanip>

double takeInput(){
    std::cout<<"Enter a double value: ";
    double nm {};
    std::cin>>nm;
    return nm;
}

int main(){
    double nm1{takeInput()};
    double nm2{takeInput()};
    std::cout<<"Enter +, -, *, or /: ";
    char ch {};
    std::cin>>ch;
    std::cout<<std::fixed<<std::setprecision(2);
    if (ch=='+') std::cout<<nm1<<ch<<nm2<<" is "<<nm1+nm2;
    else if (ch=='-') std::cout<<nm1<<ch<<nm2<<" is "<<nm1-nm2;
    else if (ch=='*') std::cout<<nm1<<ch<<nm2<<" is "<<nm1*nm2;
    else std::cout<<nm1<<ch<<nm2<<" is "<<nm1/nm2;

}
/*
double karşılaştırmak için
#include <iostream>
#include <cmath> // std::abs için

bool esitMi(double a, double b, double epsilon = 1e-5) {
    // İki sayı arasındaki fark epsilon'dan küçükse eşit kabul et
    return std::abs(a - b) <= epsilon;
}

int main() {
    double x { 0.1 + 0.2 }; // Arka planda 0.30000000000000004 olur
    double y { 0.3 };

    if (x == y) {
        // Bu blok ÇALIŞMAZ (Hatalı yaklaşım)
    }

    if (esitMi(x, y)) {
        std::cout << "Sayilar esit kabul edildi!\n"; // Bu blok ÇALIŞIR
    }
}
*/
/*
1. std::fixed (Sabit Noktalı Gösterim Mode)Sayıyı bilimsel/üstel gösterim (e+06 gibi) yerine her zaman bildiğimiz ondalıklı formatta (123.45) 
yazdırır.
En önemli etkisi: std::setprecision'ın çalışma mantığını değiştirir.
2. std::setprecision(n) (Hassasiyet Ayarı)Kullanıldığı moda göre iki farklı anlama gelir:
std::fixed YOKSA (Varsayılan Mod):Sayının toplam anlamlı basamak sayısını (tam kısım + ondalık kısım toplamı) ayarlar.
Örnek (n=4): 123.4567  123.5 (Toplam 4 basamak)
std::fixed VARSA:Sayının virgülden sonraki basamak sayısını sabitler.Eksik basamaklar varsa sonuna sıfır ekler.
Örnek (n=4): 123.4567 $\rightarrow$ 123.4567 (Virgülden sonra 4 basamak)
*/