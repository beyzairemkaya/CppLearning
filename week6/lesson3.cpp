#include <iostream>

#include <iostream>

// POINTER (Yeni bir kumanda kopyalandı)
void pointerOrnegi(int* kumanda) {
    *kumanda = 50;       // TV'nin kanalını değiştirdi (Orijinal değişir!)
    kumanda = nullptr;   // Kendi elindeki kumandayı çöpe attı.
                         // Orijinal main'deki kumandaya BİR ŞEY OLMAZ!
}

// REFERANS (Kumanda yok, TV'ye takma isim verildi)
void referansOrnegi(int& tv) {
    tv = 100;            // Doğrudan TV'ye dokunuyor (Orijinal değişir!)
    // tv'yi "başka bir değişkene" yönlendirme şansın bile yoktur,
    // çünkü tv artık o değişkenin kendisidir.
    // burda değerin kendisini kopyalmadığımızn için inexpendsive dir
}
void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main() {
    int asilTv = 10;

    int* kumanda1 = &asilTv;
    pointerOrnegi(kumanda1); 
    // asilTv artık 50 oldu. kumanda1 hala asilTv'yi gösteriyor.

    referansOrnegi(asilTv);  
    // asilTv artık 100 oldu.

    int x { 5 };
    std::cout << "The address of x is: " << &x << '\n';
    printAddresses(x, x);
    // pass by referance yaptıgında orijinal değeri değiştridiğini unutma değiştrmek istemiyosan pass by vcalue yapmalısn !!!
}
/*
#include <iostream>

void printValue(int& y) // y only accepts modifiable lvalues
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
}
*/