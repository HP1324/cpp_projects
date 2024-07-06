
#include "Contact.h"
#include<limits>
void showMenu();
int main()
{
    vector<Contact> contacts;
    ofstream contactFile;
    showMenu(); 
    int input;
    int vcPointer = -1;
    do
    {
        cin >> input;
        switch (input)
        {
        case 1:
        {
            contacts.push_back(addContact());
            ++vcPointer;
            contacts[vcPointer].addToFile();
            showMenu();
            break;
        }
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
                cout << "Contact found at index " << result + 1 << '\n';
                contacts[result].print(result);
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
            // cin.ignore();
            showMenu();
            break;
        case 6:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid Input! try again...\n";
            break;
        }
        cin.clear();
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
