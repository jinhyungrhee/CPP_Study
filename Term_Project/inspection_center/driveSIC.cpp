#include "driveSIC.h"

// ��� ���� �����ڿ� �Ҹ���
// ������
DriveSIC::DriveSIC(string nm, string loc, string ph, string tp, int w, int t, string st, ScreeningIC jd)
:ScreeningIC(nm, loc, ph, tp, w = 0, t = 0, st = ""), jurisdiction(jd)
{
}

// �Ҹ���
DriveSIC::~DriveSIC()
{
}

// ����Լ�
void DriveSIC::print() const
{
	ScreeningIC::print(); // ����
	cout << "|���� : " << jurisdiction.getName() << "(" << jurisdiction.getPhone() << ") ";
}

// driveSIC�� ScreeningIC�� ����ϰ� �ֱ� ������ 
// ���̽� Ŭ������ ������ setStatus(), setWaiter(), setWTime() ����Լ��� �������� �ʰ� ����� �� ����!
