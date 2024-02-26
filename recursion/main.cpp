#include <iostream>

void print() {
    std::cout << "hello ";
    print();
}

int main() {
    print();
    return 0;
}