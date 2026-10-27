#pragma once
#include <string>

namespace meetup {

struct Fecha {
    int year;
    int month;
    int day;
};

enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

enum class Descriptor { first, second, third, fourth, last, teenth };

Fecha find(int year, int month, Weekday weekday, Descriptor descriptor);
std::string to_string(const Fecha& fecha);

}  // namespace meetup
