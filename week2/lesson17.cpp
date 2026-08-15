#include <iostream>
#include <string>
#include <string_view>
void print(std::string_view s){
    std::cout<<s<<"\n";
}
void print2(std::string s){
    std::cout<<s<<"\n";
}
std::string_view hataliFonksiyon() {
    std::string geciciMetin = "Merhaba Dünya";
    return geciciMetin; // 💥 TEHLİKE!
} // 'geciciMetin' bu parantez kapandığı an RAM'den SİLİNİR!
int main(){
    int a {9};
    // 9 değeri a nın içine kopyalanır
    std::string s {"hello world"};
    // veya burda hello world s in içine kopyalnır primative kopyalamak hızlı iken
    // string kopyalamak yavaş bir işlemdir 
    // eğer sadeceokuyacaksak string kullanmak pahalı bir işlemdir onun yerine string_view kullanmalıyız
    // string_view read only dir modifiye edemezsin
    // read-only access to an existing string (a C-style string, a std::string, or another std::string_view) without making a copy

    std::string_view s2 {"beyza"};
    print(s2);
    // şimdi hiç copy oluşmadı 

    // print2(s2);
    // c++ std::string_view in std::string e implicit conversionuna izin vermez
    // ya yeni bir std::string oluşturacaksın yada sttic cast yapacaksın
    std::string s3 {s2};
    print(static_cast<std::string>(s3));
    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex

    using namespace std::string_view_literals;  //bunu unutma
    
    std::cout<<"hi\n"sv;  // sv eki ile string_view yapabiliriz 
    // burda gereksiz tabiikş ama auto kullanımıda gerekli olacak

    // constexpr std::string c17 öncesine kadar desteklenmiyordu bu yüzden onun yerine std::string_view kullanmak daha iyi bir tercih 
    constexpr std::string_view cs {"irem"};
    std::cout<<cs<<"\n";
    // cs compile time da iremle değişir

    std::string_view sv5 = hataliFonksiyon();
    
    // sv şu an silinmiş bir belleğe (çöpe) bakıyor (Dangling View)!
    std::cout << sv5 << '\n'; // ❌ Tanımsız Davranış (Undefined Behavior / Crash)
}




