C++'ta yaygın bir tercih var:
- struct: Birbirleriyle ilişkili verileri bir arada tutmak için kullanılır. Örneğin Point, StudentInfo, Color.
- class: Verileri ve bunların davranışlarını bir araya getirirken, özellikle veri gizleme (encapsulation) gerektiğinde tercih edilir.

structures can be passed by value or reference 
ama arraylar sadece pass by refrance unutma çünkü pointer ile veriyoruz birde c style arraylar fonskiyon return tipi olmaz çünkü copy edilemzler bunuda unutma

Tabii! C++'ta `struct` ve `class` arasındaki iki temel farkı örneklerle açıklayalım. Aslında ikisi de `public`, `private` ve inheritance kullanabiliyor. Fark, biz hiçbir şey belirtmediğimizde C++'ın ne varsaydığı.

## 1. Varsayılan üye erişimi (Default Member Access)

C++'ta üyelerin kimler tarafından erişilebilir olduğunu belirleyen erişim belirleyicileri (access specifiers) vardır.

- `public`: Sınıfın dışından erişilebilir.
- `private`: Yalnızca sınıfın kendi üyeleri ve `friend` olarak tanımlananlar doğrudan erişebilir.
- `protected`: `private` gibidir, ancak türetilmiş sınıflar da erişebilir.

### Struct → Varsayılan olarak public

```
struct Student {
    string name;
    int age;
};

int main() {
    Student s;
    s.name = "Beyza"; // GEÇERLİ
    s.age = 20;       // GEÇERLİ
}
```

Burada `public:` yazmadık ama C++ üyeleri otomatik olarak `public` kabul etti.

### Class → Varsayılan olarak private

```
class Student {
    string name;
    int age;
};

int main() {
    Student s;
    s.name = "Beyza"; // HATA!
}
```

Çünkü `class` içinde üyeler varsayılan olarak `private`.

Ancak:

```
class Student {
public:
    string name;
    int age;
};
```

Şimdi dışarıdan erişebiliriz.

Birinci farkın özeti: `struct` içinde `public` yazmak zorunda değilsin. `class` içinde ise üyelerin dışarıdan erişilebilir olmasını istiyorsan `public` belirtmelisin.

## 2. Varsayılan kalıtım (Default Inheritance)

Önce inheritance nedir, onu anlayalım.

Diyelim ki bir `Animal` sınıfımız var:

```
class Animal {
public:
    int age;
};
```

Bir de `Dog` sınıfı oluşturacağız.

Her köpeğin bir hayvan olduğunu biliyoruz. O zaman `Animal` sınıfındaki özellikleri `Dog` sınıfına miras bırakabiliriz.

### Struct → Varsayılan public inheritance

```
struct Dog : Animal {
    string name;
};

int main() {
    Dog d;
    d.age = 5;       // GEÇERLİ
    d.name = "Max";  // GEÇERLİ
}
```

Buradaki:

```
struct Dog : Animal
```

aslında şu anlama geliyor:

```
struct Dog : public Animal
```

Yani `Animal` sınıfından gelen `public` üyeler, `Dog` nesnesi üzerinden de `public` olarak erişilebilir kalıyor.

### Class → Varsayılan private inheritance

```
class Dog : Animal {
public:
    string name;
};

int main() {
    Dog d;
    d.age = 5;      // HATA!
    d.name = "Max"; // GEÇERLİ
}
```

Neden `d.age` hata verdi?

Çünkü:

```
class Dog : Animal
```

aslında:

```
class Dog : private Animal
```

demek.

Bu durumda `Animal` sınıfından miras alınan `public` üye, `Dog` içinde `private` erişime dönüşür.

Dolayısıyla sınıfın dışından `d.age` kullanamayız. Ancak `Dog` sınıfının kendi fonksiyonları `age` üyesine erişebilir.

Bunu değiştirmek istersek:

```
class Dog : public Animal {
public:
    string name;
};
```

Artık `d.age` geçerli!

## Özet tablo

| Özellik                                 | `struct` | `class`   |
| --------------------------------------- | -------- | --------- |
| Varsayılan üye erişimi                  | `public` | `private` |
| Varsayılan kalıtım                      | `public` | `private` |
| Açıkça `public:` yazılabilir mi?        | Evet     | Evet      |
| Açıkça `private:` yazılabilir mi?       | Evet     | Evet      |
| `public` inheritance kullanılabilir mi? | Evet     | Evet      |

### Aklında kalması gereken

Şu iki tanım erişim açısından eşdeğerdir:

Struct

```
struct Dog : Animal {
    int age;
};
```

Class

```
class Dog : public Animal {
public:
    int age;
};
```

Yani C++'ta `struct` ve `class` arasındaki temel dil farkı, varsayılan erişim ve kalıtım belirleyicileridir.

Sana bir de düşündürücü soru bırakayım: `class Dog : private Animal` yazdığımızda `Animal`'ın `age` üyesi gerçekten silinmiş mi oluyor, yoksa yalnızca dışarıdan erişimi mi engelleniyor?