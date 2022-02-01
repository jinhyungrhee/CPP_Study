#ifndef INSPECTIONCENTER_H
#define INSPECTIONCENTER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;

// ����� �������̽�
class InspectionCenter
{
private:
	
public:
	// ���� ���� �Լ� ���� = > ��� ����Լ��� ���������Լ��̹Ƿ� InspectionCenter�� �߻�Ŭ���� �߿����� '�������̽�'��!(��������X)
	virtual void print() const = 0;
	virtual void setStatus() = 0;
	virtual void setWaiter(int num) = 0;
	virtual void setWTime() = 0;
};


#endif
