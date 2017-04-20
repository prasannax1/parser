#include "splitIter.H"
#include <iostream>
int main() {
    for (auto v: splitIter("hello world and bananas", ' ')) {
        std::cout << v << std::endl;
    }
}
