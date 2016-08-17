#include <iostream>
#include "slice.hpp"

int main() {
    auto s = Slice{"hello world"};

    //test indexing
    std::cout << "testing index" << std::endl;
    for (auto i: {0, 1, 2, 3, 4, 5, 6}) {
        std::cout << s[i] << std::endl;
    } 

    //test printing
    std::cout << "testing print" << std::endl;
    std::cout << std::string(s) << std::endl;

    //test iteration
    std::cout << "testing iterator" << std::endl;
    for (auto c: s) {
        std::cout << c << std::endl;
    }

    //test slicing
    std::cout << "testing slicing" << std::endl;
    std::cout << "s(1,5) = " << std::string(s(1,5)) << std::endl;
    std::cout << "s(3,5) = " << std::string(s(3,5)) << std::endl;
    std::cout << "s(1,-1) = " << std::string(s(1,-1)) << std::endl;
}

