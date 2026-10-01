#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}
void changeadress (int* adress){
    int y {11};
    adress=&y;
}
void changevalue(int* adress){
    int y {11};
    *adress=y;
}
void xfunc (const int* d){}
void print(int* ptr)
{
    if (!ptr) // if ptr is a null pointer, early return back to the caller
        return;

    // if we reached this point, we can assume ptr is valid
    // so no more testing or nesting required

    std::cout << *ptr << '\n';
} // null checking yapmayı unutma

int main()
{
    std::string str{ "Hello, world!" };

    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    int x {9};
    int* ptr {&x};
    changeadress(ptr);
    std::cout<<&x<<"\n"<<ptr<<"\n"<<x<<"\n";
    // x pass by adress pointer pass by value geçti dresin kendisi ponterin kopyası gitti
    // bu yüzden pointerin adresini değiştrimeye çalışsan değişmez ama x in değerini aşağıdki gibi değiştirebilirsin
    // poiterin adresini değiştiremeyeceğin için int* const x şeklinde paramtere vermen gereksizdir çünkü zaten kopyası gider

    int x1 {9};
    int* ptr1 {&x1};
    changevalue(ptr1);
    std::cout<<&x1<<"\n"<<ptr1<<"\n"<<x1<<"\n";

    // xfunc(x1); const int parametre alan fonksiyona int yollayamzsın

    



}
/*
#include <iostream>
#include <cassert>

void print(const int* ptr) // now a pointer to a const int
{
	assert(ptr); // fail the program in debug mode if a null pointer is passed (since this should never happen)

	// (optionally) handle this as an error case in production mode so we don't crash if it does happen
	if (!ptr)
		return;

	std::cout << *ptr << '\n';
}

int main()
{
	int x{ 5 };

	print(&x);
	print(nullptr);

	return 0;
}
    assert sadece debug modunda çalışır release e geçince silişnşr
    bu kodu çalıştırmak için f5 e basarsan assert çalışır normal çalıştırısan çalışmaz
*/

/*
2. printByReference(5); $\rightarrow$ Asıl Sihir Burada!C++void printByReference(const int& ref)
Normalde referanslar kalıcı bir değişken (lvalue) ister. Eğer fonksiyon (int& ref) olsaydı printByReference(5) derleme hatası verirdi
.Ama parametre const int& olduğu için C++ dilinde "Lifetime Extension" (Ömür Uzatma) kuralı devreye girer:Derleyici gizlice arka planda isimsiz, 
geçici bir değişken yaratır:const int __gecici = 5;Senin ref referansını bu gizli değişkene bağlar.Bu geçici değişkenin ömrünü, fonksiyon çalışıp
bitene kadar uzatır.Fonksiyon bitince o geçici değişkeni bellekten temizler.Yani const & sayesinde 5 sayısı havada kalmaz; derleyici ona geçici 
de olsa güvenli bir bellek açar.
*/

// “Pass by reference when you can, pass by address when you must”.
/*
#include <iostream>

void nullify(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    int x{ 5 };
    int* ptr{ &x }; // ptr points to x

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");

    nullify(ptr);

    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
*/