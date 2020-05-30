#pragma once

struct Contact {
	char name[10];
	int age;
	char homePhone[10];
	char mobilePhone[20];
};

class PhoneBook {
private:
	Contact* book;
	int countContact;

	inline bool IsValidSize(int age) const
	{
		return age > 0;
	}

public:
	PhoneBook();
	PhoneBook( const char* _name, int _age, const char* _homePhone, const char* _mobilePhone);
	~PhoneBook();

	const char* GetName() const;
	int GetAge() const;
	const char* GetHomePhone() const;
	const char* GetMobilePhone() const;

	void SetName(Contact other,const char* name);
	void SetAge(Contact other, int age);
	void SetHomePhone(Contact other, const char* homePhone);
	void SetMobilePhone(Contact other, const char* mobilePhone);

	void AddNewContact(Contact _contact);
	void DellContactByName(const char* name);
	void SearchByName(const char* name);
	void Print(Contact _contact);
	void ShowAllContacts();
	void SaveContact();
	void Load();
};