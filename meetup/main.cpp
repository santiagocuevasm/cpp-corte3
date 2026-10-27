#include <iostream>

#include "meetup.h"

int main() {
    using meetup::Descriptor;
    using meetup::Weekday;

    std::cout << "Lunes teenth de mayo 2013      -> "
              << meetup::to_string(meetup::find(2013, 5, Weekday::Monday, Descriptor::teenth)) << '\n';
    std::cout << "Ultimo miercoles de dic 2013   -> "
              << meetup::to_string(meetup::find(2013, 12, Weekday::Wednesday, Descriptor::last)) << '\n';
    std::cout << "Primer lunes de marzo 2013     -> "
              << meetup::to_string(meetup::find(2013, 3, Weekday::Monday, Descriptor::first)) << '\n';
    std::cout << "Tercer jueves de feb 2015      -> "
              << meetup::to_string(meetup::find(2015, 2, Weekday::Thursday, Descriptor::third)) << '\n';
    return 0;
}
