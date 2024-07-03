#include <iostream>
#include <vector>
using namespace std;
class Contact;
void showMenu();
Contact addContact();
int searchContact(string searchKey, const vector<Contact> &contacts);
void viewContacts(const vector<Contact> &contacts);
void deleteContact(int index, vector<Contact> &contacts);
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
            viewContacts(contacts);
            cout << "\nEnter index of the contact you want to delete: ";
            int iDelete;
            cin >> iDelete;
            if (iDelete < 1 && iDelete > (int)contacts.size())
                cout << "Contact not available\n";
            else
            {
                deleteContact(iDelete, contacts);
            }
            cin.ignore();
            showMenu();
            break;
        }
        }

    } while (input != 6);
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
        for (int i = 0; i < (int)contacts.size(); ++i)
        {
            cout << "\n*****Contact List*****\n\n";
            cout << "index\tFirst Name\tSecond Name\tPhone Number\tEmail Address\n";
            cout << i + 1 << "\t  ";
            cout << contacts[i].firstName << "\t\t";
            cout << contacts[i].lastName << "\t\t ";
            cout << contacts[i].phoneNumber << "\t";
            cout << contacts[i].emailAddress << '\n';
        }
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
        else
        {
            return -1;
        }
    }
}

void deleteContact(int index, vector<Contact> &contacts)
{
    contacts.erase(contacts.erase((contacts.begin() + index) - 1));
}