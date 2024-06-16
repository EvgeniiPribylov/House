#pragma once
#include "Person.h"

// Класс квартирва
class Flat {
public:

	// Принимает колличество людей в квартире
	Flat(const int& quanResident);

	// Конструктор содержит рандом колличества жильцов
	Flat();

	// Показать квартиру
	void print();

	~Flat();

	Flat& operator=(const Flat& fl);

private:
	static inline int number_apartments{};	// Колличество созданных квартир
	int number;				// Номер квартиры
	int quanResident;		// Колличество жильцов в кваритре
	Person* resident;		// Информация о жильцах в квартире

	// Ф-ция для рандома чисел
	int randNumber(const int& min, const int& max);
};

