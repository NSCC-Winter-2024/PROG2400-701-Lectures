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
        std::cout << "You entered some text." << std::endl;
    } else {
        // possible 'I', 'L', 'E', 'D', or 'Q' commands
        std::cout << "I think you are a command." << std::endl;

        // try to extract a number
        ss >> start;
        if (!ss.fail()) {
            std::cout << "You have a starting number!" << std::endl;
            // success! try to extract out a second number
            ss >> end;
            if (!ss.fail()) {
                // success! it must be a command!
                std::cout << "You have an ending number!" << std::endl;
                std::cout << "I'll assume you are a valid command." << std::endl;
            } else {
                std::cout << "You didn't have an ending number." << std::endl;
                std::cout << "I'll still assume you are a valid command." << std::endl;
            }
        } else {
            // didn't get a number, but could be a command
            // if the entire input was only one character
            if (user_input.length() == 1) {
                std::cout << "I'll assume you are a command!" << std::endl;
            } else {
                std::cout << "You must be text instead." << std::endl;
            }
        }
    }

    std::cout << "Command: " << command << std::endl;
    std::cout << "First: " << start << std::endl;
    std::cout << "Second: " << end << std::endl;

    return 0;
}