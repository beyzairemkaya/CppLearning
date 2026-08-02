#include "x1.h"
#include <iostream>
// özelden genele import ediyorduk unutma
int main(){
    std::cout<<multiply(8,9);
    return 0;
}

// x1.cpp ile main.cpp yi beraber compile ettiğimizde x1.h ikisinin içine de kod vloğunu kopyalar header quards beraber compile etmeye
// ngel olmaz çünkü önce x1 den x1.o oluştu endif e geldik sonra main içinde aynı olay oldu
// bu yüzden kod bloğonu x1.cpp ye koymalısın bu durumda h ile sadece etiket kopyalanır ki bu da bir soreun değildir 

// peki madem etiketi istediğimiz kadar kopyala yapıştır yapıyoruz o zaman neden headar guarda ihtiyacımız var
// yarın öbürgün kodunun içinde class vs kullanabilirsin içeriği takip etmek yerine ne yazarsan yaz header quard koymak iyi bir alışkanlıktır
/*
struct, class, enum tanımları: Aynı .cpp içine 2 kere kopyalanırsa derleyiciyi BOZAR.
Sonuç: Kafan hiç karışmasın. İster içinde 1 satır bildirim olsun, ister 1000 satır kod; yazdığın her .h dosyasına otomatik olarak 
Header Guard ekleyeceksin.
*/

