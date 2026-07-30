// input-output işlemleri
#include <iostream>

int main(){
    int x {};
    int y{};
    std::cin >> x >> y;
    // bu şekilde tek seferde birden fazla karakter alabilirsin
    int z{};
    char k{};
    std::cin >>z >>k;
    // beklenilen tipte veri vermezsen std::cin kilitkenir çalışmayı durdurur ve direkt alt satıra geçer
    std::cout << "bu satir yinede calisti"<<"\n";
    std::cout << x<<"\n";
    // 0 yazdırır
    // std cout and std cin is buffered. so they follow the principe first in first out

    // eğer 4 5 7 k girersen ilk inputa x 4 y 5 z 7 k k olur tekrardan input istemez

    // std::cin çalışacağı zaman öncelikle durumuna bakar eğer daha önceden std::cin kilitlenmişse çalışmayı reddeder
    // ikinci olarak başında duran \n ve boşlukları tabları temizler
    // tampon boşsa kullanıcıyı bekler
    // Bir '\n' (Enter) görünceye VEYA hedef değişken için geçersiz bir karakter görünceye kadar okumaya devam eder.
    // Okunmayan tüm karakterler (okumayı bozan hatalı harf veya satır sonundaki '\n') tampon bellekte kalmaya devam eder. 
    // std::cin temizlense bile o karakterler bir sonraki okuma işlemine kadar tamponda bekler.
    // mesela 5a girersen 5 x e atanır a bufferda kalır
    /*
    std::cout << "Bekle..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    mesela burda std::endl kull-anamsan bekle yazısı bufferda kalıp gözükmeyebilir veya
    for (int i = 0; i < 1000000; i++)
    std::cout << i << '\n';
    burda toplu yazma yapılır hepsi bufferda bakeldikten sonra 
    for (int i = 0; i < 1000000; i++)
    std::cout << i << std::endl;
    burda sırayla yazdırlırl çünkü flush() çağrılır*/
    int m{};
    char n {};
    std::cin >> m >>n;
    std::cout << m <<n<<"\n";
    // 1n girsen kabul eder yan

    // x e 7.4 girersen x =7 olur ama buffere .4 takılı kalır bu yzüden std::cin kilitlenir
    // x e çok büyük bir sayı girersen en az 3 milyon 2147483647 gibi bir syı alırsın max değerden daha büyük değer girersen 
    // max değeri verir
    //  +5 (three spaces, followed by a plus symbol, and a 5). verirsen The leading whitespace is skipped. 
    //Plus is a valid symbol at the start of a number (just as a minus sign would be), so it is extracted. The 5 is also extracted.

    //c++ default variabları çok sınrılıdır (int e 0o vermes gibi) ramda kalan son rastgale veriyi atar
    std::cout << sizeof(int);
    // bir int 4 baytlık yer kaplarmış 1bayt=8 bit yani 32 bit
    // Avoid naming your identifiers starting with an underscore. Although syntactically legal, these names are typically reserved 
    // for OS, library, and/or compiler use.
    /*
    Key insight
    Literals are values that are inserted directly into the source code. These values usually appear directly in the executable code 
    (unless they are optimized out).
    Objects and variables represent memory locations that hold values. These values can be fetched on demand.*/
    return 0;
}