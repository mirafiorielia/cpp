#include <string>

using namespace std;

class Book
{
private:
    string isbn, title, auth_name, auth_surname;
    int date; // TODO switch to Date class
    bool is_available;

public:
    Book();
    Book(string isbn, string title, string auth_name,
         string auth_surname, int date, bool is_available);
    ~Book();

    string get_isbn();
    string get_title();
    string get_auth_name();
    string get_auth_surname();
    int get_date();
    bool available();
};
