#include <iostream>
#include <string>
#include <string_view>

int nm5(){
    int a=5;
    return a;
    // fonksiyon a yerine 5 değerini kopyalar ve çağıran yere aktarır
}
std::string_view strA(){
    std::string s {"Akvmf"};
    return s;
}
std::string_view strA2()
{
    return "strA2 runned";
}
std::string getName()
{
    std::string s { "Alex" };
    return s;
}
std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
    if (s1 < s2)
        return s1;
    return s2;
}



int main(){
    int b=nm5();
    // 5 değeri b ye aktarılır a {} kapandığı an silinmişti ve bu b yi alakadar etmez 
    // std::string str=strA();
    // std::string_viewi std::stringe direkt dönüştüremeyeceğin hatırla
    std::string_view str=strA();
    std::cout<<str<<"\n";
    //  burda std::stringview in içinde kalan tek bilgi son pointer ve kaç adım okuyacağın o yüzden işaret ettiğüi pointıra gidiyor
    // ama s {} btmesiyles silindi doğal olarak çöp veriyi okuyor

    std::string_view name { getName() }; // name initialized with return value of function
    std::cout << name << '\n'; // undefined behavior
    // bak burdada name içinde getnameden dönen ismin pointırı ve uzunlluğu var sen sprna get name in return ettiği değeri
    // kaydetmediğin için tekrar okumaya çalıştığında yine crushla karşılacakısn 
    // get name in return değereini kaydetseydin sorun olmauacaktı
    std::string name2=getName();
    std::string_view name3 {name2};
    std::cout<<name3<<"\n";

    using namespace std::string_literals;
    std::string_view name4 { "beyza"s }; // "beyza"s creates a temporary std::string
    std::cout << name4 << '\n'; // undefined behavior
    // burdada yine hafızanın gösterdiği yeri tutuyor ama hafızakdaki obje silindi

    // YAPMA
    using namespace std::string_literals;
    // ❌ HATA / UNDEFINED BEHAVIOR:
    std::string_view svx { "Alex"s };
    // Sonundaki s eki yüzünden derleyici arka planda geçici bir std::string nesnesi yaratır. 
    // Satır bittiğinde (; işaretinde) o geçici nesne RAM'den silinir. sv ise silinmiş bir belleğe bakarak ortada kalır (dangling view).

    // ✅ TAMAMEN GÜVENLİ:
    std::string_view svx2 { "Alex" };

    using namespace std::string_view_literals;
    // ✅ TAMAMEN GÜVENLİ:
    std::string_view sv { "Alex"sv };
    // Arka planda geçici bir std::string yaratmaz, doğrudan kalıcı metne bakan bir görünüm oluşturur.

    // ilk durumda bir std::string nesnesi yaratiyorsun ki bununda ömrü {} kapandığında biter doğal olarak 
    // dışındaki string viewin bakcak bir şeyi kalmıyor

    // ama ikinci durumda string literal kullanıyorsun string litearlların ömrü program sonlana kadardır bu yüzden sring view herzaman görür

    // üçüncüde alex literal "Alex"sv'nin kendisi de aslında bir string_view değeridir.

    /*
    Do not initialize a std::string_view with a std::string literal, as this will leave the std::string_view dangling.
    It is okay to initialize a std::string_view with a C-style string literal or a std::string_view literal. 
    It’s also okay to initialize a std::string_view with a C-style string object, a std::string object, or a std::string_view object, 
    as long as that string object outlives the view.
    */
   std::string ab {"beyza"};
   std::string_view ba {ab};
   ab="iremirem kaya haha"; // undefinied bhavior
   std::cout<<ba<<"end \n";
   // string_view in baktığı stringi değiştirisen stringview undefined behaviora girers
   // bu durum invalidate olmak denir
   // revalidate etmek için tekardan eşitlrsin
   ba=ab;
   std::cout<<ba<<"\n";



   std::string alex=getName();
   std::cout<<alex<<"\n";
   // bu çalıştı çünkü {} kapanmadan değeri sakladı
   std::string_view alex3= getName();
   std::cout<<alex3<<"\n";
   // bu undefinied behavior çünkü değeri değil değerin başlangıç bitişini kaydetti


   std::cout<<strA()<<"  "<<strA2()<<"\n";
   // strA  undefined behavior çünkü std::sring {} sonunda silindi string viewin bakacak nokatası kalamdı ama string litaraller
   //program sonuan kadar yaşadığı için 

   std::cout<<firstAlphabetical("beyza","irem")<<"\n";
   // döndrülen stringview parametree ise unefnied behavior olmaz lştearl program sı-ouna kadar var
   // Fonksiyon çağrılırken üretilen geçici std::string nesneleri satır sonunda (;) silinir:
   std::string_view sv8 = firstAlphabetical(std::string{"beyza"}, std::string{"irem"}); 
   // std::string nesneleri az önce silindi!
   std::cout << sv8<<"\n"; // 💥 Undefined Behavior!

   // MOddify optionlarla nesneyi değiştiremezekde ne göreceğimizi değiştirebilirz
   std::string_view apple {"apple"};
   apple.remove_prefix(1);
   std::cout<<apple<<"\n";
   apple.remove_suffix(2);
   std::cout<<apple<<"\n";
   // objeyi direkt etkiliyor unutma geri dönmek için yeniden atamalısın
   apple="apple";

   /*
   2. std::string_view Neden Null Karakterle Bitmeyebilir?
std::string_view bir metnin sadece ortasındaki bir parçayı (alt dize / substring) kesip gösterebilir:

Eğer std::string_view, "snowball" kelimesinin sadece ortasındaki "now" kısmına bakıyorsa:

Başlangıç: 'n' harfinin adresi

Uzunluk: 3 karakter ('n', 'o', 'w')

'w' harfinden hemen sonra gelen karakter \0 değil, 'b' harfidir!

Dolayısıyla bu std::string_view null-terminated DEĞİLDİR.

3. Bu Neden Genellikle Sorun Olmaz?
std::string_view, metnin nerede bittiğini anlamak için \0 karakterine bakmaz. Elinde zaten "Uzunluk = 3" bilgisi olduğu için sadece 3 harf okur 
ve durur. std::cout da bunu bildiği için ekrana sadece "now" basar.
4. Asıl Tehlike Nerede Başlar? (Eski C Fonksiyonları)
Eski C kütüphaneleri (örneğin strlen, printf, strcpy) metin uzunluğunu bilmez; bellekte \0 görene kadar durmadan okumaya devam eder.

C++
std::string_view sv = "snowball";
sv.remove_prefix(1); // baştan 's'yi at
sv.remove_suffix(4); // sondan 'ball'u at -> Artık sadece "now" görüyor

// 1. C++ Tarzı (Güvenli):
std::cout << sv; // "now" yazar (çünkü uzunluğu 3 biliyor)

// 2. C Tarzı .data() ile (TEHLİKELİ!):
// printf, \0 görene kadar okur; "nowball" yazar ve saçmalar!
printf("%s\n", sv.data());
Eğer std::string_view içindeki bir veriyi \0 ile bitmesini şart koşan eski bir C fonksiyonuna göndermen gerekiyorsa, onu önce std::string'e dönüştürmelisin:C++std::string guvenliString{ sv }; // Otomatik olarak sonuna '\0' ekler
printf("%s\n", guvenliString.c_str()); // ✅ Güvenle "now" yazar

   */


   

   



}