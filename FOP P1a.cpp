#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>  // For character checks
#include <regex>   // For regex password validation

using namespace std;

// A map to store user credentials (ID, Password, and Name)
unordered_map<int, pair<string, string>> userCredentials;  // User ID -> {Name, Password}

// Function to check if the password is strong
bool isStrongPassword(const string& password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return false;
    }

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    for (char c : password) {
        if (islower(c)) hasLower = true;
        if (isupper(c)) hasUpper = true;
        if (isdigit(c)) hasDigit = true;
        if (!isalnum(c)) hasSpecial = true;
    }

    if (hasLower && hasUpper && hasDigit && hasSpecial) {
        return true;
    } else {
        cout << "Password must contain at least one lowercase letter, one uppercase letter, one digit, and one special character." << endl;
        return false;
    }
}

// Function to register a new user
void registerUser(int userId, const string& name, const string& password) {
    if (userCredentials.find(userId) != userCredentials.end()) {
        cout << "User ID " << userId << " already exists. Please choose a different ID." << endl;
    } else {
        userCredentials[userId] = make_pair(name, password);
        cout << "User " << name << " (ID: " << userId << ") registered successfully!" << endl;
    }
}

// Function to authenticate a user
bool authenticate(int userId, const string& password) {
    if (userCredentials.find(userId) != userCredentials.end()) {
        if (userCredentials[userId].second == password) {
            return true;  // Authentication successful
        }
    }
    return false;  // Authentication failed
}

// Function to handle user login attempts
bool loginUser() {
    int userId;
    string password;
    int attemptCount = 0;  // Track the number of login attempts

    while (attemptCount < 3) {  // Limit to 3 attempts
        cout << "Enter your User ID: ";
        cin >> userId;

        cout << "Enter your password: ";
        cin >> password;

        if (authenticate(userId, password)) {
            cout << "Login successful! Welcome, " << userCredentials[userId].first << "!" << endl;
            return true;  // Successful login
        } else {
            cout << "Incorrect User ID or password. Please try again." << endl;
            attemptCount++;
        }
    }

    cout << "Too many failed attempts. Access denied." << endl;
    return false;  // Failed login
}

// Function to get user input for registration
void registerNewUser() {
    int userId;
    string name, password;

    cout << "Enter your new User ID: ";
    cin >> userId;
    cin.ignore();  // To ignore the newline character from previous input

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your password: ";
    cin >> password;

    // Validate the password strength
    if (isStrongPassword(password)) {
        registerUser(userId, name, password);
    } else {
        cout << "Please choose a stronger password and try again." << endl;
    }
}

// Function to display the main menu
void displayMenu() {
    cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
}

int main() {
    int choice;

    cout << "Welcome to the Hospital Management System!" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            // Register a new user
            registerNewUser();
        } else if (choice == 2) {
            // Login with existing user ID and password
            loginUser();
        } else if (choice == 3) {
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
