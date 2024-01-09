#include <iostream>

void parse_command_line(auto argc, auto argv) {
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
}

int main(int argc, char** argv) {

    parse_command_line(argc, argv);

    return 0;
}