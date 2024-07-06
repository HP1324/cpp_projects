#include "Contact.h"
const char *const CONTACT_FILE = "contact_data.txt";

Contact addContact()
{
    Contact contact;
    while (true)
    {
        cout << "Enter contact details: ";
        cout << "First name: ";
        getline(cin, contact.firstName);
        cout << "Last name:  ";
        getline(cin, contact.lastName);
        cout << "Phone Number: ";
        getline(cin, contact.phoneNumber);
        cout << "Email : ";
        getline(cin, contact.emailAddress);
        if (contact.isValidContact())
            break;
        else
            cout << "Invalid contact! try again...\n";
    }
    cout << "Contact added successfully\n";
    return contact;
}
void viewContacts(vector<Contact> contacts)
{
    contacts = loadContacts();

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
            return i;
        }
    }
    return -1;
}

void deleteContact(int index, vector<Contact> &contacts)
{
    if (contacts.empty())
        cout << "No contacts to delete!\n";
    else if (index > 0 && index <= static_cast<int>(contacts.size()))
    {
        contacts.erase(contacts.begin() + (index - 1));
        cout << "Contact deleted succesfully!\n";
    }
    else
    {
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
vector<Contact> loadContacts()
{
    ifstream readContacts(CONTACT_FILE, ios::in);
    vector<Contact> contacts;
    if (!readContacts)
        cout << "Can't open the file for reading\n";

    string line;
    string delimiter = "; ";

    while (getline(readContacts, line))
    {
        Contact contact;
        size_t pos = 0;
        int tokenCounter = 0;
        while ((pos = line.find(delimiter)) != string::npos)
        {
            string token = line.substr(0, pos);
            switch (tokenCounter)
            {
            case 0:
                contact.firstName = token;
                break;
            case 1:
                contact.lastName = token;
                break;
            case 2:
                contact.phoneNumber = token;
                break;
            }
            line.erase(0, pos + delimiter.length());
            ++tokenCounter;
        }
        // The last has to be dealt with separately
        if (tokenCounter == 3)
        {
            contact.emailAddress = line;
        }
        contacts.push_back(contact);
    }
    readContacts.close();
    return contacts;
}
void Contact::print(int i) const
{
    cout << "  | First Name   : " << firstName << "\n";
    cout << i + 1 << " | Last Name    : " << lastName << "\n";
    cout << "  | Phone Number : " << phoneNumber << "\n";
    cout << "  | Email Address: " << emailAddress << "\n\n";
}
bool Contact::isValidContact()
{
    regex namePattern("^[A-Za-z\\s-]+$");
    regex phonePattern("^(?:\\+91|91)?[-\\s]?[7-9]\\d{4}[-\\s]?\\d{5}$");
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return (regex_match(firstName, namePattern) && regex_match(lastName, namePattern) && regex_match(phoneNumber, phonePattern) && regex_match(emailAddress, emailPattern));
}
void addToFile(vector<Contact> &contacts, int i)
{
    ofstream contactFile{CONTACT_FILE, ios::app};
    contactFile.seekp(0, ios::beg);
    if (!contactFile)
        cout << "File couldn't be opened for writing\n";
    else
    {
        contactFile << contacts[i].firstName << "; ";
        contactFile << contacts[i].lastName << "; ";
        contactFile << contacts[i].phoneNumber << "; ";
        contactFile << contacts[i].emailAddress << "\n";
    }
    contactFile.close();
}
