// 선별 검사소
#ifndef SCREENINGIC_H
#define SCREENINGIC_H
#include "inspectionCenter.h"

class ScreeningIC : public InspectionCenter
{
private:
	string name;	 // 선별진료소 이름
	string location; // 지역
	string phone;	 // 전화번호
	string type;	 // 유형(선별진료소 / 임시선별진료소 / 자동차 이동형 선별진료소)
	int waiter;		 // 대기자수
	int wTime;		 // 대기시간
	string status;   // 상태(혼잡 / 보통 / 원활 / 미운영)
public:
	ScreeningIC(string name, string location, string phone, string type, int waiter, int wTime, string status);
	ScreeningIC(const ScreeningIC& screening);
	~ScreeningIC();
	void print() const; // 반드시 구현 필요(순수가상함수)
	void setStatus(); // 반드시 구현 필요
	void setWaiter(int num); // 반드시 구현 필요
	void setWTime(); // 반드시 구현 필요
	string getName() const;
	string getPhone() const;
};
#endif