#include <iostream>

int main() {

    int num = 0x1234;
    char* ptr = (char*)&num;

    *ptr = 'X';
    ptr++;
    *ptr = 'X';

    std::cout << "num = 0x" << std::hex << num << std::endl;
    std::cout << "ptr = " << &num << std::endl;

    return 0;
}