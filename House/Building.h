#pragma once
#include "Flat.h"

// Класс здания
class Building {
public:
	Building(const int& numberFloors, const int& numberApartments);

	void print();

	~Building();

	// Конструктор копирования (присваения)
	Building& operator=(const Building& bui);

private:
	int numberFloors;		// Кол-во этажей и их номер
	int numberApartments;	// Кол-во квартир на этаже
	Flat** apartments;		// Массив квартир по этажам

	void deleteBui();
	void createFlat();
};

