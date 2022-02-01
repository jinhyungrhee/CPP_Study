#ifndef INSPECTIONCENTER_H
#define INSPECTIONCENTER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
using namespace std;

// 진료소 인터페이스
class InspectionCenter
{
private:
	
public:
	// 순수 가상 함수 선언 = > 모든 멤버함수가 순수가상함수이므로 InspectionCenter는 추상클래스 중에서도 '인터페이스'임!(구현파일X)
	virtual void print() const = 0;
	virtual void setStatus() = 0;
	virtual void setWaiter(int num) = 0;
	virtual void setWTime() = 0;
};


#endif
