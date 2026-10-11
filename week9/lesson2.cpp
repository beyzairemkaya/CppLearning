#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> list{10, 20, 30};

    // INSERT
    list.push_back(40);
    list.insert(list.begin() + 1, 15);
    std::cout<<list[0]<<" "<<list[1]<<"\n";
    // list.begin() listenin ilk elemanını gösteren bir iterator dur
    auto it2 = list.begin();
    std::cout << *it2<<"\n"; // 10
    /*
    Pointer: Bellekteki bir adresi tutar.
    Iterator: Bir veri yapısının elemanları arasında gezinmek için kullanılan nesnedir. Pointer benzeri davranabilir.
    */
    // REMOVE
    list.erase(list.begin());
    std::cout<<list[0]<<" "<<list[1]<<"\n";

    // FIND
    auto it = std::find(list.begin(), list.end(), 20);

     // PREVIOUS
        if (it != list.begin()) {
            auto previous = std::prev(it);
            std::cout << *previous << '\n';
        }

        // NEXT
        if (std::next(it) != list.end()) {
            auto next = std::next(it);
            std::cout << *next << '\n';

    // PRINT
    for (int x : list) {
        std::cout << x << " ";
    }

    // CLEAR
    list.clear();
    // std::cout<<list[0]<<" "<<list[1]<<"\n"; 
}}