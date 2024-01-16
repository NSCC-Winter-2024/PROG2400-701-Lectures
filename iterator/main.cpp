#include <iostream>
#include <vector>

int main() {

    auto v = std::vector {1, 2, 3, 4, 5};

    for (auto n:v) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    for (auto it = v.begin(); it != v.end() ; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}