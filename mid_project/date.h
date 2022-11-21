#include <iostream>
#include <string>

#include "enums.cpp"

/*
#authors:
@Elia Mirafiori 2008772
@Davide Iannello 2009661
@Alberto Celadin xxx

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

    bool is_leap() const;                         // check if the year is leap
    bool validate_date(int x, int max, int min);  // check if x is between min and max
    bool is_valid();                              // check if the date received is valid

    friend std::ostream &operator<<(std::ostream &os, const Date &date);

   private:
    int year;
    Month month;
    int day;
};