#include "l11ek1.h"
#include "l11ek2.h"
int main(){
    return 0;

}
 // bu hali ile l111 de getsquare var l112 de onu include etti bu yüzden aynı fonksiyondan iki kez yazıldı compile error çıkacak
 // bu sorunu header guards ile çözeriz
 // tüm .h lı dosyalara header quards eklememiz gerekir
 // satndart libary headers larda header quards  kulllanır