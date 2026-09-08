#include <algorithm> // for std::max
#include <cmath>     // for std::abs
#include <iostream>

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
    // std::abs mutlak değer fonksiyonu 
}
/*
Sabit Epsilon (abs(a - b) <= epsilon) Neden Yetersizdir?Sabit bir hata payı belirlediğinde (örneğin $\text{epsilon} = 0.00001$):
Çok büyük sayılarda: $100{,}000{,}000.0$ ile $100{,}000{,}000.1$ sayıları arasındaki fark $0.1$'dir. Bu fark $0.00001$'den büyük olduğu için 
sabit epsilon bunları "farklı" ilan eder; oysa 100 milyonda 0.1'lik fark sadece önemsiz bir yuvarlama tozudur.Çok küçük sayılarda: $0.00001$ 
ile $0.00002$ arasındaki fark $0.00001$'dir. Sabit epsilon bunları "eşit" ilan eder; oysa biri diğerinin tam 2 katıdır (%100 hata vardır).

Diyelim ki a = 1000.0, b = 1000.5 ve relEpsilon = 0.001 (Binde 1 hata payı):Sol taraf (Gerçek Fark): $\vert{}1000.0 - 1000.5\vert{} = ,
\mathbf{0.5}$Sağ taraf (İzin Verilen Limit): $1000.5 \times 0.001 = \mathbf{1.0005}$Karşılaştırma: $0.5 \le 1.0005$ $\rightarrow$ true 
(Fark kabul edilebilir binde 1 sınırının içinde kaldığı için sayılar eşit sayılır).Kısacası: relEpsilon ile çarpmak, tolerans cetvelini sayıların 
boyutuna göre otomatik olarak büyütüp küçültür.
*/
// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int findmax(int x,int y){
    // ?: tenary operatör (3 operand) doğru ise 1.stament değilse 2.
    int max {};
    max=((x>y)? x:y);
    return max;
}



