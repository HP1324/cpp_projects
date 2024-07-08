#include "Contact.h"

const std::string DELIM = "; ";
const char *const CONTACT_FILE = "contact_data.txt";

std::vector<Contact> contacts = loadContacts();

int Contact::idCounter = 0;
Contact::Contact() {};
void Contact::set(std::string firstName, std::string lastName,std::string phoneNumber, std::string emailAddress)
{
    //id = ++idCounter;
    this->firstName = firstName;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->emailAddress = emailAddress;
}
void ignoreLine() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
Contact addContact()
{
    Contact contact;
    while (true)
    {
        std::string firstName, lastName,phoneNumber,emailAddress;
        std::cout << "Enter contact details: ";
        std::cout << "First name: ";
        std::getline(std::cin, firstName);
        std::cout << "Last name:  ";
        std::getline(std::cin, lastName);
        std::cout << "Phone Number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Email : ";
        std::getline(std::cin, emailAddress);
        contact.set(firstName, lastName, phoneNumber, emailAddress);
        if (contact.isValidContact()) {
        contact.id += 1;
            break;
        }
        else
            std::cout << "Invalid contact! try again...\n";
    }
    std::cout << "Contact added successfully\n";
    return contact;
}
void viewContacts()
{
    if (contacts.empty())
        std::cout << "Contact list empty! add some contacts first\n";
    else
    {
        std::cout << "\n*****Contact List*****\n\n";
        for (int i = 0; i < (int)contacts.size(); ++i)
        {
            contacts[i].print();
        }
        std::cout << "*****List End*****";
        std::cout << "\n\n";
    }
}

int searchContact( std::string searchKey, const std::vector<Contact> &contacts)
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

void deleteContact(int index, std::vector<Contact> &contacts)
{
    if (contacts.empty())
        std::cout << "No contacts to delete!\n";
    else if (index > 0 && index <= static_cast<int>(contacts.size()))
    {
        contacts.erase(contacts.begin() + (index - 1));
        std::cout << "Contact deleted succesfully!\n";
    }
    else
    {
        std::cout << "Invalid index!\n";
    }
}
void editContact(std::vector<Contact> &contacts)
{
    if (contacts.empty())
        std::cout << "\nNo contacts to change!\n";
    else
    {
        viewContacts();
        std::cout << "Enter index of the contact to edit: ";
        int index;
        std::cin >> index;
        if (index > 0 && index <= (int)contacts.size()) {
            std::cout << "Editing contact " << index << '\n';
            contacts[index - 1].print();
            contacts[index - 1] = addContact();
            }  
        else { std::cout << "Invalid index!\n"; }
        }
    
}
std::vector<Contact> loadContacts()
{
    std::ifstream readContacts(CONTACT_FILE, std::ios::in);
    std::vector<Contact> contacts;
    if (!readContacts)
        std::cout << "Can't open the file for reading\n";

   std:: string line;

    while (getline(readContacts, line))
    {
        Contact contact;
        size_t pos = 0;
        int tokenCounter = 0;
        while ((pos = line.find(DELIM)) != std::string::npos)
        {
            std::string token = line.substr(0, pos);
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
            line.erase(0, pos + DELIM.length());
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
void Contact::print() const
{
    std::cout << "  | First Name   : " << firstName << "\n";
    std::cout << id << " | Last Name    : " << lastName << "\n";
    std::cout << "  | Phone Number : " << phoneNumber << "\n";
    std::cout << "  | Email Address: " << emailAddress << "\n\n";
}
bool Contact::isValidContact()
{
    std::regex namePattern("^[A-Za-z\\s-]+$");
    std::regex phonePattern("^(?:\\+91|91)?[-\\s]?[7-9]\\d{4}[-\\s]?\\d{5}$");
    std::regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return (std::regex_match(firstName, namePattern) && std::regex_match(lastName, namePattern) && std::regex_match(phoneNumber, phonePattern) && std::regex_match(emailAddress, emailPattern));
}
void saveContacts(std::vector<Contact> &contacts)
{
   std:: ofstream contactFile{CONTACT_FILE, std::ios::out};
    //contactFile.seekp(0, std::ios::beg);
    if (!contactFile)
        std::cout << "File couldn't be opened for writing\n";
    else
    {
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            contactFile << contacts[i].firstName << DELIM;
            contactFile << contacts[i].lastName << DELIM;
            contactFile << contacts[i].phoneNumber << DELIM;
            contactFile << contacts[i].emailAddress << "\n";
        }
    }
    contactFile.close();
}
