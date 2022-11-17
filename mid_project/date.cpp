#include "date.h"

using namespace Chrono;

Date::Date()
    : year{2000}, month{Month(9)}, day{Day(26)}
{
    if (!is_valid())
    {
        throw Invalid();
    }
}

Date::Date(int year, int month, int day)
    : year{year}, month{Month(9)}, day{Day(26)}
{
    if (!is_valid())
    {
        throw Invalid();
    }
}

bool Date::is_valid()
{
    if (month < 0 || month > 11)
    {
        return false;
    }
    if (day < 1 || day > 31)
    {
        return false;
    }
}