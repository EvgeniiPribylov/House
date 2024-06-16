#pragma once

#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

const int MAX_CHAR{ 255 };					// ���� ����� ��������
const int MAX_SURNAME{ 14652 };				// ���-�� ������� � �����
const int MAX_NAME_MALE{ 737 };				// ���-�� ������� ��� � �����
const int MAX_NAME_FEMALE{ 938 };			// ���-�� ������� ��� � �����
const int MAX_PATRONY_MALE{ 73 };			// ���-�� ������� ������� � �����
const int MAX_PATRONY_FEMALE{ 57 };			// ���-�� ������� ������� � �����
const int MIN_AGE{ 15 }, MAX_AGE{ 100 };	// MAX/MIN �������
const int MAX_PROFESSIONS{ 35 };			// ���-�� ��������� � �����

// ����� ��������
class Person {
public:
public:
	Person();
	Person(const string& surname, const string& name, const string& patrony,
		const string& homePhone, const string& workPhone, const string& mobilePhone,
		const string& additInfo, const int& age, const bool& gender);

	// ��������� �������� ��������
	void random();

	// �������� ���� � ��������
	void print();

	inline string getSurname();
	inline string getName();
	inline string getPatrony();
	inline string getHomePhone();
	inline string getWorkPhone();
	inline string getMobilePhone();
	inline string getAdditInfo();
	inline int getAge();
	inline bool getGender();

	inline void setSurname(const string& surname);
	inline void setName(const string& name);
	inline void setPatrony(const string& patrony);
	inline void setHomePhone(const string& homePhone);
	inline void setWorkPhone(const string& workPhone);
	inline void setMobilePhone(const string& mobilePhone);
	inline void setAdditInfo(const string& additInfo);
	inline void setAge(const int& age);
	inline void setGender(const bool& gender);

	Person& operator+=(const Person& p);

	~Person() {}

private:
	string surname;		// �������
	string name;		// ���
	string patrony;		// ��������
	string homePhone;	// �������� �������
	string workPhone;	// ������� �������
	string mobilePhone;	// ��������� �������
	string additInfo;	// �������������� ���������� � ��������
	int age;			// �������
	bool gender;		// ��� (1)�/(2)�

	// �-��� ��� ������� �����
	int randNumber(const int& min, const int& max);
};

