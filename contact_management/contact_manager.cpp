#include <iostream>
#include <vector>
using namespace std;
class Contact;
void showMenu();
Contact addContact();
int searchContact(string searchKey, const vector<Contact> &contacts);
void viewContacts(const vector<Contact> &contacts);
void deleteContact(int index, vector<Contact> &contacts);
void editContact(int index, vector<Contact> &contacts);
class Contact
{
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string emailAddress;

public:
    friend Contact addContact();
    friend void viewContacts(const vector<Contact> &contacts);
    friend int searchContact(string searchKey, const vector<Contact> &contacts);
    friend void editContact(int index, vector<Contact> &contacts);
    void print()
    {
        cout << "First Name   : " << firstName << '\n';
        cout << "Last Name    : " << lastName << '\n';
        cout << "Phone Number : " << phoneNumber << '\n';
        cout << "Email Address: " << emailAddress << '\n';
    }
};

int main()
{
    vector<Contact> contacts;

    // cout << it;
    showMenu();
    int input;
    do
    {
        cin >> input;
        switch (input)
        {
        case 1:
            contacts.push_back(addContact());
            showMenu();
            break;
        case 2:
            viewContacts(contacts);
            showMenu();
            break;
        case 3:
        {
            string searchKey;
            cout << "Enter one of the following to search \n (First Name, Last Name, Phone Number, Email Address): ";
            cin.ignore();
            getline(cin, searchKey);
            int result = searchContact(searchKey, contacts);
            if (result == -1)
                cout << "Contact not found!";
            else
            {
                cout << "Contact found at index " << result << '\n';
                contacts[result - 1].print();
            }
            showMenu();
            break;
        }
        case 4:
        {
            if (contacts.empty())
                cout << "No contacts to delete!\n";
            else
            {
                viewContacts(contacts);
                cout << "Enter index of the contact to delete: ";
                int index;
                cin >> index;
                deleteContact(index, contacts);
                cout << "Contact deleted successfully!\n";
            }

            // cin.ignore();
            showMenu();
            break;
        }
        case 5:
            if (contacts.empty())
                cout << "\nNo contacts to change!\n";
            else
            {
                viewContacts(contacts);
                cout << "Enter index of the contact to edit: ";
                int index;
                cin >> index;
                editContact(index, contacts);
            }
            //cin.ignore();
            showMenu();
            break;
        }
        case 6:
        cout << "Exiting...";
            break;

    } while (input != 6);
    return 0;
}
void showMenu()
{
    cout << "Contact book menu:\n\n";
    cout << "1. Add Contacts\n";
    cout << "2. View Contacts\n";
    cout << "3. Search Contacts\n";
    cout << "4. Delete Contact\n";
    cout << "5. Edit Contact\n";
    cout << "6. Exit\n\n";

    cout << "Please choose an option(1-6): ";
}
Contact addContact()
{
    Contact contact;
    cin.ignore();
    cout << "First name: ";
    getline(cin, contact.firstName);
    cout << "Last name:  ";
    getline(cin, contact.lastName);
    cout << "Phone Number: ";
    getline(cin, contact.phoneNumber);
    cout << "Email : ";
    getline(cin, contact.emailAddress);

    cout << "Contact added successfully\n";
    return contact;
}
void viewContacts(const vector<Contact> &contacts)

{
    if (contacts.empty())
        cout << "Contact list empty! add some contacts first\n";
    else
    {
        cout << "\n*****Contact List*****\n\n";
        for (int i = 0; i < (int)contacts.size(); ++i)
        {
            // cout << "index\tFirst Name\tSecond Name\tPhone Number\tEmail Address\n";
            // cout << i + 1 << "\n";

            cout << "  | First Name   : " << contacts[i].firstName << "\n";
            cout << i + 1 << " | Last Name    : " << contacts[i].lastName << "\n";
            cout << "  | Phone Number : " << contacts[i].phoneNumber << "\n";
            cout << "  | Email Address: " << contacts[i].emailAddress << "\n\n";
        }
        cout << "\n\n";
    }
}

int searchContact(string searchKey, const vector<Contact> &contacts)

{
    for (auto i = 0; i < contacts.size(); ++i)
    {
        if (searchKey == contacts[i].firstName || searchKey == contacts[i].lastName || searchKey == contacts[i].phoneNumber || searchKey == contacts[i].emailAddress)
        {
            return i + 1;
        }
    }
    return -1;
}

void deleteContact(int index, vector<Contact> &contacts)
{
    contacts.erase(contacts.begin() + (index - 1));
}
void editContact(int index, vector<Contact> &contacts)
{
    if (contacts.empty())
        cout << "\nNo contacts to change!\n";
    else
    {
        cin.ignore();
        cout << "First name: ";
        getline(cin, contacts[index-1].firstName);
        cout << "Last name:  ";
        getline(cin, contacts[index-1].lastName);
        cout << "Phone Number: ";
        getline(cin, contacts[index-1].phoneNumber);
        cout << "Email : ";
        getline(cin, contacts[index-1].emailAddress);
        cout << "\nContact edited successfully!\n";
    }
    
}