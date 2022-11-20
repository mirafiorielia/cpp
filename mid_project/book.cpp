#include "book.h"

using std::endl;
using std::ostream;
using std::regex;
using std::string;

Book::Book()
    : isbn{"nnn-nnn-nnn-x"}, title{"dummy"}, auth_name{"dummy"}, auth_surname{"dummy"}, date{Date()}, available{true} {
}

Book::Book(std::string auth_name, std::string auth_surname, std::string title, std::string isbn)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{Date()}, available{true} {
}

Book::Book(std::string auth_name, std::string auth_surname, std::string title,
           std::string isbn, Date date = Date(), bool available = true)
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

Date Book::get_date() const {
    return date;
}

bool Book::is_available() const {
    return available;
}

bool Book::borrow_book() {
    if (is_available()) available = false;
    return available;
}

bool Book::return_book() {
    if (!is_available()) available = true;
    return available;
}

bool Book::check_isbn() {
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            string token = isbn.substr(i, isbn.find('-'));

            if (token.length() != 3) return false;

            for (char c : token)
                if (!isdigit(c)) return false;

        } else {
            string token = isbn.substr(i, isbn.find('-'));

            if (token.length() != 1) return false;

            return !regex_match(token, regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
        }
    }
    return true;
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