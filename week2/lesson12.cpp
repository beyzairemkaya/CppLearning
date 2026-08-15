#include <iostream>
int main(){
    // C style string literals
    // beyza 6 uzunlukturdadır 5 harf ve sonda null string terminator
    // C style string literals const objelerdir ve programın sonuna kadar val-rlıkalrını sürdürürler
    // ama std::string ve std::string_view temporary onjectler oluşturur ve expression biter bitmez destroy edilirler
    // tabii bir değişkeen atarsan değil mesela 
    std::string s= "Hello";
    // bu scope bitene kadar varlığını sürdürür
    // foo(std::string("Hello")); // "Hello" string'i bu satırın sonunda destroy edilir. bu şekilde anlık kullanılırsa destroy edilir
    // td::string_view bir metni kendi bünyesinde saklamaz, sadece var olan bir metne işaret eden hafif bir "penceredir" (pointer + boyut tutar)
    std::string_view sv = "Hello";
    // Burada sv değişkeninin kendisi scope sonunda silinse bile, baktığı "Hello" yazısı bir C-style literal olduğu için program sonuna kadar 
    // bellekte kalır. Bu yüzden sv hiçbir zaman boşa çıkmaz.
    std::string_view sv = std::string("Hello"); // DANGLES!
    // std::string nesnesi bu satırın sonunda yok edilir.
    // sv artık silinmiş bir belleğe bakmaktadır (Dangling Reference).

    // program yazarken literal olarkak sayıları metinleri kullanmak kötü bir pratiktir mesela her masada max 4 kişi oturdun
    int masaSayisi {7};
    int personNumber {masaSayisi*4};
    // ama yeni sandalye eklenebilir o zaman gidip her 4 ü 5 yapmaya çalışmaktansa şu yaklaşım daha mantıklı
    int maxPerson {4};
    int personNumber2 {masaSayisi*maxPerson};
    // (bu ssayılara magic numbers denir ama dediğim gibi bir exde olabilir örn uygulamanın ismini direkt yazmak yerine deişkende sakla)
    // Avoid magic numbers in your code (use constexpr variables instead, see lesson 5.6 -- Constexpr variables).
}