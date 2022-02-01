/* 선별검사소(screening inspetion)과 이동형 선별 검사소(drive through screening inspection)은 소유(aggregation)관계로 구성! */
#ifndef DRIVESIC_H
#define DRIVESIC_H
#include "screeningIC.h" // 소유 관계
#include <iostream>

class DriveSIC : public ScreeningIC
{
private:
	ScreeningIC jurisdiction; // 관할 기관
public:
	DriveSIC(string name, string location, string phone, string type, int waiter, int wTime, string status, ScreeningIC jurisdiction);
	~DriveSIC();
	void print() const;
};
#endif

