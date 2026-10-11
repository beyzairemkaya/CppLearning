// destructors 
// normalde destructors kendiliğinde çağrılır zaten yeniden tanımlayıp bazır özelliklerini değiştirmen gereken durumlar oldugunda yazarsın
// örn dynamic bir nesne oluşturusun onu da silmek için yazarsın


#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	IntArray(int length) // constructor
	{
		assert(length > 0);

		m_array = new int[static_cast<std::size_t>(length)]{};
		m_length = length;
	}

	~IntArray() // destructor
	{
		// Dynamically delete the array we allocated earlier
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main()
{
	IntArray ar ( 10 ); // allocate 10 integers
	for (int count{ 0 }; count < ar.getLength(); ++count)
		ar.setValue(count, count+1);

	std::cout << "The value of element 5 is: " << ar.getValue(5) << '\n';

	return 0;
} // ar is destroyed here, so the ~IntArray() destructor function is called here

// Global variables are constructed before main() and destroyed after main().
/*
`IntArray ar(10)` ve `IntArray ar{10}` mevcut sınıfımızda aynı işi yapar çünkü yalnızca `IntArray(int length)` constructor'ı vardır.

Ancak sınıfa `std::initializer_list` alan bir constructor eklenirse davranış değişir:

```
IntArray ar1(10); // Length constructor: 10 elemanlı dizi
IntArray ar2{10}; // Initializer_list constructor: 10 değerini içeren dizi
```

Sebep: `{}` ile initialization yapıldığında `std::initializer_list` constructor'ına öncelik verilir.

Kural: Container oluştururken boyut belirtmek için `()`, elemanların değerlerini belirtmek için `{}` tercih edilir.
*/
