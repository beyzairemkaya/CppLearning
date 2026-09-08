#include <iostream>
// 1. Sadece Foo'nun içinde yer alan fonksiyon
namespace Foo
{
    int subtract(int x, int y)
    {
        return x - y;
    }
}

// 2. Foo altındaki Goo'nun içinde yer alan fonksiyon
namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}


namespace Foo2
{
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
        
	}
    void print2()
    {
            print(); // en yakın print
            ::print(); // gloval print
        }
}
/*
Nested da olur
namespace Foo
{
    // Sadece Foo seviyesinde
    int subtract(int x, int y)
    {
        return x - y;
    }

    namespace Goo
    {
        // Foo::Goo seviyesinde
        int add(int x, int y)
        {
            return x + y;
        }
    }
}
*/
int main()
{
	Foo2::print(); // call print() in Foo namespace
	::print();    // call print() in global namespace (same as just calling print() in this case) 
    // ama ::print kesin globel print demek üsteki örnekte oldugu gibi
    Foo2::print2();
    // Sadece Foo'da olana erişim:
    std::cout << Foo::subtract(5, 2) << '\n'; // Çıktı: 3

    // Foo::Goo içinde olana erişim:
    std::cout << Foo::Goo::add(1, 2) << '\n';  // Çıktı: 3

    // daha da iç içe girdikçe Foo::Goo::Xoo vs yazmak zor olacağı için yer tutucu kullanabilirsin 
    namespace Active=Foo::Goo;
    std::cout << Active::add(1, 2) << '\n';  // Çıktı: 3
    /*
    One nice advantage of namespace aliases: If you ever want to move the functionality within Foo::Goo to a different place, 
    you can just update the Active alias to reflect the new destination, rather than having to find/replace every instance of Foo::Goo.
    */

	return 0;
}
/*
It’s legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file). All declarations within the namespace are considered part of the namespace.

circle.h:

#ifndef CIRCLE_H
#define CIRCLE_H

namespace BasicMath
{
    constexpr double pi{ 3.14 };
}

#endif
growth.h:

#ifndef GROWTH_H
#define GROWTH_H

namespace BasicMath
{
    // the constant e is also part of namespace BasicMath
    constexpr double e{ 2.7 };
}

#endif
main.cpp:

#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e

#include <iostream>

int main()
{
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    return 0;
}
*/