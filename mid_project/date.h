#include "enums.cpp"

class Date
{
public:
    // errors report
    class Invalid
    {
    };

    // constructors
    Date();
    Date(int year, int month, int day);

    // setter funcs
    int set_year();
    int set_month();
    int set_day();

    // getter funcs
    int get_year();
    int get_month();
    int get_day();

private:
    int year;
    Month month;
    Day day;

    bool is_valid();
};