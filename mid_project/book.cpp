#include "book.h"

using std::cout;
using std::endl;
using std::ostream;
using std::regex;
using std::string;

// constructor without any argument
Book::Book()
    : isbn{"nnn-nnn-nnn-x"}, title{"dummy"}, auth_name{"dummy"}, auth_surname{"dummy"}, date{Date()}, available{true} {
    if (!check_isbn()) {
        isbn = "invalid isbn";
        cout << get_isbn() << endl;
    }
}

// constructor that needs auth_name, auth_surname, title and isbn
Book::Book(std::string auth_name, std::string auth_surname, std::string title, std::string isbn)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{Date()}, available{true} {
    if (!check_isbn()) {
        isbn = "invalid isbn";
        cout << get_isbn() << endl;
    }
}

// constructor that needs auth_name, auth_surname, title, isbn, date and availability
Book::Book(std::string auth_name, std::string auth_surname, std::string title,
           std::string isbn, Date date = Date(), bool available = true)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{date}, available{available} {
    if (!check_isbn()) {
        isbn = "invalid isbn";
        cout << get_isbn() << endl;
    }
}

// returns isbn
string Book::get_isbn() const {
    return isbn;
}

// returns the title
string Book::get_title() const {
    return title;
}

// returns the author name
string Book::get_auth_name() const {
    return auth_name;
}

// returns the author surname
string Book::get_auth_surname() const {
    return auth_surname;
}

// returns the date of copyright
Date Book::get_date() const {
    return date;
}

// returns if the book is available
bool Book::is_available() const {
    return available;
}

// set available to false if the book is available
bool Book::borrow_book() {
    if (is_available()) available = false;
    return available;
}

// set available to true if the book is not available
bool Book::return_book() {
    if (!is_available()) available = true;
    return available;
}

/*
checks if the isbn inserted is valid or not
the isbn should look like n-n-n-x with
n = int number with size of 3
x = char that can be a number or a letter with size of 1
example: 000-000-000-A
*/
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

// overload "==" operator that checks if two books are the same based on their isbn
bool Book::operator==(const Book& book) const {
    return isbn == book.get_isbn();
}

// overload "!=" operator that checks if two books are NOT the same based on their isbn
bool Book::operator!=(const Book& book) const {
    return isbn != book.get_isbn();
}

/*
overload ostream "<<" operator to output the book informations

output example:
title -> Una cosa divertente che non farò mai più
author's name surname -> David Foster Wallace
isbn -> 878-521-837-4
date ->
*/
ostream& operator<<(ostream& os, const Book& book) {
    os << book.get_title() << endl;
    os << book.get_auth_name() << ' ' << book.get_auth_surname() << endl;
    os << book.get_isbn() << endl;
    os << book.get_date() << endl;
    return os;
}