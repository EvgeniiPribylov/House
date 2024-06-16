#pragma once
#include "Flat.h"

// ����� ������
class Building {
public:
	Building(const int& numberFloors, const int& numberApartments);

	void print();

	~Building();

	// ����������� ����������� (����������)
	Building& operator=(const Building& bui);

private:
	int numberFloors;		// ���-�� ������ � �� �����
	int numberApartments;	// ���-�� ������� �� �����
	Flat** apartments;		// ������ ������� �� ������

	void deleteBui();
	void createFlat();
};

