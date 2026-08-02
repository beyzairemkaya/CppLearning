#include "add.h" 

int add(int x,int y){
    return x+y;
}

/*
Neden add.cpp e add.h include ekledik
type checking için
Derleyici, add.h içindeki söz ile add.cpp içindeki icraatın birebir uyuşup uyuşmadığını denetler.
Eğer add.h dosyasına int add(int x, int y); yazıp, add.cpp içinde yanlışlıkla double add(int x, int y) yazarsan,
 add.cpp kendi header'ını include ettiği için derleyici seni anında uyarır.
*/