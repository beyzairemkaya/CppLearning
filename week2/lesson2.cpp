// debug modu kodunu satır satır çalıştırmanı sağlar
// eskiden ide lerin içinde integrarated debugger yoktu terminalden komutlarla bakıyorlardı
// gömülü sistem gibi alanlarda hala bu yöntem kullanılır
#include <iostream>

void printValue(int value)
{
    std::cout << value << '\n';
}
int multipletwo(int x){
    return x*2;
}

int main()
{
    printValue(5);
    int y {multipletwo(8)};
    int z {multipletwo(87)};


    return 0;
}
// şu anlık step back komutu yok mebur en baştan çalıştıracaksın
// n VS Code, the run to cursor command can be accessed while already debugging a program by right clicking a statement in your code and 
// choosing Run to Cursor from the context menu.
// run to cursor lada gemişe gidemiyorsun tek çözüm you yeniden başlatmak

// brakpoint mantığı Yani program normal hızında çalışır, ama belirlediğin satıra ulaşınca otomatik olarak durur.
/*
Warning

You should not use set next statement to change the point of execution to a different function. This may result in undefined behavior, 
and likely a crash.
“Step back” vs jumping backwards via “Set next statement”
“Step back” rewinds the state of everything, as if you’d never gone past that point in the first place. Any changes to variable values or other 
program state is undone. This is essentially an “undo” command for stepping.

“Set next statement” when used to jump backwards only changes the point of execution. Any changes to variable values or other program state 
are not undone.
*/
/*
Yöntem 1 (En yaygın)
Koduna bir breakpoint koy.
F5 ile debug başlat.
Program breakpoint'te durunca sol tarafta Run and Debug paneli açılır.
hemen solda işte */

/*
The call stack is a list of all the active functions that have been called to get to the current point of execution. 
The call stack includes an entry for each function called, as well as which line of code will be returned to when the function returns.
Whenever a new function is called, that function is added to the top of the call stack. When the current function returns to the caller, 
it is removed from the top of the call stack, and control returns to the function just below it.*/

/*
Compiler: Zorunlu analiz yapar, temel hataları yakalar.
Static analysis tools (clang-tidy, cppcheck, SonarLint...): Compiler'dan çok daha kapsamlı analiz yapar.
IDE: Bu araçların çalışmasını kolaylaştıran bir arayüzdür; analizin kendisini yapan genellikle bu araçlardır, IDE değil.
*/