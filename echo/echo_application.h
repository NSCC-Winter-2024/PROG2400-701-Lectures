#ifndef ECHO_APPLICATION_H
#define ECHO_APPLICATION_H

#include <iostream>

class EchoApplication {
    static constexpr std::string END_VALUE {"end"};
    std::istream& _cin;
    std::ostream& _cout;
    std::string _input;
public:
    explicit EchoApplication(std::istream& in, std::ostream& out);
    void input();
    void output();
    void run();
};

#endif