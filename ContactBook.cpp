// ContactBook.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <algorithm>
#include "ContactBook.h"

int main()
{
	int choice{};
	ContactBook c1{};
	std::string name{};
	std::string email{};
	int phoneNum{};
	do
		
	{
		std::cout << "Enter your choice: \n" 
			" 1. Add Contact\n"
			" 2. View Contact\n"
			" 3. Search Contact\n"
			" 4. Delete Contact\n"
			" 5. Sort Contact\n"
			" 6. Exit \n";
		std::cin >> choice;
		std::cin.ignore();
		
		switch (choice)
		{
		case 1:					//Add Contact
		{
			
			std::cout << "Enter Name: \n";
			std::getline(std::cin, name);

			std::cout << "Enter Phone Number: \n";
			std::cin >> phoneNum;
			std::cin.ignore();

			std::cout << "Enter EmailID: \n";
			std::getline(std::cin, email);

			Contact c{name,phoneNum,email};
			c1.addContact(c);
			break;
		}
			
		case 2:					//View Contact
		{
			c1.viewContacts();
			break;
		}
			
		case 3:					//Search Contact
		{
			std::cout << "Enter name to search contact details: \n";
			std::getline(std::cin, name);
			c1.searchContact(name);
			break;
		}
		
		case 4:					//Delete Contact by name
		{
			std::cout << "Enter contact name to delete";
			std::getline(std::cin, name);
			c1.deleteContact(name);
			break;
		}
			
		case 5:					//Sort Contact by name in increasing order
			c1.sortContact();
			break;

		case 6:					//Exit
			std::cout << "Exiting Contact Book...\n";
			break;

		default:				//Invalid choice
			std::cout << "Invalid Choice!!! Please try again";

		}
	} while (choice != 6);
	return 0;
}

/* Function Definitions*/

Contact::Contact()=default; 

Contact::Contact(std::string name, int phone, std::string email) : m_name{ name }
, m_phoneNum{ phone }, m_emailID{ email } {
}; // Constructor

//Getters
std::string Contact::getName() const
{
	return m_name;
}
int  Contact::getPhoneNum() const
{
	return m_phoneNum;
}
std::string Contact::getEmailID() const
{
	return m_emailID;
}

//Setters
void Contact::setName(const std::string& name)
{
	m_name = name;
}

void Contact::setEmailID(const std::string& email)
{
	m_emailID = email;
}

void Contact::setPhoneNum(const int& num)
{
	m_phoneNum = num;
}

ContactBook::ContactBook() = default; //Default constructor
ContactBook::ContactBook(std::vector<Contact> contact) : m_contact{ contact } {};

void ContactBook::addContact(const Contact& c)
{
	m_contact.push_back(c);
}

void ContactBook::viewContacts() const
{
	int count{ 1 };
	for (const auto& contact : m_contact)
	{
		std::cout << count++ << ".Name: " << contact.getName()<<"\n";
		std::cout << "Phone Number: "<<contact.getPhoneNum() << "\n";
		std::cout << "EmailID: "<<contact.getEmailID() << "\n";
	}
	
}

void ContactBook::searchContact(const std::string& name)
{
	auto it=std::find_if(m_contact.begin(), m_contact.end(),
		[&](const Contact& c) {
			return (c.getName() == name);
		});

	if (it != m_contact.end())
	{
		std::cout << "Contact Found: \n";
		std::cout << "Name: " << it->getName() << "\n";
		std::cout << "Phone Number: " << it->getPhoneNum() << "\n";
		std::cout << "Email ID: " << it->getEmailID() << "\n";

	}

	else
	{
		std::cout << "No matching contact found!!!" << "\n";
	}
	
}

void ContactBook::deleteContact(const std::string& name)
{
	auto it = std::find_if(m_contact.begin(), m_contact.end(),
		[&](const Contact& c) {
			return (c.getName() == name);
		});
		
	if (it != m_contact.end())
	{
		m_contact.erase(it);
		std::cout << "Contact Deleted...\n";
	}
	else
	{
		std::cout << "No matching contact found to delete!!!" << "\n";
	}
	
}

//Sort Contact by name in increasing order
void ContactBook::sortContact()
{
	std::sort(m_contact.begin(), m_contact.end(),
          [](const Contact& a, const Contact& b) {
              return a.getName() < b.getName();  // sort by name
          });

	std::cout << "Contact Sorted...\n";
}

ContactBook:: ~ContactBook() {};