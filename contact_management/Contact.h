#ifndef CONTACT_H
#define CONTACT_H 

#include<iostream>
#include<fstream>
#include<regex>
#include<vector>

extern const char* const CONTACT_FILE;

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
    void addToFile();
    void print(int i)const;
    bool isValidContact();
};

#endif