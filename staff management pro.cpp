#include <iostream>
#include <string>

using namespace std;

// Maximum number of staff
const int MAX_STAFF = 5;

// Structure to store staff attendance details
struct Staff {
    string name;
    bool isPresent; // true = present, false = absent
};

// Functions to manage attendance
void markAttendance(Staff staffList[], int size, const string& name, bool status) {
    for (int i = 0; i < size; ++i) {
        if (staffList[i].name == name) {
            staffList[i].isPresent = status;
            cout << name << " marked as " << (status ? "Present" : "Absent") << "." << endl;
            return;
        }
    }
    cout << "Staff member " << name << " not found!" << endl;
}

void displayAttendance(const Staff staffList[], int size) {
    cout << "\n--- Attendance Status ---" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << staffList[i].name
             << ", Status: " << (staffList[i].isPresent ? "Present" : "Absent") << endl;
    }
}

int main() {
    // Static array to store staff names and attendance
    Staff staffList[MAX_STAFF] = {
        {"Aschalew", false},
        {"Emebet", false},
        {"Solomon", false},
        {"Ahmed", false},
        {"Hanan", false}
    };

    int choice;
    string name;
    bool status;

    do {
        cout << "\n--- Staff Attendance System ---" << endl;
        cout << "1. Mark Attendance" << endl;
        cout << "2. Display Attendance" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter staff name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter status (1 for Present, 0 for Absent): ";
                cin >> status;
                markAttendance(staffList, MAX_STAFF, name, status);
                break;

            case 2:
                displayAttendance(staffList, MAX_STAFF);
                break;

            case 3:
                cout << "Exiting Attendance System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
