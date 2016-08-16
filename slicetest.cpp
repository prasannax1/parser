#include <iostream>
#include "slice.hpp"

int main() {
    auto s = Slice{(char *)"hello world"};

    std::cout << "s = " << std::string(s) << std::endl;

    for (auto x: s) {
        std::cout << x << std::endl;
    }
}

