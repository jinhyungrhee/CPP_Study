/* 선별검사소(screening inspetion center)과 임시 선별검사소(temporary screening inspection center)은 상속 관계이면서 소유(aggregation)관계로 구성! */
#ifndef TEMPORARYSIC_H
#define TEMPORARYSIC_H
#include "screeningIC.h" // 소유 관계
#include <iostream>
class TemporarySIC : public ScreeningIC
{
private:
	ScreeningIC jurisdiction; // 관할 기관
public:
	TemporarySIC(string name, string location, string phone, string type, int waiter, int wTime, string status, ScreeningIC jurisdiction);
	~TemporarySIC();
	void print() const;
};
#endif
