#include <iostream>
#include <array>
#include <vector>

// std::vector boyutu değişebilir boyutu runtime’da değişebilir 
// std::array ise sabittir boyutu compile-time’da sabit
// std::array, normal C-style array gibi elemanları doğrudan kendi içinde tutar. std::vector ise elemanlarını genellikle heap'te dinamik olarak 
// ayırdığı bellekte tutar ve içeride kabaca pointer + size + capacity bilgileri taşır.


void printElementZero(int arr[1000]) // doesn't make a copy
{
    std::cout << arr[2]; // print the value of the first element
    // int arr[1000];
    // bunu paramterte olarak verdiğinde fonksiyona boyut bilgisi kayboluyor sadece başlangıç adresi tutuluyor
    // int* arr buna dönüşüyor
    // C’nin eski tasarımından gelen bir kural var: fonksiyon parametresinde bir C-style array yazdığında, compiler onu otomatik olarak 
    // pointer parametresine “adjust” ediyor.
    /*
    void f(int arr[10]);
    void f(int arr[100]);
    void f(int* arr);
    function overloading yapaamzsın dikkat et!!!!

    Ama array’i reference olarak alırsan boyut tipin parçası olur:
void f(int (&arr)[3]) {
    std::cout << "3\n";
}

void f(int (&arr)[4]) {
    std::cout << "4\n";
}
    böyle overlaiding yapabilirisn

    Eğer boyutu da korumak istiyorsan C++’ta referansla alabilirsin:
    void f(int (&arr)[7])
    */
   int arr2[7];
   int* p = arr2;
   // böylede uunluk bilgisi gitmiş yani decay etmiş oldu ama dıkkat
   //arr 2 in tye pı int[7]  p ninki int*

   

}

void printElementZero2(const int arr[]) // treated the same as const int*
{
    std::cout << arr[88];
    // bu da derlenir sadece code rewieve muhtemelen bir aarray bekliyorum ipucusunu vermiş oldun yoksa bu da poinytere dönüşüyor yani
}

int main(){
    std::array<int, 3> arr{1, 2, 3};
    // std::cout<<arr[3];
    // hata vermez undefinied behaviora çıkar arrayda out of index olmak
    // std::array::operator[] sınır kontrolü yapmaz.
    std::array<int, 5> a;   // Members default initialized (int elements are left uninitialized)
    std::array<int, 5> b{}; // Members value initialized (int elements are zero initialized) (preferred)

    std::vector<int> v(5);  // Members value initialized (int elements are zero initialized) (for comparison)

    // std::array<int,3> c {1,2,2,2};
    // bu hata verir ama
    std::array<int,3> c {1};
    std::cout<<c[0]<<c[1]<<c[2]<<"\n";
    // hata vermez value initialzed başlatır 00 olur geişris

    // pointer’ı “arraymiş gibi” indexleyebiliyoruz çünkü C/C++’ta [] operatörü pointer arithmetic üzerinden tanımlı.
    int arr3[4] {1,2,3,4};
    int* ptr3 {arr3};
    std::cout<<ptr3[3]<<"\n";
    // çünkü bunu *(ptr3+3) olarak okur
    int x {6};
    printElementZero(&x);
    // bak bu hali ile undefinied behavior oldu çünkü fonskiyon paramteresi int* bizde ona normal bir int verebildik

    printElementZero2(&x);

    

}
/*
n C++, arrays can be passed by reference, in which case the array argument won’t decay when passed to a function (but the reference to the 
array will still decay when evaluated). However, it’s easy to forget to apply this consistently, and one missed reference will lead to decaying
arguments. Also, array reference parameters must have a fixed length, meaning the function can only handle arrays of one particular length. 
If we want a function that can handle arrays of different lengths, then we also have to use function templates. But if you’re going to do both 
of those things to “fix” C-style arrays, then you might as well just use std::array!
*/
    
