#include "Building.h"

Building::Building(const int& numberFloors, const int& numberApartments) : numberFloors{ numberFloors },
numberApartments{ numberApartments } {
	createFlat();
}

void Building::print() {
	cout << "Всего этажей = " << numberFloors << endl;
	for (int i{}; i < numberFloors; ++i) {
		cout << "Этаж - " << i + 1 << endl;

		for (int j{}; j < numberApartments; ++j)
			apartments[i][j].print();

		cout << "-------------------------------" << endl;
	}
}

void Building::deleteBui() {
	for (int i{}; i < numberFloors; ++i)
		delete[] apartments[i];

	delete[] apartments;
}

void Building::createFlat() {
	apartments = new Flat * [numberFloors] {};

	for (int i{}; i < numberFloors; ++i)
		apartments[i] = new Flat[numberApartments]{};
}

Building::~Building() {
	deleteBui();
}

Building& Building::operator=(const Building& bui) {
	deleteBui();

	numberFloors = bui.numberFloors;
	numberApartments = bui.numberApartments;

	createFlat();

	for (int i{}; i < numberFloors; ++i)
		for (int j{}; j < numberApartments; ++j)
			apartments[i][j] = bui.apartments[i][j];

	return *this;
}
