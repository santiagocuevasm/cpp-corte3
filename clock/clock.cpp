#include "clock.h"

#include <iomanip>
#include <sstream>

namespace {
constexpr int kMinutesPerDay = 24 * 60;

int normalize(int minutes) {
    minutes %= kMinutesPerDay;
    if (minutes < 0) minutes += kMinutesPerDay;
    return minutes;
}
}  // namespace

namespace date_independent {

clock::clock(int total_minutes) : minutes_(normalize(total_minutes)) {}

clock clock::at(int hour, int minute) { return clock(hour * 60 + minute); }

clock clock::plus(int minutes) const { return clock(minutes_ + minutes); }

clock clock::minus(int minutes) const { return clock(minutes_ - minutes); }

clock::operator std::string() const {
    std::ostringstream out;
    out << std::setfill('0') << std::setw(2) << minutes_ / 60 << ':'
        << std::setw(2) << minutes_ % 60;
    return out.str();
}

bool clock::operator==(const clock& other) const {
    return minutes_ == other.minutes_;
}

bool clock::operator!=(const clock& other) const { return !(*this == other); }

}  // namespace date_independent
