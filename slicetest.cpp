#include <iostream>
#include "slice.hpp"

int main() {
    auto s = Slice{"hello world"};

    //test indexing
    for (auto i: {0, 1, 2, 3, 4, 5, 6}) {
        std::cout << s[i] << std::endl;
    } 

    //test iteration
    for (auto c: s) {
        std::cout << c << std::endl;
    }
}

