#include<iostream>
using namespace std;
class Contact{
    private:
        string firstName;
        string lastName;
        string phoneNumber;
        string emailAddress;
        string address;

};
void showMenu();
void addContact();
void viewContacts();
void deleteContact(int index);
int searchContact(Contact contacts, std::string key);
int main(){
    cout << "Welcome to Contact Manager!\nWhat do you want to do?: ";
    return 0;
}
