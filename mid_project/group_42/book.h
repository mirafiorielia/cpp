#ifndef book_h
#define book_h

#include <iostream>
#include <regex>
#include <string>

#include "date.h"

/*
#authors group_42:
@Elia Mirafiori 2008772
@Davide Iannello 2009661
@Alberto Celadin 2007950

#date: 21 Nov 2022

#version: 1.0.0
*/
class Book {
   public:
    // constructors
    Book();
    Book(std::string auth_name, std::string auth_surname, std::string title, std::string isbn);
    Book(std::string auth_name, std::string auth_surname, std::string title,
         std::string isbn, Date date, bool available);

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
    void borrow_book();                              // borrow book from library
    void return_book();                              // return book to the library
    bool check_isbn(const std::string &isbn) const;  // check book isbn
    bool check_date() const;                         // check book date

    bool operator==(const Book &book) const;  // overloading default operator
    bool operator!=(const Book &book) const;  // overloading default operator

   private:
    std::string isbn, title, auth_name, auth_surname;  // general info
    Date date;                                         // copyright date
    bool available;                                    // book status

    std::vector<std::string> split(const std::string &isbn, const char delimiter) const;
};

std::ostream &operator<<(std::ostream &os, const Book &book);

#endif  // book_h