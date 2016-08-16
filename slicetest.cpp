#include <iostream>
#include "slice.hpp"

int main() {
    auto s = Slice{(char *)"hello world"};
    auto a = s(1,5);

    std::cout << "s = " << std::string(s) << " and a = " << std::string(a) << std::endl;
}

