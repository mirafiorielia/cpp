#ifndef date_h
#define date_h

#include <iostream>
#include <string>

#include "enums.cpp"

/*
#authors group_42:
@Elia Mirafiori 2008772
@Davide Iannello 2009661
@Alberto Celadin 2007950

#date: 21 Nov 2022

#version: 1.0.0
*/
class Date {
   public:
    // constructors
    Date();
    Date(int year, int month, int day);

    // getter functions
    int get_year() const;          // get date year
    int get_month() const;         // get date month
    int get_day() const;           // get date day
    std::string get_date() const;  // get date

    // setter functions
    void set_year(const int &year);                                    // set date year
    void set_month(const int &month);                                  // set date month
    void set_day(const int &day);                                      // set date day
    void set_date(const int &year, const int &month, const int &day);  // set date

    bool is_valid();  // check if the date received is valid

   private:
    int year;
    Month month;  // jan = 0, ..., dec = 11
    int day;

    bool is_leap() const;                               // check if the year is leap
    bool validate_date(int x, int max, int min) const;  // check if x is between min and max
};

std::ostream &operator<<(std::ostream &os, const Date &date);

#endif  // date_h