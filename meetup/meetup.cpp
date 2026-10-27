#include "meetup.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

namespace {

bool is_leap(int y) { return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

int days_in_month(int y, int m) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (m == 2 && is_leap(y)) ? 29 : days[m - 1];
}

// Devuelve 0 = domingo, 1 = lunes, ..., 6 = sabado (algoritmo de Sakamoto)
int day_of_week(int y, int m, int d) {
    static const int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) y -= 1;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

}  // namespace

namespace meetup {

Fecha find(int year, int month, Weekday weekday, Descriptor descriptor) {
    const int target = static_cast<int>(weekday);
    const int last_day = days_in_month(year, month);

    if (descriptor == Descriptor::teenth) {
        for (int day = 13; day <= 19; ++day) {
            if (day_of_week(year, month, day) == target) return {year, month, day};
        }
    } else if (descriptor == Descriptor::last) {
        for (int day = last_day; day >= last_day - 6; --day) {
            if (day_of_week(year, month, day) == target) return {year, month, day};
        }
    } else {
        const int n = static_cast<int>(descriptor);  // first=0, second=1, third=2, fourth=3
        const int first_match = 1 + (target - day_of_week(year, month, 1) + 7) % 7;
        const int day = first_match + 7 * n;
        if (day <= last_day) return {year, month, day};
    }
    throw std::domain_error("No existe esa fecha");
}

std::string to_string(const Fecha& f) {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(4) << f.year << '-' << std::setw(2)
        << f.month << '-' << std::setw(2) << f.day;
    return out.str();
}

}  // namespace meetup
