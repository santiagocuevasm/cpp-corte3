#pragma once
#include <string>

namespace date_independent {

class clock {
public:
    static clock at(int hour, int minute = 0);
    clock plus(int minutes) const;
    clock minus(int minutes) const;
    explicit operator std::string() const;
    bool operator==(const clock& other) const;
    bool operator!=(const clock& other) const;

private:
    explicit clock(int total_minutes);
    int minutes_;  // siempre entre 0 y 1439
};

}  // namespace date_independent
