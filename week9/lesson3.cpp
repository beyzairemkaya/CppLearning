#include <iostream>
class Student {
    //cpp de class elamnları defaut private dır yani private yazmasaydın da private olurlardı
private:
    int age;
    std::string name;
    
    int size;

public:
    int* listArray;
    // dynamic arrayın int[] değil int* olarak gösterildiğini unutma
    Student(int age, std::string name,int size){
        // constructur
        this->age=age; // (*this).age demek
        this->name=name;
        this->size=size; 
        // direkrt age =a diyebilriidn paramtereli öyle ayarlayıp
        listArray= new int[size];
    }
    ~Student(){
        delete[] listArray;
        //destructor bu da
    }
    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }
};// noktalı virgül unutmaaa

class Beyza : public Student{
    // beyza studenttan inherit aldı
    // public yapamzsa private inheritance olur 


};
int main() {
    Student s1(20, "Beyza", 10);

    std::cout << s1.getAge() << '\n';

    return 0;
}

