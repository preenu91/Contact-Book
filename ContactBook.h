// ContactBook.h : Include file for standard system include files,
// or project specific include files.

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include <vector>

class Contact
{
private:
	std::string m_name{};
	int m_phoneNum{};
	std::string m_emailID{};

public:
	Contact();
	Contact(std::string name, int phone, std::string email); // Constructor

		//Getters
		std::string getName() const;
		int  getPhoneNum() const;		
		std::string getEmailID() const;
		

		//Setters
		void setName(const std::string& name);
		void setEmailID(const std::string& email);
		void setPhoneNum(const int& num);

		~Contact() {}; //Destructor
};


class ContactBook
{
private:
	std::vector<Contact> m_contact{};

public:
	ContactBook();
	ContactBook(std::vector<Contact> contact);
	void addContact(const Contact& c);
	void viewContacts() const;
	void searchContact(const std::string& name);
	void deleteContact(const std::string& name);
	void sortContact();

	~ContactBook();


};
#endif