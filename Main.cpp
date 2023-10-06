#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;


// Compile this code g++ -o Main Main.cpp
// ./Main    


class Person {
public:
    Person() : firstName(""), lastName(""), phoneNumber("") {}

    Person(const string& firstName, const string& lastName, const string& phoneNumber)
        : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber) {}

    string getFullName() const {
        return lastName + " " + firstName;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

private:
    string firstName;
    string lastName;
    string phoneNumber;
};

class Book {
public:
    void addPerson(const Person& person) {
        // Create a key for the person using their last name and first name
        string key = person.getFullName();
        phoneBook[key] = person;
    }

    void displayPhoneBook() const {
        cout << "Phone Book:" << endl;
        for (const auto& entry : phoneBook) {
            cout << "Name: " << entry.first << ", Phone: " << entry.second.getPhoneNumber() << endl;
        }
    }

    // Search for a person by their full name
    void searchPerson(const string& fullName) const {
        auto it = phoneBook.find(fullName);
        if (it != phoneBook.end()) {
            cout << "Name: " << it->first << ", Phone: " << it->second.getPhoneNumber() << endl;
        } else {
            cout << "Person not found in the phone book." << endl;
        }
    }

private:
    map<string, Person> phoneBook;
};

class UserInterface {
public:
    void run() {
        char choice;
        Book phoneBook;

        do {
            cout << "Phone Book Menu:" << endl;
            cout << "1. Add Person" << endl;
            cout << "2. Display Phone Book" << endl;
            cout << "3. Search Person" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case '1':
                    addPerson(phoneBook);
                    break;
                case '2':
                    phoneBook.displayPhoneBook();
                    break;
                case '3':
                    searchPerson(phoneBook);
                    break;
                case '4':
                    cout << "Exiting Phone Book........................" << endl;
                    cout << ".........................................." << endl;

                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != '4');
    }

private:
    void addPerson(Book& phoneBook) {
        string firstName, lastName, phoneNumber;

        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;

        Person person(firstName, lastName, phoneNumber);
        phoneBook.addPerson(person);
        cout << "Person added to the phone book." << endl;
    }

    void searchPerson(const Book& phoneBook) {
        string fullName;
        cout << "Enter Full Name (Last First): ";
        cin.ignore();
        getline(cin, fullName);
        phoneBook.searchPerson(fullName);
    }
};

int main() {
    UserInterface ui;
    ui.run();
    return 0;
}

//THIS CODE WAS DEVELOPED by
// Mabon Ninan, MKhan, MFZ
// UCDasec.