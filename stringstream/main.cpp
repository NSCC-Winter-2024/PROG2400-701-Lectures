#include <iostream>
#include <sstream>

using namespace std::string_literals;

int main() {

    std::string user_input;
    auto command = "*"s;
    auto start = -1;
    auto end = -1;

    std::cout << "Type in a command: ";
    std::getline(std::cin, user_input);

    std::stringstream ss;
    ss << user_input;

    // extract first string
    ss >> command;

    if (command.length() > 1) {
        // it must be text
    } else {
        // possible 'I', 'L', 'E', 'D', or 'Q' commands

        // try to extract a number
        ss >> start;
        if (!ss.fail()) {
            // success! try to extract out a second number
            ss >> end;
            if (!ss.fail()) {
                // success! it must be a command!
            }
        }
    }

    ss >> command >> start >> end;

    std::cout << "Command: " << command << std::endl;
    std::cout << "First: " << start << std::endl;
    std::cout << "Second: " << end << std::endl;

    return 0;
}