#include <iostream>

void change(int*& p, int* newAddress) {
    p = newAddress;
}

int main(){
    // two dimensinol fixed array şöyle oluştururlur
    int array37[4][5];
    // ama dynamic multidimesinol array şöyle olmaz
    // int** array { new int[10][5] }; // won’t work!
    // new int [10][5] dediğinde  ilk satırın adresi, 5 elemanlı bir int dizisini gösteren pointer türündedir
    // int i gösteren pointerı gösteren pointeri değil 5 dizilik arrayı gösteren pointer
    int (*beyza)[5]; // e elemanlı diziyi gösteren o-poineter
    // 5 elemanlı int dizisini gösteren pointer tanımlıyoruz.
    // dikkat int* beyza [5] yazsan 5 elemanlı array olur direkt

    int x { 7 }; // non-constant
    int (*array2)[5] { new int[x][5] }; // rightmost dimension must be constexpr pointerın türü belli olmalı

    auto array { new int[x][5] }; // so much simpler!
    // type deductionu kullanabilriisn

    delete[] array2;
    delete[] array;

    /*
    Unfortunately, this relatively simple solution doesn’t work if the rightmost array dimension isn’t a compile-time constant. 
    In that case, we have to get a little more complicated. First, we allocate an array of pointers (as per above). 
    Then we iterate through the array of pointers and allocate a dynamic array for each array element. Our dynamic two-dimensional array 
    is a dynamic one-dimensional array of dynamic one-dimensional arrays!

    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count { 0 }; count < 10; ++count)
    array[count] = new int[5]; // these are our columns
    */
   // With this method, because each array column is dynamically allocated independently, it’s possible to make dynamically allocated 
   // two dimensional arrays that are not rectangular. For example, we can make a triangle-shaped array:

    int** array3 { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count { 0 }; count < 10; ++count){
        array3[count] = new int[count+1]; // these are our columns
    }

    // Deallocating a dynamically allocated two-dimensional array using this method requires a loop as well:

    for (int count { 0 }; count < 10; ++count){
        delete[] array3[count];}
    delete[] array3; // this needs to be done last

    <// bak direkt arrayı silsen rowdaki arraylar memory leak yapar önce döngü ile onları silmey unutm!!


    int xa = 10;
    int ya = 50;

    int* ptra = &xa;

    change(ptra, &ya);

    std::cout << *ptra; // 50
    // int*& p, bir int* değişkenine referans demek.

}
/*
Because allocating and deallocating two-dimensional arrays is complex and easy to mess up, it’s often easier to “flatten” a two-dimensional 
array (of size x by y) into a one-dimensional array of size x * y:

// Instead of this:
int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
for (int count { 0 }; count < 10; ++count)
    array[count] = new int[5]; // these are our columns

// Do this
int *array { new int[50] }; // a 10x5 array flattened into a single array
Simple math can then be used to convert a row and column index for a rectangular two-dimensional array into a single index for a 
one-dimensional array:

int getSingleIndex(int row, int col, int numberOfColumnsInArray)
{
     return (row * numberOfColumnsInArray) + col;
}

// set array[9,4] to 3 using our flattened array
array[getSingleIndex(9, 4, 5)] = 3;
*/