#ifndef CONTACT_H
#define CONTACT_H 

#include<iostream>
#include<vector>
using namespace std;
class Contact;
Contact addContact();
void viewContacts(const vector<Contact> &contacts);
int searchContact(string searchKey, const vector<Contact> &contacts);
void editContact(int index, vector<Contact> &contacts);
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
    friend void editContact(int index, vector<Contact> &contacts);
    void print()
    {
        cout << "First Name   : " << firstName << '\n';
        cout << "Last Name    : " << lastName << '\n';
        cout << "Phone Number : " << phoneNumber << '\n';
        cout << "Email Address: " << emailAddress << '\n';
    }
};

#endif