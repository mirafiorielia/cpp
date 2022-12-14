//#authors group_42:
//@Elia Mirafiori 2008772
//@Davide Iannello 2009661
//@Alberto Celadin 2007950
//
//#date: 21 Nov 2022
//
//#version: 1.0.0

#include "../include/book.h"

using std::cout;
using std::endl;
using std::ostream;
using std::regex;
using std::string;
using std::vector;

// constructor without any argument
Book::Book()
    : isbn{"nnn-nnn-nnn-x"}, title{"plch"}, auth_name{"plch"}, auth_surname{"plch"}, date{Date()}, available{true} {
    if (!check_isbn(isbn)) {
        isbn = "invalid isbn";
    }
}

// constructor that needs auth_name, auth_surname, title and isbn
Book::Book(std::string auth_name, std::string auth_surname, std::string title, std::string isbn)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{Date()}, available{true} {
    if (!check_isbn(isbn)) {
        isbn = "invalid isbn";
    }
}

// constructor that needs auth_name, auth_surname, title, isbn, date and availability
Book::Book(std::string auth_name, std::string auth_surname, std::string title,
           std::string isbn, Date date = Date(), bool available = true)
    : isbn{isbn}, title{title}, auth_name{auth_name}, auth_surname{auth_surname}, date{date}, available{available} {
    if (!check_isbn(isbn)) {
        isbn = "invalid isbn";
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

// set isbn
void Book::set_isbn(const string& isbn) {
    if (check_isbn(isbn)) this->isbn = isbn;
}

// set title
void Book::set_title(const string& title) {
    this->title = title;
}

// set auth_name
void Book::set_auth_name(const string& auth_name) {
    this->auth_name = auth_name;
}

// set auth_surname
void Book::set_auth_surname(const string& auth_surname) {
    this->auth_surname = auth_surname;
}

// set date
void Book::set_date(const Date& date) {
    this->date = date;
}

// set available to false if the book is available
void Book::borrow_book() {
    if (is_available()) {
        cout << "book borrowed correctly" << endl;
        set_availability(false);
        return;
    }

    cout << "book not available" << endl;
    return;
}

// set available to true if the book is not available
void Book::return_book() {
    if (!is_available()) {
        cout << "book returned correctly" << endl;
        set_availability(true);
        return;
    }

    cout << "book is already returned" << endl;
    return;
}

// set available
void Book::set_availability(const bool& available) {
    this->available = available;
}

/*
checks if the isbn inserted is valid or not
the isbn should look like n-n-n-x with
n = int number with size of 3
x = char that can be a number or a letter with size of 1
example: 000-000-000-A
*/
bool Book::check_isbn(const string& isbn) const {
    vector<string> tokens = split(isbn, '-');

    if (tokens.size() != 4) return false;  // check isbn components

    for (int i = 0; i < tokens.size(); i++) {
        if (i < 3) {
            string token = tokens.at(i);

            if (token.length() != 3) return false;

            for (char c : token)
                if (!isdigit(c)) return false;

        } else {
            string token = tokens.at(i);

            if (token.length() != 1) return false;

            return iswalnum(token[0]) != 0;
        }
    }

    return true;
}

// helper function to split our isbn var with a delimiter
vector<string> Book::split(const string& isbn, const char delimiter) const {
    vector<string> tokens;  // init vector with tokens
    string temp = "";       // temp token

    // iterate throw the length of the isbn
    for (int i = 0; i < (int)isbn.length(); i++) {
        // If current char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        if (isbn[i] != delimiter) {
            temp += isbn[i];
        } else {
            tokens.push_back(temp);
            temp = "";
        }
    }

    tokens.push_back(temp);
    return tokens;
}

// checks if the date is valid or not
bool Book::check_date() const {
    return get_date().is_valid();
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
title -> Una cosa divertente che non far?? mai pi??
author's name surname -> David Foster Wallace
isbn -> 878-521-837-4
date -> 26 9 2000
*/
ostream& operator<<(ostream& os, const Book& book) {
    os << book.get_title() << endl;
    os << book.get_auth_name() << ' ' << book.get_auth_surname() << endl;
    os << book.get_isbn() << endl;
    os << book.get_date() << endl;
    return os;
}