#include <iomanip>
#include <iostream>

#include "UndergroundSystem.h"

int main() {
    UndergroundSystem metro;

    metro.checkIn(45, "Leyton", 3);
    metro.checkIn(32, "Paradise", 8);
    metro.checkIn(27, "Leyton", 10);
    metro.checkOut(45, "Waterloo", 15);
    metro.checkOut(27, "Waterloo", 20);
    metro.checkOut(32, "Cambridge", 22);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Promedio Paradise -> Cambridge: "
              << metro.getAverageTime("Paradise", "Cambridge") << '\n';
    std::cout << "Promedio Leyton -> Waterloo:    "
              << metro.getAverageTime("Leyton", "Waterloo") << '\n';

    metro.checkIn(10, "Leyton", 24);
    std::cout << "Promedio Leyton -> Waterloo:    "
              << metro.getAverageTime("Leyton", "Waterloo") << '\n';

    metro.checkOut(10, "Waterloo", 38);
    std::cout << "Promedio Leyton -> Waterloo:    "
              << metro.getAverageTime("Leyton", "Waterloo") << '\n';
    return 0;
}
