#include <iostream>
// Preprocessor directive yai önişlemci yönergesi cpp expressionu değildir (bu yüzden ; ile bitmez)
// program çalışmadan yapılcakları anlatır include dosyayı kütüphaneyş ekler, define bul ve değiştir işlemi yapar (#define PI 3.14)
// #pragma once veya #ifndef Bir dosyanın projede yanlışlıkla 2 kere kopyalanıp yapıştırılmasını ve derleme hatası vermesini engeller

int main(){
    // direkt paramtre almaz demek (c de böyle bıraksan belirsi olurdu) o yüzden int main(void) yazman gerekmez
    std:: cout <<"Hello World!";
    // std kütüphane adı :: dosya yolu gibi düşün std içindeki couta ulaşıyoruz
    // c out character out yani ekrana yazı yazdır demek
    // << sola bakan ok gibi dşün sağdaki veriyi (hello world) soldaki ekrana (cout) aktarıyor
    int a,b; // tek satırda tanımlayabilirsin ama çoğu zaman ayrı ayrı yapmak daha iyidir 
    return 0;
    // c++ ve operasyon sistemlernde 0 başarı/sıfırt hata demek 
    // 1: Genel/belirsiz bir hata oluştu., 2: Yanlış komut satırı argümanı girildi. 
    //139: Program hafızada yetkisi olmayan bir yere erişmeye çalıştı (Segmentation Fault)
    // c++11 den sonra return 0 eklemeyi unutsan bile otomatik ekler ama neyin nerde bittiğini göstermek için iyi bir alışkanlık
}