int a(int);
int main(){
    a(4);
}
// şimdi bunu derlerken g++ func.cpp lesson8extra.cpp -o lesson8extra şeklinde derlemen gerekekcek öylece a fonksiyonunu görebilir

// bu dosyada kullanmadığın iöçin include iostream veya b declarationa ihtiyacın yok unutma
// iki dosyayı birlikte derleyeceğin zaman sadece bir tane man olmalı unutm afunc.cpp içinde main olsaydı hata veriridi

/*
int a(int b){
    return b;
}
*/

// aynı mainde oldugu gibi linker error verdi 
// eğer name collitision aynı dosyada ise compile error farklı dosyalarda ise linker error verir
// a fonksiyonu hiç çağırmasan bile bu hata verilir
// Name collision fonksiyonlarda oldugu gibi GLOBAL DEĞİŞKENLER'de de olabilir