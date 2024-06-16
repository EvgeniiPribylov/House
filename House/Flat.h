#pragma once
#include "Person.h"

// ����� ���������
class Flat {
public:

	// ��������� ����������� ����� � ��������
	Flat(const int& quanResident);

	// ����������� �������� ������ ����������� �������
	Flat();

	// �������� ��������
	void print();

	~Flat();

	Flat& operator=(const Flat& fl);

private:
	static inline int number_apartments{};	// ����������� ��������� �������
	int number;				// ����� ��������
	int quanResident;		// ����������� ������� � ��������
	Person* resident;		// ���������� � ������� � ��������

	// �-��� ��� ������� �����
	int randNumber(const int& min, const int& max);
};

