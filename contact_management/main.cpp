
#include "Contact.h"

void showMenu();
int main()
{
    showMenu();
    int input;
    // int vcPointer = -1;
    do
    {
       std::cin >> input;
       ignoreLine();
        switch (input)
        {
        case 1:
        {
            contacts.push_back(addContact());
            showMenu();
            break;
        }
        case 2:
            viewContacts();
            showMenu();
            break;
        case 3:
        {
           std::string searchKey;
            
           std::cout << "Enter one of the following to search \n (First Name, Last Name, Phone Number, Email Address): ";
            std::getline(std::cin, searchKey);
            int result = searchContact(searchKey, contacts);
            if (result == -1)
                std::cout << "Contact not found!";
            else
            {
                std::cout << "Contact found at index " << result + 1 << '\n';
                contacts[result].print();
            }
            showMenu();
            break;
        }
        case 4:
        {
            if (contacts.empty())
                std::cout << "No contacts to delete!\n";
            else
            {
                viewContacts();
                std::cout << "Enter index of the contact to delete: ";
                int index;
               std::cin >> index;
                deleteContact(index, contacts);
            }
            //std::cin.ignore();
            showMenu();
            break;
        }
        case 5:
            editContact(contacts);
            showMenu();
            break;
        case 6:
            std::cout << "Exiting...";
            break;
        default:
            std::cout << "Invalid Input! try again...\n";
            break;
        }

    } while (input != 6);

    saveContacts(contacts);
    return 0;
}
void showMenu()
{
    std::cout << "Contact book menu:\n\n";
    std::cout << "1. Add Contacts\n";
    std::cout << "2. View Contacts\n";
    std::cout << "3. Search Contacts\n";
    std::cout << "4. Delete Contact\n";
    std::cout << "5. Edit Contact\n";
    std::cout << "6. Exit\n\n";

    std::cout << "Please choose an option(1-6): ";
}
