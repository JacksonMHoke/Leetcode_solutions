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

class Book {
public:
    Book(string _name, int _id) {
        m_name = _name;
        m_id = _id;
        m_returnDate = -1;
        m_status = BookStatus::AVAILABLE;
    }

    void borrowFromLibrary(int _returnDate) {
        m_returnDate = _returnDate;
        m_status = BookStatus::BORROWED;
    }

    void returnToLibrary() {
        m_returnDate = -1;
        m_status = BookStatus::AVAILABLE;
    }

    BookStatus getStatus(int _date) {
        if (m_returnDate != -1 && _date > m_returnDate)
            m_status = BookStatus::OVERDUE;
        return m_status;   
    }

    string getName() const { return m_name; }
    int getId() const { return m_id; }
    int getReturnDate() const { return m_returnDate; }

private:
    string m_name;
    BookStatus m_status;
    int m_returnDate;
    int m_id;
};

class User {
public:
    User(string _name, int _id) {
        m_name = _name;
        m_id = _id;
        m_borrowLimit=0;
    }

    bool borrowBook(Book* _book) {
        if (m_books.size() >= m_borrowLimit) {
            cout << "PAST BORROW LIMIT" << endl;
            return false;
        }
        m_books.push_back(_book);
        return true;
    }

    void returnBook(string _name) {
        for (int i = 0; i < m_books.size(); ++i) {
            if (m_books[i]->getName() == _name) {
                m_books[i]->returnToLibrary();
                m_books.erase(m_books.begin()+i);
                return;
            }
        }
    }

    string getName() const { return m_name; }
    int getId() const { return m_id; }
    vector<Book*> getBooks() const { return m_books; }
protected:
    string m_name;
    int m_id;
    int m_borrowLimit;
    vector<Book*> m_books;
};

class Student : public User {
public:
    Student(string _name, int _id) : User(_name, _id) {
        m_borrowLimit = 1;
    }
};

class Professor : public User {
public:
    Professor(string _name, int _id) : User(_name, _id) {
        m_borrowLimit = 2;
    }
};

struct BookCmp {
    bool operator()(Book* lhs, Book* rhs) const {
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

    vector<Book*> availableBooks(int _date) {
        vector<Book*> available;
        for (auto it = m_books.begin(); it != m_books.end(); ++it) {
            if ((*it)->getStatus(_date) == BookStatus::AVAILABLE)
                available.push_back(*it);
        }
        return available;
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
                if (_user->borrowBook(*i)) {
                    (*i)->borrowFromLibrary(_date + m_returnInterval);
                    return true;
                }
                return false;
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

int main() {
    Library lib(10);
    lib.addBook("Harry Potter");
    lib.addBook("Lord of the Rings");
    User* u1 = new Student("Jackson", 0);
    User* u2 = new Professor("Dev", 1);

    cout << "AVAILABLE BOOKS: " << endl;
    vector<Book*> available = lib.availableBooks(0);
    for (Book* book : available)
        cout << book->getName() << endl;

    cout << "BORROWING HARRY POTTER" << endl;
    lib.borrowBook("Harry Potter", u2, 0);
    lib.borrowBook("Lord of the Rings", u2, 0);

    cout << "AVAILABLE BOOKS: " << endl;
    available = lib.availableBooks(0);
    for (Book* book : available)
        cout << book->getName() << endl;

    cout << "BORROWED BOOKS: " << endl;
    vector<Book*> borrowed = lib.borrowedBooks(0);
    for (Book* book : borrowed)
        cout << book->getName() << endl;

    cout << "WAIT 11 DAYS" << endl;
    cout << "OVERDUE BOOKS: " << endl;
    vector<Book*> overdue = lib.overdueBooks(11);
    for (Book* book : overdue)
        cout << book->getName() << endl;

    cout << "RETURN HARRY POTTER" << endl;
    lib.returnBook("Harry Potter", u2);

    cout << "AVAILABLE BOOKS: " << endl;
    available = lib.availableBooks(11);
    for (Book* book : available)
        cout << book->getName() << endl;

    cout << "BORROWED BOOKS: " << endl;
    borrowed = lib.borrowedBooks(11);
    for (Book* book : borrowed)
        cout << book->getName() << endl;

    cout << "OVERDUE BOOKS: " << endl;
    overdue = lib.overdueBooks(11);
    for (Book* book : overdue)
        cout << book->getName() << endl;
}