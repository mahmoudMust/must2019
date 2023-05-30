#include <iostream>

#include <string>

using namespace std;

struct Contact {

    string name;

    string phone;

    Contact* next;

};

class Phonebook {

public:

    Phonebook() : head(nullptr) {}

    ~Phonebook() {

        Contact* current = head;

        while (current != nullptr) {

            Contact* next = current->next;

            delete current;

            current = next;

        }

    }

    void addContact(string name, string phone) {

        Contact* newContact = new Contact;

        newContact->name = name;

        newContact->phone = phone;

        newContact->next = head;

        head = newContact;

        cout << "Contact added successfully!" << endl;

    }

    void displayContacts() {

        if (head == nullptr) {

            cout << "Phonebook is empty." << endl;

        }

        else {

            cout << "Contacts:" << endl;

            Contact* current = head;

            while (current != nullptr) {

                cout << current->name << " - " << current->phone << endl;

                current = current->next;

            }

        }

    }

    void searchContact(string name) {

        Contact* current = head;

        bool found = false;

        while (current != nullptr) {

            if (current->name == name) {

                cout << current->name<< " - " << current->phone << endl;

                found = true;

                break;

            }

            current = current->next;

        }

        if (!found) {

            cout << "Contact not found." << endl;

        }

    }

    void deleteContact(string name) {

        if (head == nullptr) {

            cout << "Phonebook is empty." << endl;

        }

        else {

            if (head->name == name) {

                Contact* temp = head;

                head = head->next;

                delete temp;

                cout << "Contact deleted successfully!" << endl;

            }

            else {

                Contact* current = head;

                while (current->next != nullptr && current->next->name != name) {

                    current = current->next;

                }

                if (current->next == nullptr) {

                    cout << "Contact not found." << endl;

                }

                else {

                    Contact* temp = current->next;

                    current->next = current->next->next;

                    delete temp;

                    cout << "Contact deleted successfully!" << endl;

                }

            }

        }

    }

private:

    Contact* head;

};

int main() {

    Phonebook phonebook;

    int choice;

    string name, phone;

    do {

        cout << "\nPhonebook System" << endl;

        cout << "1. Add contact" << endl;

        cout << "2. Display contacts" << endl;

        cout<< "3. Search contact" << endl;

        cout << "4. Delete contact" << endl;

        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter name: ";

            cin >> name;

            cout << "Enter phone number: ";

            cin >> phone;

            phonebook.addContact(name, phone);

            break;

        case 2:

            phonebook.displayContacts();

            break;

        case 3:

            cout << "Enter name to search: ";

            cin >> name;

            phonebook.searchContact(name);

            break;

        case 4:

            cout << "Enter name to delete: ";

            cin >> name;

            phonebook.deleteContact(name);

            break;

        case 5:

            cout << "Exiting..." << endl;

            break;

        default:

            cout << "Invalid choice." << endl;

        }

    } while (choice != 5);

    return 0;

}
