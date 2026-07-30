#include <iostream>

// her zaman ilk çalışan fonskiyon main değildir 
// örneğin global değişkenler varsa bu durum değişir
int getValue(){
    std::cout<< "getValue worked\n";
    return 5;
}
int num {getValue()};
void printA(){
    std::cout << "A";
}


int main(){
    std::cout<<"main worked";
    // getvalueworked mainworked olur


   // std::cout <<printA();
   // bu satır hata verir çünkü std count içine return değer lazım oraya printA yazdırmamızın hiçbir mantığı yok
}

// diyelim ki bir fonksiyonu sonradan düzenledin ve artık paramatre almıyor onu x(int count) şeklinde bırakırsan hata verir
// ama tüm fonsksiyon callarına gidip onu düzeltmek de çok zaman alır o yüzden x(int) şeklinde bırakabilirisn 
// paramatre aldıgını ama hiç kullanamdığını söyler

/*
++x      // Prefix
x++      // Postfix

Operator overloading yapılırken bunlar şu şekilde ayırt edilir:

operator++();      // Prefix

operator++(int);   // Postfix

Buradaki int parametresi gerçekten kullanılmak için değil, sadece derleyiciye "bu postfix sürümü" demek için vardır. 
Bu, C++ dilinin tasarımında özel olarak belirlenmiş bir kuraldır.*/


/*
#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value of input back to the caller
}

int main()
{
	std::cout << getValueFromUser() << '\n'; // where does the returned value get stored?

	return 0;
}*/


