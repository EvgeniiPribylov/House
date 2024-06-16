#pragma once

#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

const int MAX_CHAR{ 255 };					// Макс число символов
const int MAX_SURNAME{ 14652 };				// Кол-во фамилий в файле
const int MAX_NAME_MALE{ 737 };				// Кол-во мужских имён в файле
const int MAX_NAME_FEMALE{ 938 };			// Кол-во женских имён в файле
const int MAX_PATRONY_MALE{ 73 };			// Кол-во мужских отчеств в файле
const int MAX_PATRONY_FEMALE{ 57 };			// Кол-во мужских отчеств в файле
const int MIN_AGE{ 15 }, MAX_AGE{ 100 };	// MAX/MIN возраст
const int MAX_PROFESSIONS{ 35 };			// Кол-во профессий в файле

// Класс человека
class Person {
public:
public:
	Person();
	Person(const string& surname, const string& name, const string& patrony,
		const string& homePhone, const string& workPhone, const string& mobilePhone,
		const string& additInfo, const int& age, const bool& gender);

	// Рандомное создание человека
	void random();

	// Показать инфу о человеке
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
	string surname;		// Фамилия
	string name;		// Имя
	string patrony;		// Отчество
	string homePhone;	// Домашний телефон
	string workPhone;	// Рабочий телефон
	string mobilePhone;	// Мобильный телефон
	string additInfo;	// Дополнительная информация о контакте
	int age;			// Возраст
	bool gender;		// Пол (1)м/(2)ж

	// Ф-ция для рандома чисел
	int randNumber(const int& min, const int& max);
};

