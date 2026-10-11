C style arraylar fonksiyonun return tipi olamaz
arraylar değer olarak kopyalanamaz

int* func() {
    int arr[3] = {1, 2, 3};
    return arr; // TEHLİKELİ!
}


Bu kod sözdizimi açısından geçerlidir, ancak arr fonksiyonun yerel değişkenidir.
Fonksiyon bittiğinde arr'nin yaşam süresi sona erer. Döndürdüğümüz pointer ise artık geçersiz belleği gösterir (dangling pointer).

bununyerine std::array kullanırız