int main(){
    // cpp de üs alma cmath kütüphanesindeki powla yapılır
    double z {std::pow(3.0,4.0)};
    // pow double parmtre alır ve double döndürü int li versiyonunu istiyorsan kendin yazmalısın
    /*
    Prefix increment (pre-increment)	++	++x	Increment x, then return x
    Prefix decrement (pre-decrement)	––	––x	Decrement x, then return x
    Postfix increment (post-increment)	++	x++	Copy x, then increment x, then return the copy
    Postfix decrement (post-decrement)	––	x––	Copy x, then decrement x, then return the copy
    */
   int x{5};
   int y=++x;
   std::cout<<x<<" "<<y<<"\n";
   // x in değişeceğini gözden kaçırma
   int m=x--;
   std::cout<<x<<" "<<m<<"\n";
   std::cout<<++x<<x<<x++<<x<<"\n";
   // 1.si artrırıp döndürdü üçünsüüs ise değeri kopyaladı artrdı kopyaladığı değeri döndürdü
   // For example, the expression x + ++x is unspecified behavior. When x is initialized to 1, Visual Studio and GCC evaluate 
   // this as 2 + 2, and Clang evaluates it as 1 + 2! 
   // This is due to differences in when the compilers apply the side effect of incrementing x.
   

   // comma operatör 
   // x,y =) önce x i sonra y değerlendir y nin değerini döndür demek

   int nm {8};
   int nm2 {3};
   std::cout<<(nm++,nm2++)<<"\n"; // önce nm2 değeğrini kopyladı çünkü
   std::cout<<nm<<" "<<nm2<<"\n";
   // Note that comma has the lowest precedence of all the operators, even lower than assignment. 
   // Because of this, the following two lines of code do different things:
   z = (--nm, --nm2); // evaluate (a, b) first to get result of b, then assign that value to variable z.
   z = --nm, --nm2; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.
   std::cout<<nm<<" "<<nm2<<"\n";
   // comma operatürünü kullanmaktansa ayrı statemntler olarak geçmek daha iyi bu yüzden 

   std::cout<<findmax(5,10)<<"\n";

    constexpr bool inBigClassroom2 { false };
    constexpr int classSize2 { inBigClassroom2 ? 30 : 20 };
    std::cout << "The class size is: " << classSize2 <<  '\n';// sorun yok

    constexpr bool inBigClassroom { false };

    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };

    // std::cout << "The class size is: " << classSize << '\n'; // Compile error: classSize not defined
    //if else blokları içindede scope dışı oldugunu unuma ama the ternary operatör ile scope dışı olmadı

    int xa { 0 };
    int ya { 1 };
    int za { 10 - x > y ? x : y };
    std::cout << za<<"\n";
    // (10 - xa) > ya ? xa : ya olarak dğerlendir ezberleme parantez kullan

    int o { 2 };
    std::cout << (o < 0) ? "negative" : "non-negative";
    // 0<0 false döner daha sonra << ?: e üstün oldugu için false in int değeri olan 0 yazdırlır bu yyüzden parantez kullanmayı iyi
    // bir alışkanlık haline getir
    /*
    Here’s what’s happening in the above example. First, x < 0 evaluates to false. The partially evaluated expression is now std::cout << false ? 
    "negative" : "non-negative". Because operator<< has higher precedence than operator?:, this expression evaluates as if it were written as 
    (std::cout << false) ? "negative" : "non-negative". Thus std::cout << false is evaluated, which prints 0 (and returns std::cout).
    The partially evaluated expression is now std::cout ? "negative" : "non-negative". Since std::cout is all that is remaining in the condition, t
    he compiler will try to convert it to a bool so the condition can be resolved. Perhaps surprisingly, std::cout has a defined conversion to 
    bool, which will most likely return false. Assuming it returns false, we now have false ? "negative" : "non-negative", which evaluates to 
    "non-negative". So our fully evaluated statement is "non-negative";. An expression statement that is just a literal (in this case, a string 
    literal) has no effect, so we’re done.
    */

    // operatörlerin operandlarının typleri eşleşmeli 
    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int
    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double
    std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range
    // std::cout << ((x != 5) ? x : "x is 5"); // compile error: compiler can't find common type for constexpr int and C-style string literal

    // floating sayılarla karşılaştırma yaparken precise hataları olabilir ama aynı iki sayıyı karşılaştırsan olmaz şunu demye çalışıyorjm
    double gravity {9.8};
    bool f1 (gravity==9.8); // true
    bool f2 (5.0+4.8==9.8);// true yada false çıkabilir ama emin olma
    // $5.0 + 4.8$ işleminin sonucu IEEE 754 64-bit donanımında şans eseri $9.8$ ile aynı bit dizilimine denk gelse bile, 
    // farklı derleyici optimizasyonlarında (örneğin 80-bit x87 FPU kayıtları veya FMA yönergelerinde) ara basamak yuvarlama farkı oluşabilir.
    // Sonuç: Çoğu modern sistemde $1$ (true) çıksa da bu bir şans ve derleyici optimizasyonu sonucudur; asla güvenilmez
    bool f3 (gravity==9.8f);// false
    std::cout<<f1<<" "<<f2<<" "<<f3<<"\n";
    // ama f1in doğru olması için min precison aşammak gerek floatta 6 double da 15
    // float karşılaştırmak için fzrkları epsilondan küçük mü diye kontrol ederiz

    double r {1e-4} // 10^-4 anlamına gelir

    if (x == 1 && ++y == 2) std::cout<<"hi";
    // x!= 1 oldugub için kısa devre olur y hiç artırılmaz unutma

    // y da true || false short circut

    // && || birlikte kullanırken and daha önceiği oldyugunu unutma en iyisi karıştırmamamk için parantez kullana kullanan gitmek

    // c++ da logical XOR yok ama (bit XOR ile karıştırma) ama != aynı işi yapar zaten eşit değilse true döndürürü
    // and or da yaabilirsin ama operatörleri kullanmak aha iyi

   



}