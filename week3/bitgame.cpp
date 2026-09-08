#include <bitset>
#include <iostream>

struct Character {
    static constexpr int hasKey      { 0 };
    static constexpr int isPoisoned  { 1 };
    static constexpr int isInvisible { 2 };
    static constexpr int hasShield   { 3 };
    static constexpr int isStunned   { 4 };
    static constexpr int onFire      { 5 };
    static constexpr int isFlying    { 6 };
    static constexpr int isDead      { 7 };

    std::bitset<8> states{ 0b0000'1100 };

    void triggerFireTrap(){
        states.set(onFire);
        // set biti 1 yapar
        states.reset(isInvisible);
        // reset 0 yap demek başlangıç pozisyonuna al depğil
    }

    void wizardHelp(){
        states.reset(onFire);
        states.set(isFlying);
        states.set(isStunned);
    }

    void bossAttack(){
        if (states.test(isFlying)&&(!(states.test(isStunned)))) return;
        states.reset();
        // içine bir şey yapmazsan tüm bitleri 0 yapar 
        states.set(isDead);
    }
};

int main(){
    Character hero;

    std::cout << "1. Baslangic:     " << hero.states << '\n';

    hero.triggerFireTrap();
    std::cout << "2. Ates Tuzagi:   " << hero.states << '\n';

    hero.wizardHelp();
    std::cout << "3. Buyucu Yardimi: " << hero.states << '\n';

    hero.bossAttack();
    std::cout << "4. Boss Saldirisi: " << hero.states << '\n';

    // Raporlama
    std::cout << "---------------------------------\n";
    std::cout << "Karakter Hayatta mi?: " << (!hero.states.test(Character::isDead) ? "Evet" : "Hayir") << '\n';
    std::cout << "Toplam Aktif Durum:   " << hero.states.count() << '\n';

    return 0;
    
    
   

    
}