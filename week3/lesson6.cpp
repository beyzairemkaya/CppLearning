#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags{ option_favorited };
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';
    
    myArticleFlags|=option_viewed; // option_viewed i açtık

    std::cout<<((myArticleFlags&option_deleted) ? "option_deleted is on\n" : "option_deleted is off\n");

    // myArticleFlags^=option_favorited; // tek biti flip lemek XOR ile yapılır

    myArticleFlags &= static_cast<std::uint8_t>(~option_favorited);
    // diper bitşer &1 ile karşılaşır  se 1 kalır 0 sa 0 ama hedef bit 0 la karşılaşıp resetlenir
    /*
    Örnekteki ~option_favorited ifadesi ise baştaki 24 biti 1 yaptığı için 32-bitlik negatif bir int üretti. 
    Bazı derleyicilerde bu uyarıyı susturmak için static_cast<std::uint8_t>(...) kullanıldı.
    */



    

    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    return 0;
}