namespace Chrono
{
    // month 0..11
    enum Month
    {
        january = 0,
        february,
        march,
        april,
        may,
        june,
        july,
        august,
        september,
        octber,
        november,
        december
    };

    // day 0..6
    enum Day
    {
        monday = 0,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday
    };

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
} // namespace Chrono
