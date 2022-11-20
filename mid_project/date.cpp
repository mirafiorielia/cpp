#include "date.h"

Date::Date()
    : year{2000}, month{Month(9)}, day{26} {
    if (!is_valid()) {
        throw Invalid();
    }
}

Date::Date(int year, int month, int day)
    : year{year}, month{Month(9)}, day{26} {
    if (!is_valid()) {
        throw Invalid();
    }
}

bool Date::is_valid() {
    if (get_month() < 0 || get_month() > 11) {
        return false;
    }

    if (is_leap() && get_month() == 1) {
        if (get_day() < 1 || get_day() > 29) {
            return false;
        }
    } else {
        int m = get_month();
        if (m == 3 || m == 5 || m == 9 || m == 11) {
                }

        if (get_month() < 7) {
            if (get_month() % 2 == 0) {
                if (get_day() < 1 || get_day() > 31) {
                    return false;
                }
            } else {
                if (get_day() < 1 || get_day() > 30) {
                    return false;
                }
            }
        } else {
            if (get_month() % 2 == 1) {
                if (get_day() < 1 || get_day() > 31) {
                    return false;
                }
            } else {
                if (get_day() < 1 || get_day() > 30) {
                    return false;
                }
            }
        }
    }
}

bool Date::is_leap() const {
    // If a year is multiple of 400,
    // then it is a leap year
    if (get_year() % 400 == 0)
        return true;

    // Else If a year is multiple of 100,
    // then it is not a leap year
    if (get_year() % 100 == 0)
        return false;

    // Else If a year is multiple of 4,
    // then it is a leap year
    if (get_year() % 4 == 0)
        return true;

    return false;
}