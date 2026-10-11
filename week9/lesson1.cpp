#include <string>
#include <iostream>


//struct tabımlamak hafızada yeni bir alan ayırmaz sadece yeni bir veri tipi tanımlar

struct Student{
    // const long id;
    long id;
    std::string name;
    int age;
};
// struct un sonudna ; unutma aynı int x; demek gibi mantığı hatırla kuralı hatırla
// büyük projelerde structları headerda tanımlamak daha iyidir

struct Classroom{
    Student student1;
    Student student2;
    // nested struct lar yapabilirisn
    void sayHello() {
        cout << "Hello!";
    }
    // Struct içinde fonksiyon tanımlayablirsin!!
}; // lütfen noktalı virgül unutmaaaaaaaaaaaaaa

void WriteOut(Student student){
    std::cout<<student.id<<"\n";
    std::cout<<student.name<<"\n";
    std::cout<<student.age<<"\n";
    // tüm elemanlarını işleme aldığı için Aggregate Operationdur
}
void changeAge(Student& student){
    // refaransla almazsan değiştiremzsin tabii ki
    student.age++;
}
bool isOlder(Student student1,Student student2){
    return student1.age>student2.age;
    // tabiki tüm structu karşılaştırmazsın student1< student2 gibi ama elemanlarını karşılaştırablrsin
}
Student rtrnBeyza(){
    Student beyza {223223,"beyza",20};
    return beyza;
    // beyza scope sonunda destroy edilecek yani refransı değil copy değeri döndürmemiz gerek
    // orijinal yerel nesneye referans döndürmez; bir AnimalType değeri döndürür. Böylece bilgiler fonksiyon dışında kullanılabilir. 
    // Derleyici bunu kopyalama veya taşıma yoluyla gerçekleştirebilir; hatta bazı durumlarda kopyalamayı tamamen ortadan kaldırabilir (NRVO).
    
}
/*
void tryChangeId(Student& student){
    student.id++;
    // bu fonksiyonu hiç çağırmasan bile compile time da hata verir
}
*/
int main(){
    Student beyza;
    beyza.id=2240356076;
    // mesela id const olursa bunu yapamazsın aslıdaki gibi direct initialize etmelisin
    beyza.name="beyza irem kaya";
    beyza.age=20;
    Student irem;
    irem=beyza;
    std::cout<<irem.name<<"\n";
    // tüm elamanlarıyal işlem yaptığımız için buna Aggregate Operation deriz
    /*
    cout << s1.age;
    cout << s1.gpa;
    // toplu işlemlerde böyle şeyler yapamazsın
    perations valid on an entire struct type variable:
    • assignment to another struct variable of same type,
    • pass to a function as argument (by value or by
    reference),
    • return as value of a function
    */
   // direkt şu şekildede başlatabilriisn
   Student asli {2233332,"asli yermez",23};
   WriteOut(asli);
   changeAge(asli);
   WriteOut(asli);
}

