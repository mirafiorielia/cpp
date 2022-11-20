#include <iostream>
#include <regex>
#include <string>

#include "date.h"

class Book {
   public:
    // constructors
    Book();
    Book(std::string auth_name, std::string auth_surname, std::string title, std::string isbn);
    Book(std::string auth_name, std::string auth_surname, std::string title,
         std::string isbn, Date date, bool available);

    // destructor
    //~Book();

    // get general info funcs
    std::string get_isbn() const;          // return book isbn
    std::string get_title() const;         // return book title
    std::string get_auth_name() const;     // return book author name
    std::string get_auth_surname() const;  // return book author surname
    Date get_date() const;                 // return book copyright date
    bool is_available() const;             // return if book is available

    // usefull funcs for the user
    bool borrow_book();  // borrow book from library
    bool return_book();  // return book to the library
    bool check_isbn();   // check book isbn

    bool operator==(const Book &book) const;
    bool operator!=(const Book &book) const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

   private:
    std::string isbn, title, auth_name, auth_surname;  // general info
    Date date;                                         // copyright date
    bool available;                                    // book status
};
