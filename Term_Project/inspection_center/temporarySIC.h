/* �����˻��(screening inspetion center)�� �ӽ� �����˻��(temporary screening inspection center)�� ��� �����̸鼭 ����(aggregation)����� ����! */
#ifndef TEMPORARYSIC_H
#define TEMPORARYSIC_H
#include "screeningIC.h" // ���� ����
#include <iostream>
class TemporarySIC : public ScreeningIC
{
private:
	ScreeningIC jurisdiction; // ���� ���
public:
	TemporarySIC(string name, string location, string phone, string type, int waiter, int wTime, string status, ScreeningIC jurisdiction);
	~TemporarySIC();
	void print() const;
};
#endif
