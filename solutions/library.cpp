#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

/*
Functionality
    - Borrow books
    - Access records of what books have been borrowed and returned when
    - Access records of what books a user has borrowed
    - List of overdue books
    - List of currently rented out books
    - List of available books
    - List of users with overdue book
    - List of users with currently rented out book
    - List of all users
    - Add a book to library
    - Add a user to library
*/

// DECLARATIONS
class Library;
class Book;
class User;
class Student;
class Professor;

class Library {
public:
    Library() {}
    vector<Book*> overdueBooks() const;
    vector<Book*> borrowedBooks() const;
    void addBook(Book* _book);
    void borrowBook(Book* _book, User* _user);
private:
    vector<User*> m_users;
    multiset<Book*> m_books;
};
