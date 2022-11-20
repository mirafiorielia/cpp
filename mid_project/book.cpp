#include "book.h"

using std::endl;
using std::ostream;
using std::string;

Book::Book()
    : isbn{"n-n-n-x"}, title{"dummy"}, auth_name{"dummy"}, auth_surname{"dummy"}, date{0}, available{true} {
}

Book::Book(string isbn, string title, string auth_name,
           string auth_surname, int date, bool available)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{date}, available{available} {
}

string Book::get_isbn() const {
    return isbn;
}

string Book::get_title() const {
    return title;
}

string Book::get_auth_name() const {
    return auth_name;
}

string Book::get_auth_surname() const {
    return auth_surname;
}

int Book::get_date() const {
    return date;
}

bool Book::is_available() const {
    return available;
}

bool Book::borrow_book() {
    if (is_available()) {
        available = false;
    }
    return available;
    // TODO else throw invalid
}

bool Book::return_book() {
    if (!is_available()) {
        available = true;
    }
    return available;
    // TODO else throw invalid
}

bool Book::operator==(const Book& book) const {
    return isbn == book.get_isbn();
}

bool Book::operator!=(const Book& book) const {
    return isbn != book.get_isbn();
}

ostream& operator<<(ostream& os, const Book& book) {
    os << book.get_title() << endl;
    os << book.get_auth_name() << ' ' << book.get_auth_surname() << endl;
    os << book.get_isbn() << endl;
    os << book.get_date() << endl;
    return os;
}