#include <iostream>
#include <limits>

int main() {
    std::cout << "Hello World!";
    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get(); // get one more char from the user
    return 0;
}
/*
Bu dosyayı direkt vs code un entegre terminal,inden çalıştırıan çalışır çünkü bu terminal program sonlansada kapanmıyor
ama başka IDE lerde çalışırken veya direkt giidp main.exe ye çift tıklarsan termşnal anlık açlışır ve sonrasında kapanır bu durumdan 
korunmak için alt satırları ekledik
bu hali ile çıkmak için çift entera  basman gerek
*/