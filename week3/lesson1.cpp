#include <iostream>
// kim kimden üstün diye exberlemek yerien bol bol () kullan
int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous
    // sağdan sola değer atayacağını düşünddün ama y 1 z 2 x3 oldu bu yüzden en iyiis üstte değişken olarak tanımlaamn
    // Operands, function arguments, and subexpressions may be evaluated in any order.
    // Operands, function arguments, and subexpressions may be evaluated in any order.

    

    // hayırla atama ifadesi değer döndürdüğü için çoklu atama yapabilirsin 
    int x {2};
    int y{3};
    int z {4};
    x=y=z;
    // (x(y=z)) olarak algılandı y=4 4 döndürdühepsi 4 olacak
    std::cout<<x<<y<<z<<"\n";
    x%=y; // bu şekilde sadece  - + değil */% da kullanabilirsin
    // operatörler overlad edilebilir örn << bit kaydırma demek ama std cout da overload edilmiş
    // classlarda daha rahat örnek veriririz ama meslela + yı overload etmek istiyosnan operator+ diye overload edecekin
    /*
    class Point
{
public:
    int x;
    int y;

    Point(int x, int y)
        : x{x}, y{y}
    {
    }

    Point operator+(const Point& other)
    {
        return Point{x + other.x, y + other.y};
    }
};
    */
    return 0;
}
