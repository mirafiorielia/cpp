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

    // getter functions
    std::string get_isbn() const;          // return book isbn
    std::string get_title() const;         // return book title
    std::string get_auth_name() const;     // return book author name
    std::string get_auth_surname() const;  // return book author surname
    Date get_date() const;                 // return book copyright date
    bool is_available() const;             // return if book is available

    // setter functions
    void set_isbn(const std::string &isbn);                  // set book isbn
    void set_title(const std::string &title);                // set book title
    void set_auth_name(const std::string &auth_name);        // set book author name
    void set_auth_surname(const std::string &auth_surname);  // set book author surname
    void set_date(const Date &date);                         // set book copyright date
    void set_availability(const bool &available);            // set book availability

    // usefull funcs for the user
    bool borrow_book();                              // borrow book from library
    bool return_book();                              // return book to the library
    bool check_isbn(const std::string &isbn) const;  // check book isbn

    bool operator==(const Book &book) const;
    bool operator!=(const Book &book) const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

   private:
    std::string isbn, title, auth_name, auth_surname;  // general info
    Date date;                                         // copyright date
    bool available;                                    // book status
};
