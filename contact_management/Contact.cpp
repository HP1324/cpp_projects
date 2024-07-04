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
            contacts[i].print(i);
        }
        cout << "*****List End*****";
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
    if(contacts.empty()) cout << "No contacts to delete!\n";
    else if (index > 0 && index <= static_cast<int>(contacts.size()))
    {
        contacts.erase(contacts.begin() + (index - 1));
        cout << "Contact deleted succesfully!\n";
    }else{
        cout << "Invalid index!\n";
    }
}
void editContact(int index, vector<Contact> &contacts)
{
    if (index > 0 && index <= (int)contacts.size())
    {
        cout << "Editing contact: " << index << '\n';
        contacts[index - 1] = addContact();
    }
    else
    {
        cout << "Invalid index!\n";
    }
}
void Contact::print(int i) const
{
    cout << "  | First Name   : " << firstName << "\n";
    cout << i + 1 << " | Last Name    : " << lastName << "\n";
    cout << "  | Phone Number : " << phoneNumber << "\n";
    cout << "  | Email Address: " << emailAddress << "\n\n";
}