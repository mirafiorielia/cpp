#include <iostream>

#include "book.h"
#include "date.h"

int main() {
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "8878-521-837-4");
    Book my_favourite_book2("Elia", "Mirafiori", "C++ fatto easy", "888-521-837-5");

    std::cout << (my_favourite_book == my_favourite_book2) << std::endl;
    std::cout << my_favourite_book2;

    return 0;
}