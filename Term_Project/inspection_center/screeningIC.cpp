#include "screeningIC.h"

// �Ű������� ����� ������
ScreeningIC::ScreeningIC(string nm, string loc, string ph, string tp, int w, int t ,string st)
:name(nm), location(loc), phone(ph), type(tp), waiter(w = 0), wTime(t = 0), status(st = "") // �����, ���ð�, ���´� �⺻������ �ʱ�ȭ
{

}
// ���� ������
ScreeningIC::ScreeningIC(const ScreeningIC& sic)
:name(sic.name), location(sic.location), phone(sic.phone), type(sic.type), waiter(sic.waiter), wTime(sic.wTime), status(sic.status)
{

}
// �Ҹ���
ScreeningIC::~ScreeningIC()
{
}

// ����Լ�
void ScreeningIC::print() const
{
	cout << "|�̸� : " << setw(38) << left << name << " ";
	cout << "|���� : " << location << " ";
	cout << "|��ȭ��ȣ : " << setw(14) << left << phone << " ";
	cout << "|���� : " << setw(6) << left << type << " ";
	cout << "|����ο� : " << setw(4) << left << waiter << " ";
	cout << "|���� : " << setw(6) << right << status << "(�� " << setw(3) << wTime << "�� �ҿ�) ";
}

// ������ �Լ�
string ScreeningIC::getName() const
{
	return name;
}

string ScreeningIC::getPhone() const
{
	return phone;
}

void ScreeningIC::setWaiter(int num)
{
	if (num < -1)
	{
		cout << "��ȿ���� ���� ����� ���Դϴ�. ���α׷��� �����մϴ�.";
		assert(false);

	}
	waiter = num;
}

void ScreeningIC::setStatus()
{
	if (waiter >= 0 && waiter <= 10)
	{
		status = "��Ȱ";
	}
	else if (waiter > 10 && waiter <= 30)
	{
		status = "����";
	}
	else if (waiter > 30)
	{
		status = "ȥ��";
	}
	else // -1�̸�
	{
		status = "�̿";
		waiter = 0; // ����ڴ� 0���� ����
	}
}

void ScreeningIC::setWTime()
{
	if (type == "�̵���")
	{
		wTime = 0.5 * waiter;
	}
	else if (type == "����")
	{
		wTime = 1 * waiter;
	}
	else if (type == "�ӽ�")
	{
		wTime = 1.5 * waiter;
	}

}
