/* �����˻��(screening inspetion)�� �̵��� ���� �˻��(drive through screening inspection)�� ����(aggregation)����� ����! */
#ifndef DRIVESIC_H
#define DRIVESIC_H
#include "screeningIC.h" // ���� ����
#include <iostream>

class DriveSIC : public ScreeningIC
{
private:
	ScreeningIC jurisdiction; // ���� ���
public:
	DriveSIC(string name, string location, string phone, string type, int waiter, int wTime, string status, ScreeningIC jurisdiction);
	~DriveSIC();
	void print() const;
};
#endif

