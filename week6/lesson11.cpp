std::string& getRef(std::string& x){
    return x;
}
int main()
{
    const double a { 7.8 }; // a has type const double
    auto b { a };           // b has type double (const dropped)

    constexpr double c { 7.8 }; // c has type const double (constexpr implicitly applies const)
    auto d { c };               // d has type double (const dropped)

    const double* const p2 { &a };  // sağdaki const: p2'nin kendisi, soldaki: gösterdiği şey
    auto r { p2 };                   // r: const double*  -> sağdaki düştü, soldaki kaldı
    const double* m1 {p2}; // m1 pointri başka nesenye bağlanabilir ama o nesne değiştirilemez pointer üzerinden 

    // atnı const düşmesi gibi refranca da düşer
    auto ref1 { getRef() };  // std::string (reference dropped)
    auto& ref2 { getRef() }; // std::string& (reference dropped, reference reapplied)
    const int x;    // this const applies to x, so it is top-level
    int* const ptr; // this const applies to ptr, so it is top-level
    // references don't have a top-level const syntax, as they are implicitly top-level const
    const int& ref; // this const applies to the object being referenced, so it is low-level
    const int* ptr; // this const applies to the object being pointed to, so it is low-level
    


    return 0;
}
/*
Atayabilirsin. Değerle const döndüren bir fonksiyonun sonucu da sonuçta kopyalanıyor:

cpp
const int getValue() { return 5; }

int x { getValue() };    // geçerli, x: int
auto y { getValue() };   // y: int
x = 10;                  // sorun yok

Hatta temel tiplerde (int, double vb.) değerle const döndürmenin hiçbir etkisi yok. Derleyici o const'u yok sayar, 
bazıları uyarı bile verir. Sınıf tiplerinde (const std::string f() gibi) ise zararlı: dönen değer const olduğu için move edilemez, mecburen 
kopyalanır. Bu yüzden değerle dönüşte const kullanılmaz.
*/
/*
We can reapply a reference and/or const:

#include <string>

const std::string& getConstRef(); // some function that returns a const reference

int main()
{
    auto ref1{ getConstRef() };        // std::string (reference and top-level const dropped)
    const auto ref2{ getConstRef() };  // const std::string (reference dropped, const dropped, const reapplied)

    auto& ref3{ getConstRef() };       // const std::string& (reference dropped and reapplied, low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped)

    return 0;
}
*/
/*
auto x   // kopya alıyor → const olmak zorunda değil
auto& x  // aynı nesneye bağlanıyor → o nesnenin constluğuna uymak zorunda
çünkü x const olsun const nesneye const olmayan refrans bağlayamayız
auto& ref3 = getConstRef();
const std::string& ref3 = getConstRef();
*/
/*
Constexpr is not part of an expression’s type, so it is not deduced by auto.

A reminder

When defining a const reference (e.g. const int&), the const applies to the object being referenced, not the reference itself.

When defining a constexpr reference to a const variable (e.g. constexpr const int&), we need to apply both constexpr (which applies to the reference) and const (which applies to the type being referenced).

This is covered in lesson 12.4 -- Lvalue references to const.
#include <string_view>
#include <iostream>

constexpr std::string_view hello { "Hello" };   // implicitly const

constexpr const std::string_view& getConstRef() // function is constexpr, returns a const std::string_view&
{
    return hello;
}

int main()
{
    auto ref1{ getConstRef() };                  // std::string_view (reference dropped and top-level const dropped)
    constexpr auto ref2{ getConstRef() };        // constexpr const std::string_view (reference dropped and top-level const dropped, constexpr applied, implicitly const)

    auto& ref3{ getConstRef() };                 // const std::string_view& (reference reapplied, low-level const not dropped)
    constexpr const auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)

    return 0;
}




#include <string>

std::string* getPtr(); // some function that returns a pointer

int main()
{
    auto ptr1{ getPtr() }; // std::string*

    return 0;
}
    Unlike references, type deduction does not drop pointers:
*/

/*
Özetle metin şunu söylüyor: **`auto` ile `auto*` çoğu zaman aynı işi yapar ama `auto*` kullanmak bir nevi "buraya mutlaka pointer (işaretçi) gelmek zorunda" kuralı koymaktır.**

Kafayı karıştıran teknik ayrıntıları kenara bırakıp mantığı 2 maddede netleştirelim:

### 1. `auto` her şeyi içine yutar, `auto*` ise açıkça pointer bekler

* **`auto p = getPtr();`**
Derleyici sağ tarafa bakar; sağ taraf bir `std::string*` (pointer) ise `auto` doğrudan `std::string*` olur. Ne gelirse ona dönüşür.
* **`auto* p = getPtr();`**
Buradaki `auto` sadece türü (`std::string`) tahmin eder, yanındaki `*` işaretini sonradan kendisi ekler. Sonuç yine `std::string*` olur.

**Fark nerede ortaya çıkıyor?**

Sağ tarafa yanlışlıkla pointer *olmayan* normal bir değer verdiğinde:

```cpp
auto  a = *getPtr(); // ÇALIŞIR: Değeri dereference ettin (*), elinde normal std::string var. 'auto' da std::string olur.
auto* b = *getPtr(); // HATA VERİR: Sen açıkça "bu bir pointer olmalı (*)" dedin, ama sağ taraf normal string!

```

Yani `auto*` kullandığında derleyiciye şunu demiş oluyorsun: *"Sağdaki ifadenin bir pointer olduğundan eminim, eğer pointer değilse beni hemen uyar (derleme hatası ver)."* Bu da kodun okunabilirliğini artırır ve dikkatsizlik kaynaklı hataları önler.

---

### 2. `const` devreye girince ne değişir?

Metnin sonunda bahsettiği ikinci fark `const` durumudur:

* **Pointer'ın kendisi mi sabit, gösterdiği yer mi sabit?**
* `const auto p = getPtr();`
`auto` pointer'ı yuttuğu için `const` doğrudan pointer'ın kendisine yapışır: **Pointer sabittir**, başka bir adresi gösteremez (`std::string* const`).
* `const auto* p = getPtr();`
Burada `const`, `*` işaretinin solundadır. Dolayısıyla **gösterilen veri sabittir**, yani veriyi değiştiremezsin (`const std::string*`).



Kısacası: Kodunun pointer beklediğini hem kendine hem derleyiciye açıkça belli etmek ve `const` kurallarını şaşırmamak için bazen `auto` yerine `auto*` yazmak tercih edilir.
*/