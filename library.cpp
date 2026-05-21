#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    // Constructor
    Book() {
        bookID = 0;
        title = "";
        author = "";
        isIssued = false;
    }

    // Add book details
    void addBook(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        isIssued = false;
    }

    // Display book details
    void displayBook() {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;

        if (isIssued)
            cout << "\nStatus: Issued";
        else
            cout << "\nStatus: Available";

        cout << "\n----------------------";
    }

    // Search by ID
    bool searchBook(int id) {
        return (bookID == id);
    }

    // Issue book
    void issueBook() {
        if (isIssued) {
            cout << "\nBook is already issued!";
        } else {
            isIssued = true;
            cout << "\nBook issued successfully!";
        }
    }

    // Return book
    void returnBook() {
        if (!isIssued) {
            cout << "\nBook was not issued!";
        } else {
            isIssued = false;
            cout << "\nBook returned successfully!";
        }
    }
};

int main() {
    Book library[100];

    int count = 0;
    int choice;

    while (true) {
        cout << "\n====== Library Management System ======";
        cout << "\n1. Add Book";
        cout << "\n2. Display All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;

            cout << "\nEnter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            library[count].addBook(id, title, author);
            count++;

            cout << "\nBook added successfully!";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo books available!";
            } else {
                for (int i = 0; i < count; i++) {
                    library[i].displayBook();
                }
            }
        }

        else if (choice == 3) {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to search: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i].searchBook(id)) {
                    library[i].displayBook();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nBook not found!";
            }
        }

        else if (choice == 4) {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to issue: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i].searchBook(id)) {
                    library[i].issueBook();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nBook not found!";
            }
        }

        else if (choice == 5) {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to return: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (library[i].searchBook(id)) {
                    library[i].returnBook();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nBook not found!";
            }
        }

        else if (choice == 6) {
            cout << "\nExiting program...";
            break;
        }

        else {
            cout << "\nInvalid choice!";
        }
    }

    return 0;
}