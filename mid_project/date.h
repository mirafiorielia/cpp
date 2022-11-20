#include "enums.cpp"

class Date {
   private:
    int year;
    Month month;
    int day;

   public:
    // error report
    class Invalid {
    };

    // constructors
    Date();
    Date(int year, int month, int day);

    // TODO later setter funcs
    // int set_year();
    // int set_month();
    // int set_day();

    // getter funcs
    int get_year() const;   // get date year
    int get_month() const;  // get date month
    int get_day() const;    // get date day

    bool is_leap() const;  // check if the year is leap

    bool is_valid();
};