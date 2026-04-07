#include <iostream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll 
             << " Name: " << name 
             << " Marks: " << marks << endl;
    }
};

int main() {
    Student s[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                s[count].input();
                count++;
                break;

            case 2:
                for (int i = 0; i < count; i++) {
                    s[i].display();
                }
                break;

            case 3: {
                int roll, found = 0;
                cout << "Enter roll to search: ";
                cin >> roll;

                for (int i = 0; i < count; i++) {
                    if (s[i].roll == roll) {
                        s[i].display();
                        found = 1;
                    }
                }

                if (!found)
                    cout << "Student not found!\n";
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}