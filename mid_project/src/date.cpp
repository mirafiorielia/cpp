//#authors group_42:
//@Elia Mirafiori 2008772
//@Davide Iannello 2009661
//@Alberto Celadin 2007950
//
//#date: 21 Nov 2022
//
//#version: 1.0.0

#include "../include/date.h"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::to_string;

// default constructor
Date::Date()
    : year{0}, month{Month(0)}, day{0} {
    if (!is_valid()) set_year(0);
}

// constructor that needs year, month, day in order
Date::Date(int year, int month, int day)
    : year{year}, month{Month(month)}, day{day} {
    if (!is_valid()) set_year(0);
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

// set year
void Date::set_year(const int &year) {
    this->year = year;
}

// set month
void Date::set_month(const int &month) {
    this->month = Month(month);
}

// set day
void Date::set_day(const int &day) {
    this->day = day;
}

// set date
void Date::set_date(const int &year, const int &month, const int &day) {
    this->year = year;
    this->month = Month(month);
    this->day = day;
}
// set year

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
bool Date::validate_date(int x, int max, int min = 1) const {
    if (x < min || x > max) return false;
    return true;
}

// check if the date received is valid
bool Date::is_valid() {
    bool is_valid = true;

    if (get_year() == 0) return false;

    int m = get_month();  // get month
    int d = get_day();    // get day

    if (!validate_date(m, 11, 0)) return false;  // check month between 0 and 11 ref: enums.cpp

    // check month with 30 days
    if (m == 3 || m == 5 || m == 8 || m == 10) {
        if (!validate_date(d, 30)) return false;  // check day between 1 and 30
    }

    if (m == 1) {                                     // check if month is feb
        if (is_leap()) {                              // check if leap year
            if (!validate_date(d, 29)) return false;  // check day between 1 and 29
        }
        if (!validate_date(d, 28)) return false;  // check day between 1 and 28
    }

    if (!validate_date(d, 31)) return false;  // check day between 1 and 31

    return true;
}

/*
overload ostream "<<" operator to output the book informations

output example:
date -> 26 09 2000
*/
ostream &operator<<(ostream &os, const Date &date) {
    os << date.get_date() << endl;
    return os;
}