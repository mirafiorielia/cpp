#include <iostream>
#include <string>

class Book {
   public:
    // constructors
    Book();
    Book(std::string isbn, std::string title, std::string auth_name,
         std::string auth_surname, int date, bool available);

    // destructor
    ~Book();
    // get general info funcs
    std::string get_isbn() const;          // return book isbn
    std::string get_title() const;         // return book title
    std::string get_auth_name() const;     // return book author name
    std::string get_auth_surname() const;  // return book author surname
    int get_date() const;                  // return book copyright date
    bool is_available() const;             // return if book is available

    // usefull funcs for the user
    bool borrow_book();  // borrow book from library
    bool return_book();  // return book to the library
    // bool is_isbn_valid(); // check book isbn

    bool operator==(const Book &book) const;
    bool operator!=(const Book &book) const;
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

   private:
    std::string isbn, title, auth_name, auth_surname;  // general info
    int date;                                          // TODO switch to Date class
    bool available;                                    // book status
};
