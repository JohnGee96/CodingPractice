#include <iostream>
#include <sstream>
#include <vector>


template<typename T>

int main() {
    int arr [3] = {4,2,0};
    for (int i : arr) {
        std::cout << i << '\n';
    }
}