#include <iostream>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool issued;
    string borrower;

public:
    Book(string t, string a) {
        title = t;
        author = a;
        issued = false;
        borrower = "";
    }

    void display(int index) {
        cout << index + 1 << ". "
             << "Title: " << title
             << " | Author: " << author
             << " | Status: "
             << (issued ? "Issued to " + borrower : "Available")
             << endl;
    }

    void issueBook(string name) {
        if (!issued) {
            issued = true;
            borrower = name;
            cout << "Book issued successfully to " << name << "!\n";
        } else {
            cout << "Book already issued to " << borrower << ".\n";
        }
    }

    void returnBook() {
        if (issued) {
            cout << "Book returned successfully from " << borrower << ".\n";
            issued = false;
            borrower = "";
        } else {
            cout << "Book was not issued.\n";
        }
    }

    string getTitle() {
        return title;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook() {
        string title, author;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(title, author));
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }

        for (size_t i = 0; i< books.size(); i++) {
            books[i].display(i);
        }
    }

    void issueBook() {
        size_t num;
        viewBooks();
        cout << "Enter book number to issue: ";
        cin >> num;

        if (num > 0 && num <= books.size()) {
            string name;
            cin.ignore();
            cout << "Enter Borrower Name: ";
            getline(cin, name);
            books[num - 1].issueBook(name);
        } else {
            cout << "Invalid book number!\n";
        }
    }

    void returnBook() {
        size_t num;
        viewBooks();
        cout << "Enter book number to return: ";
        cin >> num;

        if (num > 0 && num <= books.size()) {
            books[num - 1].returnBook();
        } else {
            cout << "Invalid book number!\n";
        }
    }

    void searchBook() {
        string title;
        cin.ignore();
        cout << "Enter title to search: ";
        getline(cin, title);

        for (size_t i = 0; i<books.size(); i++) {
            if (books[i].getTitle() == title) {
                books[i].display(i);
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.viewBooks(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.searchBook(); break;
            case 6: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}