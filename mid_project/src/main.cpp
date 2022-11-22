#include <iostream>

#include "book.h"

/*
#authors group_42:
@Elia Mirafiori 2008772
@Davide Iannello 2009661
@Alberto Celadin 2007950

#date: 21 Nov 2022

#version: 1.0.0
*/
int main() {
    std::vector<Book> shelf(10);  // book vector

    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "878-521-837-4");  // default book

    // TEST CODE
    shelf[0].set_title("TEST VECTOR");
    shelf[0].set_auth_name("IO");
    shelf[0].set_auth_surname("SEMPRE IO");
    shelf[0].set_isbn("758-865-787-A");
    shelf[0].set_date(Date(2022, 10, 22));
    shelf[0].set_availability(true);

    std::cout << "shelf[0] -> " << shelf[0];
    std::cout << "shelf[1] -> " << shelf[1];

    Book book2("Elia", "Mirafiori", "C++ fatto easy", "888-521-837-E");  // should be equal
    Book book3("Elia", "Mirafiori", "C++ fatto easy", "888-521-837-E");  // should be equal

    Book book4("Davide", "Mirafiori", "C++ fatto easy", "a88-521-837-E");   // should give invalid isbn
    Book book5("Alberto", "Mirafiori", "C++ fatto easy", "988-521-837-+");  // should give invalid isbn

    Book book6("Pippo", "Baudo", "C++ fatto easy", "888-521-321-E");    // test borrow and return book
    Book book7("Mike", "Wazowsky", "C++ fatto easy", "777-521-123-E");  // test borrow and return book

    Book book8("Date book", "Balala", "C++ fatto easy", "777-521-123-E", Date(2000, 9, 26), true);  // test date and availability
    Book book9("Dorian", "Grey", "C++ fatto easy", "323-521-123-E", Date(2001, 11, 20), false);     // test date and availability
    Book book10("Dorian", "Grey", "C++ fatto easy", "323-521-123-E", Date(1000, 0, 35), false);     // test date and availability

    std::cout << "(my_favourite_book == book2) -> " << (my_favourite_book == book2) << std::endl;  // test overload ==
    std::cout << "(book2 == book3) -> " << (book2 == book3) << std::endl;                          // test overload ==
    std::cout << "book2 -> " << book2 << std::endl;                                                // test overload <<

    // tests to check the isbn
    std::cout << "book3 check isbn -> " << book3.check_isbn(book3.get_isbn()) << std::endl;
    std::cout << "book4 check isbn -> " << book4.check_isbn(book4.get_isbn()) << std::endl;
    std::cout << "book5 check isbn -> " << book5.check_isbn(book5.get_isbn()) << std::endl;

    // tests to borrow or return a book
    book6.borrow_book();
    book6.return_book();
    std::cout << "book6 is_available -> " << book6.is_available() << std::endl;

    book7.return_book();
    book7.borrow_book();
    std::cout << "book7 is_available -> " << book7.is_available() << std::endl;

    // test date
    std::cout << "book8 date -> " << book8.get_date() << std::endl;
    std::cout << "book9 date -> " << book9.get_date() << std::endl;
    std::cout << "book10 date -> " << book10.get_date() << std::endl;

    Book book11{"Elia", "Foster Wallace", "Una cosa divertente che non farò mai più", "878-521-837-4"};  // default book

    return 0;
}

/*
unix commands to compile, build and run this project:

g++ -c main.cpp book.cpp date.cpp enums.cpp
g++ -o main main.o book.o date.o enums.o
./main

OR

g++ -o main main.cpp book.cpp date.cpp enums.cpp
./main

unix command to build with cmake:
cmake -Bbuild -DCMAKE_BUILD_TYPE=Release
*/