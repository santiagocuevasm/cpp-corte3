#include <iostream>
#include <string>

#include "clock.h"

using Reloj = date_independent::clock;

int main() {
    std::cout << "at(8, 0)            -> " << std::string(Reloj::at(8, 0)) << '\n';
    std::cout << "at(25, 0)           -> " << std::string(Reloj::at(25, 0)) << '\n';
    std::cout << "at(-1, 15)          -> " << std::string(Reloj::at(-1, 15)) << '\n';
    std::cout << "at(10, 0).plus(3)   -> " << std::string(Reloj::at(10, 0).plus(3)) << '\n';
    std::cout << "at(0, 30).minus(60) -> " << std::string(Reloj::at(0, 30).minus(60)) << '\n';
    std::cout << std::boolalpha
              << "at(15, 37) == at(14, 97) -> "
              << (Reloj::at(15, 37) == Reloj::at(14, 97)) << '\n';
    return 0;
}
