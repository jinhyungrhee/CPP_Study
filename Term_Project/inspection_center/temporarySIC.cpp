#include "temporarySIC.h"

// ��� ���� �����ڿ� �Ҹ���
// ������
TemporarySIC::TemporarySIC(string nm, string loc, string ph, string tp, int w, int t, string st, ScreeningIC jd)
:ScreeningIC(nm, loc, ph, tp, w = 0, t = 0, st = ""), jurisdiction(jd)
{
}

// �Ҹ���
TemporarySIC::~TemporarySIC()
{
}

// ����Լ�
void TemporarySIC::print() const
{
	ScreeningIC::print(); // ����
	cout << "|���� : " << jurisdiction.getName() << "(" << jurisdiction.getPhone() << ") ";
}

// TemporarySIC�� ScreeningIC�� ����ϰ� �ֱ� ������ 
// ���̽� Ŭ������ ������ setStatus(), setWaiter(), setWTime() ����Լ��� �������� �ʰ� ����� �� ����!