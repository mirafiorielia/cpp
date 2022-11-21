#include "date.h"

using std::endl;
using std::ostream;
using std::string;
using std::to_string;

// default constructor
Date::Date()
    : year{0}, month{Month(9)}, day{26} {
    //if (!is_valid()) get_date();
}

// constructor that needs year, month, day in order
Date::Date(int year, int month, int day)
    : year{year}, month{Month(month)}, day{day} {
    //if (!is_valid()) get_date();
}

// returns the year
int Date::get_year() const {
    return year;
}

// returns the month
int Date::get_month() const {
    return month;
}

// returns the day
int Date::get_day() const {
    return day;
}

// returns a string version of the date
string Date::get_date() const {
    if (get_year() == 0) return "invalid date";
    return to_string(get_day()) + ' ' + to_string(get_month()) + ' ' + to_string(get_year());
}

// leap year check
bool Date::is_leap() const {
    // If a year is multiple of 400,
    // then it is a leap year
    if (get_year() % 400 == 0) return true;

    // Else If a year is multiple of 100,
    // then it is not a leap year
    if (get_year() % 100 == 0) return false;

    // Else If a year is multiple of 4,
    // then it is a leap year
    if (get_year() % 4 == 0) return true;

    return false;
}

// function to check month or day is in range
bool Date::check_date(int x, int max, int min = 1) {
    if (x < min || x > max) return false;
    return true;
}

// check if the date received is valid
bool Date::is_valid() {
    if (get_year() == 0) return false;

    int m = get_month();  // get month
    int d = get_day();    // get day

    return check_date(d, 11, 0);  // check month between 0 and 11 ref: enums.cpp

    // check month with 30 days
    if (m == 3 || m == 5 || m == 8 || m == 10) return check_date(d, 30);

    if (m == 1) {                      // check if month is feb
        if (is_leap()) {               // check if leap year
            return check_date(d, 29);  // check day between 1 and 29
        }
        return check_date(d, 28);  // check day between 1 and 28
    }

    return check_date(d, 31);  // check day between 1 and 31
}

/*
overload ostream "<<" operator to output the book informations

output example:
date -> 26 09 2000
*/
ostream& operator<<(ostream& os, const Date& date) {
    os << date.get_date() << endl;
    return os;
}