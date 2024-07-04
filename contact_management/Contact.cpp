#include "Contact.h"
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