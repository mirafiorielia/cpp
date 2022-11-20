#include <iostream>
#include <string>

#include "enums.cpp"

class Date {
   public:
    // error report
    /*
    class Invalid {
    };
    */

    // constructors
    Date();
    Date(int year, int month, int day);

    // destructor
    //~Date();

    // getter funcs
    int get_year() const;          // get date year
    int get_month() const;         // get date month
    int get_day() const;           // get date day
    std::string get_date() const;  // get date

    bool is_leap() const;  // check if the year is leap
    bool check_date(int x, int max, int min);
    bool is_valid();

    friend std::ostream& operator<<(std::ostream& os, const Date& date);

   private:
    int year;
    Month month;
    int day;
};