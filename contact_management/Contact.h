#ifndef CONTACT_H
#define CONTACT_H

#include <fstream>
#include <iostream>
#include <limits>
#include <regex>
#include <vector>
extern const std::string DELIM;
extern const char* const CONTACT_FILE;

class Contact;

extern std::vector<Contact> contacts;
Contact addContact();
void viewContacts();
int searchContact(std::string searchKey, const std::vector<Contact>& contacts);
void editContact(std::vector<Contact>& contacts);
void deleteContact(int index, std::vector<Contact>& contacts);
void saveContacts(std::vector<Contact>& contacts);
std::vector<Contact> loadContacts();
void ignoreLine();
class Contact
{
private:
    static int idCounter;
    int id;
   std::string firstName;
   std::string lastName;
   std::string phoneNumber;
   std::string emailAddress;

public:
    Contact();
    void set(std::string firstName, std::string lastName, std::string phoneNumber, std::string emailAddress);

    friend Contact addContact();
    friend void viewContacts();
    friend int searchContact(std::string searchKey, const std::vector<Contact>& contacts);
    friend void editContact( std::vector<Contact>& contacts);
    friend std::vector<Contact> loadContacts();
    friend void saveContacts(std::vector<Contact>& contacts);

    void print() const;
    bool isValidContact();
};

#endif
