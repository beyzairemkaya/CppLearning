#include <iostream>
#include <vector>
#include <unordered_set>

void foo(unsigned int){

}
int main(){
    int s {5};
    // [[maybe_unused]] unsigned int u {s}; // compile error list initialization kesin olarak norrawing conversiona karşıdır
    foo(s); // copy  initializatiounun nasıl tepki vereceği derleyiye bağlıdır hata da vereblir işlemi de yapanbilir
    // bizde hata vermedi mesela 

    constexpr int n {5};
    constexpr int n2 {-5};
    // yukarda hata vermesinin sebbei runtime da değer veriliyor(s=5) ama derleyici compile time da değeri bilmediği için ,
    // negatif mi pozitif mi bilemiyor bu yüzden direkt hata veriyor
    // constexpr yapınca compie time da değeri bilebiliyor bu yüzden burda n e hata vermezken n2 ye hata veriyor
    [[maybe_unused]] unsigned int u {n};
    // [[maybe_unused]] unsigned int u2 {n2};

    /*
    C++ standart kütüphanesinde dizi ve vektör indeksleri std::size_t (işaretsiz / unsigned) türündedir; ancak kod yazarken sabit sayıları çoğu 
    zaman doğrudan int (işaretli / signed) olarak yazarız. constexpr sayesinde bu iki tür arasındaki dönüşüm derleyici tarafından hiçbir uyarı 
    veya hata vermeden güvenle kabul edilir.
    */

    // int index {2};
    // Bazı derleyiciler ve sıkı bayraklar (-Wsign-conversion) burada UYARI verir:
    // Çünkü 'index' teorik olarak negatif (-1 gibi) olabilir. 
    // o yüzden en iyisi std::size ve index kullanacakken intleri constexpr yazmak
    // -1 yazıp sondan ulaşma gibi bir durum yok gördüğün gibi çünkü index olarak unsigned alıyor
    constexpr int index {2};
    std::vector<int> v {10,20,30};
    v[index]=50;

    // std::size_t, C++'ta bir nesnenin bellekte kapladığı boyutu (byte cinsinden) veya bir dizinin/vektörün eleman sayısını (indeksini) 
    // tutmak için tasarlanmış özel bir tamsayı türüdür. unsigned long veya unsigned long long kullanır genelde
    std::size_t elemanSayisi = v.size(); // v.size() her zaman std::size_t döner
    // for (std::size_t i = 0; i < v.size(); ++i) {}
    // Güvenli indeksleme tür uyuşmazlığğıı yaşamamak için döngülerde std::sizeT kullanmayı alışkanlık haline getir !!!!

    // signed int döndüren tek length fonksiynu c++20 ile gelen std::ssize
    std::cout<<std::ssize(v)<<"\n";
    // ama int döndürmez ibntten daha büyük olabilir bu yüzden static cast yapman gerekir usually std::ptrdiff_t
    int length { static_cast<int>(std::ssize(v)) };
    // yadda auto kullanırsın 
    auto length2 { (std::ssize(v)) }; 
    // operator[] sınır kontrolü yapmaz ramın o adrsine gider ki bu da undefinied behaviora yol açar
    // std::cout<<v[5]; bizde runtime exception verdi ama rastgale bir adresede gidebilirdi dedğim gibi undefinied behaviour
    // at() operatörü sınır kontrolü yapar
    // std::cout<<v.at(5); bu kesin runtime error verir
    // std::vector dinamikmoldugu için boyutu compile time da bilinemez  u yüzden compile errro vermeemz ikşside

    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << '\n';     // okay: 3 converted from int to std::size_t, not a narrowing conversion

    constexpr int index3 { 3 };         // constexpr
    std::cout << prime[index3] << '\n'; // okay: constexpr index implicitly converted to std::size_t, not a narrowing conversion
    // içine int alamadığını unutma ama constextr int verirsen onun çevrilip çevrilemeyeceğini bilir
    // runtime error lardan kaçınmak için indexi contexpr int olarak tutabilir yada std::size_t static cast yapabilirisin 
    // bir diğer kaçınma yolu ise

    std::vector prime2{ 2, 3, 5, 7, 11 };

    int index2 { 3 };                          // non-constexpr signed value
    std::cout << prime2.data()[index2] << '\n'; // okay: no sign conversion warnings


    // The size() member function and std::size both return size_type.





    /*
    prime.data() çağrısı bir std::vector metodu değildir; vektörün RAM'deki ham verisini tutan ilk elemanın adresini, 
    yani ham bir C tarzı pointer (int*) döner.C dilinden miras kalan pointer indeksleme kuralına göre, bir pointer hem pozitif hem de
    negatif sayılarla indekslenebilir (ptr[3] aslında *(ptr + 3) demektir).Derleyici burada C++ vektör kuralını değil, klasik C pointer 
    aritmetiğini çalıştırdığı için signed int indeks kullanıldığında hiçbir tür dönüşüm uyarısı vermez.Özet Karşılaştırmaprime[index]: C++ 
    nesne çağrısıdır $\rightarrow$ size_t zorunludur $\rightarrow$ int verirseniz uyarı çıkabilir.prime.data()[index]: Ham pointer erişimidir 
    (*(ptr + i)) $\rightarrow$ int ile tam uyumludur $\rightarrow$ Uyarı vermez ama sınır kontrolü (bounds checking) kesinlikle yoktur.
    
    */

         

    


}
/*
Bu metin, C++ standart kütüphanesindeki konteynerlerin (örneğin `std::vector`) boyut ve indeks türü olan **`size_type`** kavramını ve bunun neden var olduğunu açıklıyor.

---

**1. `size_type` Nedir? (Bir Tür Takma Adıdır / Alias)**

`size_type`, her konteyner sınıfının (`std::vector`, `std::string`, `std::set` vb.) kendi içinde tanımladığı **özel bir tür takma adıdır (nested typedef)**.

Konteynerin boyutu (`.size()`) veya indeksleri söz konusu olduğunda kullanılacak veri tipini temsil eder.

* `std::vector<int>::size_type` $\rightarrow$ `std::vector<int>` konteynerinin boyut türü.
* `std::string::size_type` $\rightarrow$ `std::string` metninin uzunluk türü.

---

**2. `size_type` ile `std::size_t` Arasındaki İlişki Nedir?**

Pratikte **`size_type` neredeyse her zaman `std::size_t`'nin aynısıdır.**

* Standart konteynerler bellek ayırmak için varsayılan olarak `std::allocator` kullanır.
* `std::allocator` en fazla `std::size_t` kadar bellek ayırabildiği için, konteynerin `size_type`'ı da otomatik olarak `std::size_t` olarak tanımlanır.
* Çok uç/nadir durumlarda özel bir bellek yöneticisi (custom allocator) yazılmadığı sürece bu ikisi tamamen aynı şeydir.

---

**3. Neden Doğrudan `std::size_t` Demek Yerine `size_type` Diye Bir Şey Uydurdular?**

Bunun sebebi **Genel Programlama (Generic Programming)** ve esnekliktir:

Standart kütüphaneyi tasarlayanlar şunu hedeflemiştir: Yarın bir gün standart dışı, özel bir donanım veya özel bir `allocator` ile çalışan bir konteyner yazılırsa ve onun boyutu `std::size_t` yerine başka bir türe ihtiyaç duyarsa, kodları değiştirmeden o sınıfın kendi `size_type` tanımını kullanabilelim.

---

**4. Kodda Nasıl Görünür?**

Bir vektörün boyutunu en kitabi/standart şekilde saklamak veya döngü kurmak isterseniz sınıfın adı üzerinden erişirsiniz:

```cpp
#include <vector>

int main() {
    std::vector<int> sayilar = {10, 20, 30};

    // 1. En resmi / açık yazım (Konteynerin kendi size_type'ı):
    std::vector<int>::size_type boyut1 = sayilar.size();

    // 2. Pratikte kullanılan eşdeğer yazım:
    std::size_t boyut2 = sayilar.size();

    // 3. Modern C++ yazımı (Türü derleyiciye bırakmak):
    auto boyut3 = sayilar.size(); // auto zaten size_type tipini çıkarır
}

```

Özetle: Dokümantasyonlarda, hata mesajlarında veya uyarılarda `vector<T>::size_type` gördüğünüzde, 
bunun **`std::size_t` ile aynı anlama gelen işaretsiz bir tamsayı türü** olduğunu bilmeniz yeterlidir.
*/