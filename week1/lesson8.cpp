#include <iostream>

//Forward declarations

// fonksiyonları yeniden sıralayıp maini sona atmakda bir çözüm ama bu durumda karışıklıkları oluşabilir örneğin a fonskiyonu b yi b
// fonksiyonu da ayı kendiiçinde çağırabilir bu durumda forward declartion yapmka zorundasın 
// sadece fonksiyonlar değil varabler da forward declara edilebilir
int a(int);
int b(int num);
// iki şekilde de decleara edebilirsin
// sounda sadece ; var unutma 
int c();
// bu şekilde hiç yazmadığın bir fonksiyonu declara edebilirisn hata vermez

int main(){
    std:: cout<<a(3);
    // eğer fonskiyon tanımın int(int int) declation a(int) ve main (int int) olsaydı compile hata verirdi int int li fonksiyon 
    // tanımlanamamış diye çünkü declara ettiğin başka bir fonksiyon
    // eğer fonskiyon tanımın a(int, int) olsaydı ama declation a(int)  ve main içinde a(int) kullansaydın compiler değil linker
    // hata verecekti

    // c();
    // ama çalıştırmaya kalakarsan undefined referance hatası alırsın

}

int a(int num){
    std :: cout << "a worked num: "<<num<<"\n";
    if (num==0) return 0;
    num--;
    b(num);
    return num;
}
int b(int num){
    std :: cout << "b worked num: "<<num<<"\n";
    if (num==0) return 0;
    num--;
    a(num);
    return num;
}
