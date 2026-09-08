// We’ll prefer the term “length” when referring to the number of elements in a container, 
// and use the term “size” to refer to amount of storage required by an object.
// C++ da 3 çeşit array var: C-Style Arrays, std::array, std::vector
// c style arrays lar c ile uyumlu olsun diye tutuluyor ama kullanılması tehlikeli
// std::vector en kullanışlı olanı , std::array ise c style arryuın yerine geçmek için var bazı dururmlarda std::vector den daha verimli

// std::vector javadaki arraylist gibidir boyut tahsil etmezin belleği dinamik oalrak kullanır

#include <vector>
#include <iostream>

int main(){
    std::vector <int> numbers {1,2,3};
    // list initialization yaparken typenı biz belirtebilriz veya
    std::vector smChars {'a','b','c'};
    // C++17’s CTAD (class template argument deduction) compiler type ı belirler
    // std::vector what {};
    // what.push_back(4); bu hali ile olmaz tabii ki
    // elemanlarına [] ile ulaşırız 
    std::cout<< numbers[0]<<"\n";
    // arraylar bellekte ardışık olarak tutulur
    // Ek Yük (Overhead) Yoktur: Bağlı liste (linked list) gibi yapılarda her elemanın yanına "bir sonraki nerede?" diyen ek işaretçiler 
    // (pointer) koymak gerekir. Dizilerde elemanlar zaten yan yana olduğu için sadece verinin kendisi saklanır.
    std::cout<<"Size of one int "<<sizeof(int)<<"\n";
    std::cout<<&numbers[0]<<" "<<&numbers[1]<<" "<<&numbers[2]<<"\n"; // sıralı oldugunu görebilirsin

    // std::vector boyurunu önceden belirleyebilirsin
    std::vector<int> data(3);
    // direkt std::vector <int> data yapsaydın indexle eleman yazamazdın
    // ayrıca boyut belirtmezensendğerleri sürekli kopyalayıp yeni alan açıp ekler burda sıra sıra ekliyor

    for (int i=0;i<5;i++){
        // data.push_back(i); push_back direkt sona ekler içerde de 0 0 0 vardı zaten son hali 0 0 0 0 1 2 3 4 oldu
        // data[i]=i; [] sınır kontrolü yapmadığı için vectörün belleiği çoğaltılmaz dolayısyla undefinied behaviora yol açar
    }
    // ama burda hata vermez sadece ilk üçü direkt yazdı son iki de koppyalayıp yağpıştırma tekniğine gitti
    /*
    When constructing a class type object using a initializer list:
    If the initializer list is empty, the default constructor is preferred over the list constructor.
    If the initializer list is non-empty, a matching list constructor is preferred over other matching constructors.
    
    */
   std::vector<int> ls1 {10}; // tek elemanlı oda 10 , (10 tane 0 değil)
   std::cout<<ls1[0]<<"\n";
   // If a class does not have a list constructor but then one is added later, this will change which constructor is called 
   // for all objects initialized using a non-empty initializer list.
   // list initialization diğer initializaonlara karşı baskındır çünkü

   // Copy init
   // std::vector<int> v1 = 10;     // 10 not an initializer list, copy init won't match explicit constructor: compilation error
   // Direct init
   std::vector<int> v2(10);      // 10 not an initializer list, matches explicit single-argument constructor
   
   // List init
   std::vector<int> v3{ 10 };    // { 10 } interpreted as initializer list, matches list constructor
   
   // Copy list init
   std::vector<int> v4 = { 10 }; // { 10 } interpreted as initializer list, matches list constructor
   std::vector<int> v5({ 10 });  // { 10 } interpreted as initializer list, matches list constructor

    // Default init
    std::vector<int> v6 {};       // {} is empty initializer list, matches default constructor
    std::vector<int> v7 = {};     // {} is empty initializer list, matches default constructor
    // std::cin>> arr[0]>>arr[1]>>arr[2]; // bu şekilde tek cinde atama yapabilirisn 3 tane değer ister

}