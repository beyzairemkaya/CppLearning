// chars
/*
Codes 0-31 and 127 are called the unprintable chars. These codes were designed to control peripheral devices such as printers 
(e.g. by instructing the printer how to move the print head). Most of these are obsolete now. 
If you try to print these chars, the results are dependent upon your OS (you may get some emoji-like characters).
Codes 32-126 are called the printable characters, and they represent the letters, number characters, and punctuation that most computers use 
to display basic English text.
If you try to print a character whose value is outside the range of ASCII, the results are also dependent upon your OS.
*/
#include <iostream>
int main(){
    char a {'a'};
    char b {98};  // iki şekilde de başlatabilirsin ama ikinci şekil çok önerilmez
    std::cout<<a<<" "<<b<<" "<<"\n";

    char ch {};
    
    std::cout <<"enter a b ";
    std::cin>>ch;
    std::cout<<ch<<"\n";
    std::cin>>ch;
    std::cout<<ch<<"\n";
    std::cin.ignore();
    // en sondaki \n tamponda kalıyordu onu temiledik
    
    // a-b arası boşluk görmezden gelinir eğer onuda karakter olarak saymak istiyorsan std::cin.get() kullan 
    std::cout <<"enter c d \n";
    std::cin.get(ch);
    std::cout<<"You entered: "<<ch<<"\n";
    std::cin.get(ch);
    std::cout<<"You entered: "<<ch<<"\n";

    /*
    
Name	Symbol	Meaning
Alert	\a	Makes an alert, such as a beep
Backspace	\b	Moves the cursor back one space
Formfeed	\f	Moves the cursor to next logical page
Newline	\n	Moves cursor to next line
Carriage return	\r	Moves cursor to beginning of line
Horizontal tab	\t	Prints a horizontal tab
Vertical tab	\v	Prints a vertical tab
Single quote	\’	Prints a single quote
Double quote	\”	Prints a double quote
Backslash	\\	Prints a backslash.
Question mark	\?	Prints a question mark.
No longer relevant. You can use question marks unescaped.
Octal number	\(number)	Translates into char represented by octal
Hex number	\x(number)	Translates into char represented by hex number
    */
/*
`signed char`, **-128 ile 127** arasında değer alabilen negatif işaretli, 8-bitlik (1 byte) çok küçük tam sayıları saklamaya yarar.

Düz `char` harf/metin karakterleri saklamak için kullanılırken, `signed char` matematiksel küçük sayı işlemleri için kullanılır. 
Temel kullanım amaçları:

* **Hafıza Optimizasyonu (Bellek Tasarrufu):**
* RAM kapasitesinin kısıtlı olduğu gömülü sistemlerde veya devasa veri dizilerinde kullanılır.
* Standart bir `int` bellekte 4 byte yer kaplarken, `signed char` sadece 1 byte kaplar. Milyonlarca negatif/pozitif sayı tutan bir dizide %75
bellek tasarrufu sağlar.
* **Örnekler:** Ses sinyallerindeki değişim dalgaları, sıcaklık farkları (-10°C ile +35°C), bir oyunda karakterin anlık aldığı pozitif/negatif 
bonuslar (-5, +10 vb.).


* **Platformlar Arası Çalışma Garantisi (Cross-Platform):**
* C++ standardına göre yalın `char` tipinin varsayılan olarak işaretli (`signed`) mi yoksa işaretsiz (`unsigned`) mi olacağı derleyiciye 
ve işlemci mimarisine bırakılmıştır.
* Örnegin x86 işlemcilerde `char` genellikle `signed` davranırken, bazı ARM işlemcilerde varsayılan olarak `unsigned` davranabilir.
* Negatif sayılarla işlem yaparken kodun her bilgisayarda birebir aynı çalışmasını garanti etmek için explicit olarak `signed char` yazılır.


* **Niyet Belirtme ve Kod Okunabilirliği:**
* `char c = 'A';` $\rightarrow$ Ekrana basılacak metin karakteri.
* `unsigned char b = 200;` $\rightarrow$ Ham ikili veri veya piksel renk değeri (0-255).
* `signed char s = -50;` $\rightarrow$ Negatif değer alabilen küçük tam sayı.



> **Modern C++ İpucu:** Modern C++ projelerinde `signed char` yazmak yerine `<cstdint>` kütüphanesiyle gelen **`int8_t`** türü tercih edilir. 
Arka planda ikisi tamamen aynı şeydir, ancak `int8_t` yazıldığında değişkenin metin değil 8-bitlik bir tam sayı tuttuğu koda bakan kişi tarafından 
daha net anlaşılır.



C++'ta bu üç tür de bellekte 1 byte (8 bit) yer kaplar ama **kullanım amaçları ve niyetleri** tamamen farklıdır:

* **`char`:** Metin ve karakter saklamak içindir (`'A'`, `'z'`, `'\n'`). Ekrana yazdırdığında `std::cout` bunu sayı olarak değil, 
harf/sembol olarak basar.
* **`signed char` (-128 ile 127):** Negatif değer de alabilen çok küçük tam sayıları saklamak içindir.
* **`unsigned char` (0 ile 255):** Sadece pozitif olan küçük tam sayıları veya ham veri bloklarını (pikseller, ses verisi, bayt işlemleri) 
saklamak içindir.

---

**🔍 Arka Plan Mantığı:**

C++ işlemci seviyesinde harf diye bir şey bilmez, her şeyi sayı olarak tutar. Sen `char c = 'A';` yazdığında hafızaya aslında **65** sayısı 
yazılır.

Ancak türe göre derleyicinin ve senin niyetin şöyle ayrılır:

* Türü **`char`** yaparsan: C++ *"Bu bir harftir, ekrana basarken 65 değil 'A' yazayım"* der.
* Türü **`signed/unsigned char`** yaparsan: C++ *"Yazılımcı burada harf değil, küçük bir matematiksel sayı tutmak istiyor"* mesajını alır.

*(Küçük bir C++ ipucu: Modern C++ projelerinde sayı saklamak istendiğinde kafa karışmasın diye `signed char` yerine `<cstdint>` 
kütüphanesindeki **`int8_t`** veya **`uint8_t`** isimleri tercih edilir.)*
*/
/*
Özellik,Tek Tırnak ('a'),"Çift Tırnak (""a"")"
Veri Türü,char,const char[2] (Array / Pointer)
Bellek Boyutu,1 byte,2 byte
İçerik,Tek bir karakter (ASCII 97),Karakter dizisi ('a' ve '\0')
Saklanma Yeri,Doğrudan değer (Stack/Register),Salt okunur bellek bölgesi (Rodata)
*/
    
}