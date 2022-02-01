#include "temporarySIC.h"

// 상속 때의 생성자와 소멸자
// 생성자
TemporarySIC::TemporarySIC(string nm, string loc, string ph, string tp, int w, int t, string st, ScreeningIC jd)
:ScreeningIC(nm, loc, ph, tp, w = 0, t = 0, st = ""), jurisdiction(jd)
{
}

// 소멸자
TemporarySIC::~TemporarySIC()
{
}

// 멤버함수
void TemporarySIC::print() const
{
	ScreeningIC::print(); // 위임
	cout << "|관할 : " << jurisdiction.getName() << "(" << jurisdiction.getPhone() << ") ";
}

// TemporarySIC는 ScreeningIC를 상속하고 있기 때문에 
// 베이스 클래스에 구현된 setStatus(), setWaiter(), setWTime() 멤버함수를 구현하지 않고 사용할 수 있음!