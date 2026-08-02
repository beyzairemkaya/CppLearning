#include <iostream>
// iki dosyayda bunu eklemeyi unutma

int a(int);
int b(int);
// ikiisde birbirini çağırdığı için forward declation yapmalısın unutma

int a(int num){
    std :: cout << "a worked num: "<<num<<"\n";
    if (num==0) return 0;
    num--;
    b(num);
    return num;
}
int b(int num){
    std :: cout << "b worked num: "<<num<<"\n";
    if (num==0) return 0;
    num--;
    a(num);
    return num;
}
