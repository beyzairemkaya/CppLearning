/*
 versiyon 1
#ifndef week1_x1
#define week1_x1
int multiply(int x, int y){
    return x*y
}
#endif
versiyon 1 in sonu
*/


/* versiyon 2
#ifndef week1_x1
#define week1_x1
int multiply(int x, int y);
#endif
versiyon 2 nin sonu
*/
#pragma once
int multiply(int x, int y);

// pragma once da diğer yöntemlerle aynı işi ypaan modern ve daha kısa bir yol

//#pragma once: Dosyanın disk üzerindeki konumuna (dosya yoluna / path) bakar.
// Header Guard (#ifndef): Dosyanın içindeki yazılı makro ismine (#define) bakar.
/*
#ifndef HESAP_H
#define HESAP_H

struct Hesap { int id; };

#endif
Sen main.cpp içinde önce KlasorA\hesap.h dosyasını, sonra da KlasorB\hesap.h dosyasını #include ettin.

Derleyici 1. dosyayı okur ve hafızaya HESAP_H ismini kaydeder.

Derleyici 2. dosyayı açtığında en üstte #ifndef HESAP_H satırını görür ve şöyle der:

"Dur! Dosya yolu farklı olabilir ama bu HESAP_H kimliğini ben zaten az önce hafızama aldım!"

dosyanın içeriğini tamamen atlar. Kod sorunsuz derlenir. (Başarılı!)

2. #pragma once Kullanırsan Ne Olur?
İki dosyanın da en üstünde sadece şu yazıyor:

C++
#pragma once

struct Hesap { int id; };
Sen main.cpp içinde iki dosyayı da #include ettin.

Derleyici 1. dosyaya bakar: "Hmm, KlasorA\hesap.h dosyasını daha önce okudum mu? Hayır." Okur.

Derleyici 2. dosyaya bakar: "Hmm, KlasorB\hesap.h dosyasını daha önce okudum mu? Hayır, bu farklı bir klasörde!"

Derleyici bu dosyanın içerik olarak 1. dosyanın aynısı olduğunu anlayamaz (çünkü sadece dosya yoluna bakar).

İki dosyayı da kopyalayıp yapıştırdığı için projede 2 tane struct Hesap oluşur ve derleyici anında redefinition of struct Hesap 
(Yeniden tanımlama hatası) verip çöker

*/
/*
Because #pragma once is not defined by the C++ standard, it is possible that some compilers may not implement it. 
For this reason, some development houses (such as Google) recommend using traditional header guards. In this tutorial series, 
we will favor header guards, as they are the most conventional way to guard headers. However, support for #pragma once is fairly 
ubiquitous 
at this point, and if you wish to use #pragma once instead, that is generally accepted in modern C++.
*/

/*
C++ dilini oluşturan komiteler, derleyici geliştiren şirketlere (Microsoft MSVC, GCC, Clang vb.) şöyle bir alan tanımıştır:

"Standart C++ kurallarının dışına çıkıp kendi derleyicinize özel ekstra bir özellik veya ayar eklemek isterseniz, bunun başına 
#pragma yazın."

Yani #pragma, derleyicilere verilen özel bir "özel ayar" direktifidir.

⚠️ Uyarının Demek İstediği 3 Temel Şey
1. Derleyiciye Özeldir (Implementation-Specific)
Bir #pragma komutu sadece onu yazan derleyici için anlamlıdır.

Örneğin, GCC derleyicisi için yazılmış özel bir #pragma GCC optimize ("O3") komutunu alıp Microsoft Visual Studio'da (MSVC) 
derlemeye çalışırsan, MSVC bu komutun ne anlama geldiğini bilmez ve komutu yok sayar.

2. Kodu Başka Yere Taşıyamazsın (Portability Sorunu)
Eğer kodunun içine bolca #pragma serpistirirsen, o kod sadece senin bilgisayarındaki o spesifik derleyicide çalışır. Kodunu başka bir 
işletim sistemine veya farklı bir derleyiciye taşıdığında projen patlayabilir veya beklediğin gibi çalışmayabilir.

3. Tek İstisna: #pragma once
Metinde "With the exception of #pragma once" ( #pragma once hariç) denmesinin sebebi şudur:

Teknik olarak #pragma once da resmi C++ standardının bir parçası değildir.

Ancak o kadar pratik, popüler ve hayat kurtarıcı bir komuttur ki; dünyadaki bütün modern derleyiciler (GCC, Clang, MSVC vs.) 
kendi aralarında anlaşmış gibi bu komutu destekler.

Bu yüzden #pragma once kullanırken "Acaba bu derleyici destekliyor mudur?" korkusu yaşamazsın.*/