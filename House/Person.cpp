#include "Person.h"

Person::Person() : age{}, gender{} {}

Person::Person(const string& surname, const string& name, const string& patrony,
	const string& homePhone, const string& workPhone, const string& mobilePhone,
	const string& additInfo, const int& age, const bool& gender) :
	surname{ surname }, name{ name },
	patrony{ patrony }, homePhone{ homePhone }, workPhone{ workPhone },
	mobilePhone{ mobilePhone }, additInfo{ additInfo }, age{ age }, gender{ gender } {}

void Person::random() {
	int randSurname{ randNumber(1, MAX_SURNAME) };
	int randName{};
	int randPatrony{};

	char pathName[MAX_CHAR]{};
	char pathPatrony[MAX_CHAR]{};
	char pathSurame[MAX_CHAR]{ "male_surnames_rus.txt" };

	int randProfessions = randNumber(1, MAX_PROFESSIONS);
	char pathProfessions[MAX_CHAR]{ "professions.txt" };

	gender = randNumber(false, true);
	age = randNumber(MIN_AGE, MAX_AGE);

	if (gender) {
		strcpy_s(pathName, "male_names_rus.txt");
		strcpy_s(pathPatrony, "otch_m_ru.txt");
		randName = randNumber(1, MAX_NAME_MALE);
		randPatrony = randNumber(1, MAX_PATRONY_MALE);
	}
	else {
		strcpy_s(pathName, "female_names_rus.txt");
		strcpy_s(pathPatrony, "otch_f_ru.txt");
		randName = randNumber(1, MAX_NAME_FEMALE);
		randPatrony = randNumber(1, MAX_PATRONY_FEMALE);
	}

	ifstream surname_in;
	ifstream name_in;
	ifstream patrony_in;
	ifstream professions_in;

	surname_in.open(pathSurame);
	name_in.open(pathName);
	patrony_in.open(pathPatrony);
	professions_in.open(pathProfessions);

	if (name_in.is_open() && surname_in.is_open() &&
		patrony_in.is_open() && professions_in.is_open()) {

		for (int i{}; i < randSurname; ++i)
			getline(surname_in, surname);

		for (int i{}; i < randName; ++i)
			getline(name_in, name);

		for (int i{}; i < randPatrony; ++i)
			getline(patrony_in, patrony);

		for (int i{}; i < randProfessions; ++i)
			getline(professions_in, additInfo);

		if (!gender)
			surname += "a";

		surname_in.close();
		name_in.close();
		patrony_in.close();
		professions_in.close();

		homePhone = to_string(randNumber(1, 9)) + "-" + to_string(randNumber(10, 99)) +
			"-" + to_string(randNumber(10, 99));
		workPhone = to_string(randNumber(1, 9)) + "-" + to_string(randNumber(10, 99)) +
			"-" + to_string(randNumber(10, 99));
		mobilePhone = "+7(" + to_string(randNumber(100, 999)) + ")" +
			to_string(randNumber(100, 999)) + "-" + to_string(randNumber(10, 99)) + "-" +
			to_string(randNumber(10, 99));
	}
	else
		return;
}

void Person::print() {
	cout << "Фамилия:..." << surname << endl
		<< "Имя:......." << name << endl
		<< "Отчество:.." << patrony << endl
		<< "Пол:.......";
	gender ? cout << "Мужчина" : cout << "Женщина";
	cout << endl << "Возраст:..." << age << endl;
	cout << "Дом.тел:..." << homePhone << endl
		<< "Раб.тел:..." << workPhone << endl
		<< "Моб.тел:..." << mobilePhone << endl
		<< "Заметки:..." << additInfo << endl;
}

inline string Person::getSurname() {
	return surname;
}

inline string Person::getName() {
	return name;
}

inline string Person::getPatrony() {
	return patrony;
}

inline string Person::getHomePhone() {
	return homePhone;
}

inline string Person::getWorkPhone() {
	return workPhone;
}

inline string Person::getMobilePhone() {
	return mobilePhone;
}

inline string Person::getAdditInfo() {
	return additInfo;
}

inline int Person::getAge() {
	return age;
}

inline bool Person::getGender() {
	return gender;
}

inline void Person::setSurname(const string& surname) {
	this->surname = surname;
}

inline void Person::setName(const string& name) {
	this->name = name;
}

inline void Person::setPatrony(const string& patrony) {
	this->patrony = patrony;
}

inline void Person::setHomePhone(const string& homePhone) {
	this->homePhone = homePhone;
}

inline void Person::setWorkPhone(const string& workPhone) {
	this->workPhone = workPhone;
}

inline void Person::setMobilePhone(const string& mobilePhone) {
	this->mobilePhone = mobilePhone;
}

inline void Person::setAdditInfo(const string& additInfo) {
	this->additInfo = additInfo;
}

inline void Person::setAge(const int& age) {
	this->age = age;
}

inline void Person::setGender(const bool& gender) {
	this->gender = gender;
}

Person& Person::operator+=(const Person& p) {
	surname = p.surname;
	name = p.name;
	patrony = p.patrony;
	homePhone = p.homePhone;
	workPhone = p.workPhone;
	mobilePhone = p.mobilePhone;
	additInfo = p.additInfo;
	age = p.age;
	gender = p.gender;

	return *this;
}

int Person::randNumber(const int& min, const int& max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);

	return dist(gen);
}
