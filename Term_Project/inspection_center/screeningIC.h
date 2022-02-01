// ���� �˻��
#ifndef SCREENINGIC_H
#define SCREENINGIC_H
#include "inspectionCenter.h"

class ScreeningIC : public InspectionCenter
{
private:
	string name;	 // ��������� �̸�
	string location; // ����
	string phone;	 // ��ȭ��ȣ
	string type;	 // ����(��������� / �ӽü�������� / �ڵ��� �̵��� ���������)
	int waiter;		 // ����ڼ�
	int wTime;		 // ���ð�
	string status;   // ����(ȥ�� / ���� / ��Ȱ / �̿)
public:
	ScreeningIC(string name, string location, string phone, string type, int waiter, int wTime, string status);
	ScreeningIC(const ScreeningIC& screening);
	~ScreeningIC();
	void print() const; // �ݵ�� ���� �ʿ�(���������Լ�)
	void setStatus(); // �ݵ�� ���� �ʿ�
	void setWaiter(int num); // �ݵ�� ���� �ʿ�
	void setWTime(); // �ݵ�� ���� �ʿ�
	string getName() const;
	string getPhone() const;
};
#endif