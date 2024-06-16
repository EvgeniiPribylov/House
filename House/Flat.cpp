#include "Flat.h"

Flat::Flat(const int& quanResident) : number{ ++number_apartments }, quanResident{ quanResident },
resident{ new Person[quanResident] } {
	for (int i{}; i < quanResident; ++i)
		resident[i].random();
}

Flat::Flat() : Flat(randNumber(1, 5)) {}

void Flat::print() {
	cout << "Номер квартиры -> " << number << endl
		<< "Кол-во проживающих = " << quanResident << endl;

	for (int i{}; i < quanResident; ++i) {
		resident[i].print();
		cout << endl;
	}
}

Flat::~Flat() {
	delete[] resident;
}

Flat& Flat::operator=(const Flat& fl) {
	delete[] resident;

	number = fl.number;
	quanResident = fl.quanResident;

	resident = new Person[quanResident];

	for (int i{}; i < quanResident; ++i) 
		resident[i] += fl.resident[i];

	return *this;
}

int Flat::randNumber(const int& min, const int& max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);

	return dist(gen);
}
