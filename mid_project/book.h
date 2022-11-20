#include <iostream>
#include <string>

using namespace std;

class Book {
   private:
    string isbn, title, auth_name, auth_surname;  // general info
    int date;                                     // TODO switch to Date class
    bool available;                               // book status

   public:
    // constructors
    Book();
    Book(string isbn, string title, string auth_name,
         string auth_surname, int date, bool available);

    // destructor
    ~Book();

    // get general info funcs
    string get_isbn() const;          // return book isbn
    string get_title() const;         // return book title
    string get_auth_name() const;     // return book author name
    string get_auth_surname() const;  // return book author surname
    int get_date() const;             // return book copyright date
    bool is_available() const;        // return if book is available

    // usefull funcs for the user
    bool borrow_book();  // borrow book from library
    bool return_book();  // return book to the library
    // bool is_isbn_valid(); // check book isbn

    bool operator==(const Book &book) const;
    bool operator!=(const Book &book) const;
    friend ostream &operator<<(ostream &os, const Book &book);
};
