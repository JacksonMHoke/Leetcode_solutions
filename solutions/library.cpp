#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <unordered_set>

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

enum BookStatus { AVAILABLE, BORROWED, OVERDUE };

struct BookCmp {
    bool operator()(Book*& lhs, Book*& rhs) const {
        return lhs->getName() < rhs->getName();
    }
};

class Library {
public:
    Library(int _returnInterval) {
        m_returnInterval = _returnInterval;
        m_bookId = 0;
        m_userId = 0;
    }

    vector<Book*> overdueBooks(int _date) {
        vector<Book*> overdue;
        for (auto it = m_books.begin(); it != m_books.end(); ++it) {
            if ((*it)->getStatus(_date) == BookStatus::OVERDUE)
                overdue.push_back(*it);
        }
        return overdue;
    }

    vector<Book*> borrowedBooks(int _date) {
        vector<Book*> borrowed;
        for (auto it = m_books.begin(); it != m_books.end(); ++it) {
            if ((*it)->getStatus(_date) == BookStatus::BORROWED)
                borrowed.push_back(*it);
        }
        return borrowed;
    }

    void addBook(string _name) {
        m_books.insert(new Book(_name, m_bookId++));
    }

    bool borrowBook(string _bookName, User* _user, int _date) {
        if (m_users.find(_user) == m_users.end())
            m_users.insert(_user);

        Book tempBook(_bookName, -1);
        auto range = m_books.equal_range(&tempBook);

        for (auto i = range.first; i != range.second; ++i) {
            if ((*i)->getStatus(_date)==BookStatus::AVAILABLE) {
                (*i)->borrowFromLibrary(_date + m_returnInterval);
                _user->borrowBook(*i);
                return true;
            }
        }

        return false;
    }

    void returnBook(string _bookName, User* _user) {
        _user->returnBook(_bookName);
    }
private:
    unordered_set<User*> m_users;
    multiset<Book*, BookCmp> m_books;
    int m_bookId;
    int m_userId;
    int m_returnInterval;
};

class Book {
public:
    Book(string _name, int _id) {}
    void borrowFromLibrary(int _returnDate);
    bool returnToLibrary();
    const BookStatus getStatus(int _date);
    string getName() const;
private:
    string m_name;
    BookStatus m_status;
    int m_returnDate;
    int m_id;
};

class User {
public:
    User(string _name, int _id) {}
    void borrowBook(Book* _book);
    void returnBook(string _name);
    string getName() const;
    int getId() const;
    vector<Book*> getBooks() const;
private:
    string m_name;
    int m_id;
    int m_borrowLimit;
    vector<Book*> m_books;
};