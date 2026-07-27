#include <iostream>

int main(){
    std::cout<< "start point"<<"\n";
    // statrt pointi couta yönlendirdik metin konsola yazdırılacak
    int age {};
    // direct list initialization ile balatma alıoşkanlığını edin
    std::cin >> age;

    // cin character input demek
    // konsoldan alınan veri age a yazdırılacak
    /*
    Bilgisayarlar ekrana yazı yazarken performans kazanmak için verileri önce RAM'de küçük bir "bekleme odasında" (buffer) toplar. 
    Bu bekleme odası dolunca veya program bitince verilerin hepsini tek seferde ekrana basar.
    \n kullanmak: Kamyona kolileri yüklemek ama kamyon dolana kadar beklemektir (Çok daha hızlıdır).
    std::endl kullanmak: Her koli yüklendiğinde kamyonu boş bile olsa gideceği yere gönderip geri çağırmaktır (Sistemi yavaşlatır).
    std::endl ancak verinin o anda kesinlikle ekrana basıldığından emin olmak istediğin özel durumlarda kullanılır:
    Hata Yakalama / Debugging: Programın bir sonraki satırda çökme ihtimali varsa, o ana kadarki çıktıların ekranda göründüğünden emin olmak için.
    Kullanıcı Etkileşimi: Kullanıcıdan bir girdi istemeden hemen önce çıktının ekranda belirmesini garantiye almak için.
    Eğitim materyallerinde başlangıçta alışkanlık olsun diye std::endl öğretilir. Ancak standart bir kod yazarken alışkanlığını 
    '\n' veya "\n" olarak değiştirmek performans açısından en iyi yöntemdir.
    */
   /*
   To output a newline without flushing the output buffer, we use \n (inside either single or double quotes),
    which is a special symbol that the compiler interprets as a newline character. \n moves the cursor to the next line of the 
    console without causing a flush, so it will typically perform better. \n is also more concise to type and can be embedded 
    into existing double-quoted text.
    */
   /*
   Ne Zaman \n Ekrana Düşmez? (Çökme Senaryosu)
Kodunun adım adım nerede patladığını bulmaya çalıştığın bir hata arama (debugging) senaryosu düşün:

C++
#include <iostream>

int main() {
    std::cout << "1. Adım tamamlandı\n"; // \n koyduk!
    
    int x = 5 / 0; // AAAAA! Sıfıra bölme hatası -> PROGRAM ANINDA ÇÖKTÜ!
    
    return 0;
}
Bu kod çalıştığında ne olur?

Program "1. Adım tamamlandı\n" yazısını hazırlar ve RAM'deki bekleme salonuna koyar.

Tam o yazıyı ekrana basamadan bir alt satırdaki 5 / 0 hatası yüzünden program patlar ve kapanır.

Ekrana bakarsın: Ekranda HİÇBİR ŞEY yoktur!

Sen dersin ki: "Herhalde program 1. adıma bile gelemeden çöktü."

Ama aslında kod 1. adıma gelmişti! Sadece \n yazıyı bekleme salonunda tuttuğu ve ekrana basmaya vakit bulamadan program çöktüğü için sen o yazıyı hiç göremedin.

std::endl Burada Ne Yapar?
Eğer aynı koda \n yerine std::endl koysaydın:

C++
std::cout << "1. Adım tamamlandı" << std::endl; 
int x = 5 / 0; // Program yine çökecek...
std::endl yazıyı hazırlar, alt satıra geçer ve derhal std::flush komutunu çalıştırır.

Bu komut işletim sisteminin yakasından yapışır: "Bekleme salonundaki her şeyi DERHAL ekrana bas!"

Yazı anında ekranda belirir.

Bir alt satırda program çökse bile sen ekranda "1. Adım tamamlandı" yazısını görürsün ve "Hah, demek ki problem 1. adımdan 
sonraki satırda!" dersin.*/


// bazen debugging yaparken araya printler atıyorsun nerde tükendiğini görmek için bunu std::endline ile yapmayı unutma

// bit kaydırma
int x {8};
int lastX= x>> 1;
// 1 bit lkaydırır 1000 0100 olur onuç 4 olur.
std::cout << lastX;

/*
. "Multicharacter Literal" (En Tehlikeli C++ Tuzağı)
Tek tırnak (' ') C++'ta sadece tek bir karakter (char) tutmak içindir.

Eğer dalgınlıkla iki defa alt satıra geçmek isteyip tek tırnağın içine iki karakter yazarsan ('\n\n'), C++ derleyicisi hata vermez ama çıldırtıcı bir hata (bug) üretir!

Ne Demek İstiyoruz? (Kod Örneği)
C++
// Yanlışlıkla iki tane \n koyduk:
std::cout << '\n\n'; 
Burada C++ iki kez alt satıra geçmek yerine ekrana 2573 gibi garip bir sayı basar!

Neden?

Çünkü C++ tek tırnak içine birden fazla karakter yazıldığında buna Multicharacter Literal der ve o karakterlerin ASCII kodlarını birleştirip arka planda bir tamsayıya (integer) dönüştürür.

Ama çift tırnak kullansaydın:

C++
std::cout << "\n\n"; // Harika! Düzgünce iki alt satıra geçer.
Çift tırnak bir metin (string) belirttiği için içine kaç tane \n yazarsan yaz sorunsuz çalışır.*/


return 0;
}