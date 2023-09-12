#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Book class
class Book {
private:
    string title;
    string author;
    int isbn;
    bool available;

public:
    Book(string _title, string _author, int _isbn) {
        title = _title;
        author = _author;
        isbn = _isbn;
        available = true;
    }

    // Getter methods
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getISBN() const {
        return isbn;
    }

    bool isAvailable() const {
        return available;
    }

    // Mark the book as borrowed
    void borrowBook() {
        available = false;
    }

    // Mark the book as returned
    void returnBook() {
        available = true;
    }
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    // Add a book to the library
    void addBook(Book book) {
        books.push_back(book);
    }

    // Search for a book by title
    Book* searchByTitle(string title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    // Search for a book by author
    vector<Book*> searchByAuthor(string author) {
        vector<Book*> results;
        for (auto& book : books) {
            if (book.getAuthor() == author) {
                results.push_back(&book);
            }
        }
        return results;
    }

    // Borrow a book
    void borrowBook(Book* book) {
        if (book && book->isAvailable()) {
            book->borrowBook();
            cout << "Book '" << book->getTitle() << "' is borrowed." << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    // Return a book
    void returnBook(Book* book) {
        if (book && !book->isAvailable()) {
            book->returnBook();
            cout << "Book '" << book->getTitle() << "' is returned." << endl;
        } else {
            cout << "Invalid book or it is already available." << endl;
        }
    }

    // Display all books in the library
    void displayAllBooks() {
        cout << "Library Catalog:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor()
                 << ", ISBN: " << book.getISBN() << ", Available: " << (book.isAvailable() ? "Yes" : "No") << endl;
        }
    }
};

int main() {
    Library library;

    // Adding some books to the library
    library.addBook(Book("OOP", "Md. Mahadi Hasan", 12));
    library.addBook(Book("Bangla", "Juwel", 123));
    library.addBook(Book("English", "Jihad", 1234));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 12345));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 67890));
    library.addBook(Book("1984", "George Orwell", 54321));

    int choice;
    do {
        cout << "\n***Library Management System***" << endl;
        cout << "1. Search by Title" << endl;
        cout << "2. Search by Author" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Display All Books" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                Book* result = library.searchByTitle(title);
                if (result) {
                    cout << "Book Found: " << result->getTitle() << " by " << result->getAuthor() << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 2: {
                string author;
                cout << "Enter author name: ";
                cin.ignore();
                getline(cin, author);
                vector<Book*> results = library.searchByAuthor(author);
                if (!results.empty()) {
                    cout << "Books Found by " << author << ":" << endl;
                    for (auto& book : results) {
                        cout << "Title: " << book->getTitle() << ", ISBN: " << book->getISBN() << endl;
                    }
                } else {
                    cout << "No books found by " << author << "." << endl;
                }
                break;
            }
            case 3: {
                string title;
                cout << "Enter book title to borrow: ";
                cin.ignore();
                getline(cin, title);
                Book* book = library.searchByTitle(title);
                library.borrowBook(book);
                break;
            }
            case 4: {
                string title;
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                Book* book = library.searchByTitle(title);
                library.returnBook(book);
                break;
            }
            case 5:
                library.displayAllBooks();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
