#include <iostream>
#include "echo_application.h"

EchoApplication::EchoApplication(std::istream &in, std::ostream &out) : _cin(in), _cout(out) {}

void EchoApplication::input() {
    _cout << "Type something: ";
    std::getline(_cin, _input);
}

void EchoApplication::output() {
    _cout << _input << std::endl;
}

void EchoApplication::run() {
    // example 1
    // echo the input received from the user
    do {
        input();
        output();
    } while (_input != END_VALUE);
}
