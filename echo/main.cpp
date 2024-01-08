#include <iostream>
#include "echo_application.h"

int main() {
    EchoApplication app(std::cin, std::cout);
    app.run();

    return 0;
}