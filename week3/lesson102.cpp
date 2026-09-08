int g_x {9};
int g_abc {123};
// none const değişkenlerler zaten external linkage
extern const int g_abc2 {123};
// burda const değişken externele dış dünayay açılamk zorunda

// fonksiyonlar external linkage dir ama staticle internal yapılabilir
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}