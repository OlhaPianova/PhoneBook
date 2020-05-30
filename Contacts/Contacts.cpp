#include<iostream>
#include "Contacts.h"
#include <fstream>
using namespace std;

PhoneBook::PhoneBook()
{
	countContact = 0;
	book = nullptr;
}
PhoneBook::PhoneBook(const char* _name, int _age, const char* _homePhone, const char* _mobilePhone)
{
		strcpy_s(book[countContact].name, _name);
		book[countContact].age = _age;
		strcpy_s(book[countContact].homePhone, _homePhone);
		strcpy_s(book[countContact].mobilePhone, _mobilePhone);
		countContact++;
}

PhoneBook::~PhoneBook()
{
	delete[] book;
}

inline const char * PhoneBook::GetName() const
{
	for (int i = 0; i < countContact; i++) {
		return book[i].name;
	}
}

inline int PhoneBook::GetAge() const
{
	for (int i = 0; i < countContact; i++) {
		return book[i].age;
	}
}

inline const char * PhoneBook::GetHomePhone() const
{
	for (int i = 0; i < countContact; i++) {
		return book[i].homePhone;
	}
}

inline const char * PhoneBook::GetMobilePhone() const
{
	for (int i = 0; i < countContact; i++) {
		return book[i].mobilePhone;
	}
}

void PhoneBook::SetName(Contact other,const char * name)
{
	int size = strlen(name) + 1;
		strcpy_s(other.name, size, name);
	
}

void PhoneBook::SetAge(Contact other, int age)
{
	if (IsValidSize(age))
		other.age = age;
	
}

void PhoneBook::SetHomePhone(Contact other, const char* homePhone)
{
	int size = strlen(homePhone) + 1;
	for (int i = 0; i < countContact; i++) {
		strcpy_s(other.homePhone, size, homePhone);
	}
}

void PhoneBook::SetMobilePhone(Contact other, const char * mobilePhone)
{
	int size = strlen(mobilePhone) + 1;
	for (int i = 0; i < countContact; i++) {
		strcpy_s(other.mobilePhone, size, mobilePhone);
	}
}

void PhoneBook::AddNewContact(Contact _contact)
{
	Contact* temp = new Contact[countContact + 1];
	for (int i = 0; i < countContact;i++) {
		temp[i] = book[i];
	}
	
	temp[countContact] = _contact;

	countContact++;
	delete[] book;
	book = temp;
}

void PhoneBook::DellContactByName(const char* name)
{
	Contact* temp = new Contact[countContact-1];
	for (int i = 0; i < countContact; i++)
	{
		if (strcmp(name, book[i].name) != 0) {
			temp[i] = book[i];
		}
	}

	countContact--;
	delete[] book;
	book = temp;
}

void PhoneBook::SearchByName(const char * name)
{
	for (int i = 0; i < countContact; i++) {
		if (strcmp(book[i].name, name) ==0) {
			cout <<"Name: "<< book[i].name << endl;
			cout <<"Age: " << book[i].age << endl;
			cout <<"Home phone: " << book[i].homePhone << endl;
			cout <<"Mobile phone: " << book[i].mobilePhone << endl;
			cout << "---------------------------" << endl;
			cout << endl;
		}
	}
}

void PhoneBook::Print(Contact _contact)
{
	    cout << "~~~~~~  Contact  ~~~~~" << endl;
		cout << "Name: " << _contact.name << endl;
		cout << "Age: " << _contact.age << endl;
		cout << "Home phone: " << _contact.homePhone << endl;
		cout << "Mobile phone: " << _contact.mobilePhone << endl;
		cout << "---------------------------" << endl;
		cout << endl;
	
}

void PhoneBook::ShowAllContacts()
{
	cout << "\t\t\t-------All contacts-------" << endl;
	for (int i = 0; i < countContact;i++) {
		cout << "Name: " << book[i].name << endl;
		cout << "Age: " << book[i].age << endl;
		cout << "Home phone: " << book[i].homePhone << endl;
		cout << "Mobile phone: " << book[i].mobilePhone << endl;
		cout << "---------------------------" << endl;
		cout << endl;
	}
	cout << "End===============" << endl;
	cout << "\n\n";
}
void PhoneBook::SaveContact() {
	ofstream fout;
	fout.open("PhoneBook.txt", fstream::out);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		for (int i = 0; i < countContact;i++) {
			fout << book[i].name << endl;
			fout << book[i].age << endl;
			fout << book[i].homePhone << endl;
			fout << book[i].mobilePhone << endl;
		}
		fout << countContact << endl;
		fout.close();
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
}
void PhoneBook:: Load() {
	ifstream fin;
	fin.open("PhoneBook.txt");
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		while (!fin.eof())
		{
			Contact getContact;
			for (int i = 0; i < countContact;i++) {
			fin >> getContact.name;
			fin >> getContact.age;
			fin >> getContact.homePhone;
			fin >> getContact.mobilePhone;
		  }
		fin >> countContact;
	  }
	}
	else {
		cout << "Error: Application can't open data file!" << endl;
	}
	fin.close();
}





