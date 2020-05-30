#include<iostream>
#include"Contacts.h"
using namespace std;

int main() {

	PhoneBook Con2;
	Contact test = {"Liza",30,"24-22-22","098-999-99-99"};
	Contact test2 = { "Masha",25,"22-55-55","098-555-55-55" };
	Contact test3 = { "Soloha",55,"22-77-77","098-777-77-77" };

	Con2.AddNewContact(test);
	Con2.Print(test);

	Con2.SetName(test, "Ann");
	Con2.SetAge(test, 20);

	Con2.AddNewContact(test2);
	Con2.AddNewContact(test3);
	Con2.ShowAllContacts();

	Con2.DellContactByName("Soloha");
	Con2.ShowAllContacts();
	Con2.SearchByName("Soloha");
	Con2.SaveContact();
	Con2.Load();
	system("pause");
	return 0;
}