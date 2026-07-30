#include <cstdlib>
#include <fstream>
#include <iostream>

int wrong();
int wrong2();

int main()
{
    std::ifstream file("data.txt");

    if (!file)
    {
        return EXIT_FAILURE;
    }

    // Dosya başarıyla açıldı
    return EXIT_SUCCESS;
}
// return 0 yerine cstdlib include edip EXİT_SUCCESS kullanabilrsin veya EXİT_FAİLURE
// EXIT_FAILURE Asıl amacı başka programlara veya işletim sistemine bilgi vermektir. bu hali ile kod hata mesajı falan vermez yani 
// direkt başarısız oldum bilgisi ile kapanır

int wrong(){
    std:: cout <<" I am wrong";
    return 2;
    // eğer return 2 satırını silersen hata verir ama bazı compilelerde undefined behaviorlardad geliştirebilir
    // bu yüzden type kontrolünü yapmak çok önemlidir 
}

int wrong2(){
    return 5;
    return 7;
    // hata vermez return 5 den soraısnı okumaz
}