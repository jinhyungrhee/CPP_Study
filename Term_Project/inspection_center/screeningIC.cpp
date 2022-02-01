#include "screeningIC.h"

// 매개변수를 사용한 생성자
ScreeningIC::ScreeningIC(string nm, string loc, string ph, string tp, int w, int t ,string st)
:name(nm), location(loc), phone(ph), type(tp), waiter(w = 0), wTime(t = 0), status(st = "") // 대기자, 대기시간, 상태는 기본값으로 초기화
{

}
// 복사 생성자
ScreeningIC::ScreeningIC(const ScreeningIC& sic)
:name(sic.name), location(sic.location), phone(sic.phone), type(sic.type), waiter(sic.waiter), wTime(sic.wTime), status(sic.status)
{

}
// 소멸자
ScreeningIC::~ScreeningIC()
{
}

// 멤버함수
void ScreeningIC::print() const
{
	cout << "|이름 : " << setw(38) << left << name << " ";
	cout << "|지역 : " << location << " ";
	cout << "|전화번호 : " << setw(14) << left << phone << " ";
	cout << "|유형 : " << setw(6) << left << type << " ";
	cout << "|대기인원 : " << setw(4) << left << waiter << " ";
	cout << "|상태 : " << setw(6) << right << status << "(약 " << setw(3) << wTime << "분 소요) ";
}

// 접근자 함수
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
		cout << "유효하지 않은 대기자 수입니다. 프로그램을 종료합니다.";
		assert(false);

	}
	waiter = num;
}

void ScreeningIC::setStatus()
{
	if (waiter >= 0 && waiter <= 10)
	{
		status = "원활";
	}
	else if (waiter > 10 && waiter <= 30)
	{
		status = "보통";
	}
	else if (waiter > 30)
	{
		status = "혼잡";
	}
	else // -1이면
	{
		status = "미운영";
		waiter = 0; // 대기자는 0으로 설정
	}
}

void ScreeningIC::setWTime()
{
	if (type == "이동형")
	{
		wTime = 0.5 * waiter;
	}
	else if (type == "선별")
	{
		wTime = 1 * waiter;
	}
	else if (type == "임시")
	{
		wTime = 1.5 * waiter;
	}

}
