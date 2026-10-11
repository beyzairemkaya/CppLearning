#include <iostream>
#include <string>
// std::string[] name_list()


// C++'ta fonksiyonlar doğrudan C-style array döndüremez.
std::string[] name_list(){
    std::cout<<"how many names\n";
    int x;
    std::cin>>x;
    std::string* names  {new std::string[x]};
    for (int i=0;i<x;i++){
        std::cin>>names[i];
    }
    delete[] names;
    return names;
}


int main(){
    // heap de dynamic memory ayırmak için new kullanılır
    // Most often, we’ll assign the return value to our own pointer variable so we can access the allocated memory later.
    int* ptr{ new int }; // dynamically allocate an integer and assign the address to ptr so we can access it later
    *ptr=8;
    int* prt1 {new int {8}}; // bu eşkilde başlatabilirisn
    int* ptr2 {ptr1}; // ptr2 de ptr1 le aynı yeri gösteriyor
    delete ptr1; // prt1 in gösterdiği heap adresini serbest bıraktık ptr1 i silmedk bu yzüden dangling kaldı sşu an,
    ptr1=nullptr; // dangling kalamsın diye nullprtr ye eşitledik
    // ama ptr2 hala dangling onu da nullptr ye eşitlememiz gerek
    ptr2=nullptr;

    int* value { new (std::nothrow) int }; // value will be set to a null pointer if the integer allocation fails
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }
    // heap den memory ayırma sorun olabikir bu şekilde garantiye al

    int* value_list {new[3] int {1,2,3}};
    delete[]value_list;
    // new[x] delete[] kullanamyı unutma

}
/*
void doSomething()
{
    int* ptr{ new int{} };
}
    // silmedik memory leak olur çünkü prty out of the scope olacak ama int heap de bekelemeye devam edecek
    int value = 5;
int* ptr{ new int{} }; // allocate memory
ptr = &value; // old address lost, memory leak results
yine 
*/
// memory leaks olmaması için delate ile silmeliyiz


// std array ı dynamci olarak oluşturmay çalışsanda boyutu compile timede bilmek ister o yüzden dynamic olarak oluşturma heapı boşuna yorma
// std vector vey c style arrayı kullanbaşlirsib
// Çünkü std::array boyutunu template parametresi olarak alır ve bu değer compile-time'da bilinmelidir.

/*
void createArray(int x) {
    int a[x];
}

int main() {
    int n;
    std::cin >> n;

    createArray(n);
}
    çalişmaz çünkü coopile timede oyutuınu bilmrk ister
*/