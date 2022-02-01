/* 지역별 진료소에 현재 대기 인원을 입력하면 혼잡도와 대기시간을 보여주는 프로그램 */
#include "screeningIC.h"
#include "temporarySIC.h"
#include "driveSIC.h"

int main()
{

	int input;
	
	// seoul
	ScreeningIC gangnam("강남구보건소", "강남구", "02-3423-5555", "선별", 0, 0, "");
	ScreeningIC gangdong("강동구보건소", "강동구", "02-3425-6713", "선별", 0, 0, "");
	ScreeningIC mapo("마포구보건소", "마포구", "02-3153-9037", "선별", 0, 0, "");
	
	// gyeonggi
	ScreeningIC pochun("포천시보건소", "포천시", "031-538-3686", "선별", 0, 0, "");
	ScreeningIC bundang("분당구보건소", "성남시", "031-729-3990", "선별", 0, 0, "");
	ScreeningIC pyeongtaek("평택보건소", "평택시", "031-8024-8003", "선별", 0, 0, "");

	/*
	// daejeon
	ScreeningIC donggu("동구보건소", "대전시", "042-251-6106", "선별", 0, 0, "");
	ScreeningIC yuseong("유성구보건소", "대전시", "042-611-5000", "선별", 0, 0, "");
	ScreeningIC junggu("중구보건소", "대전시", "042-288-8043", "선별", 0, 0, "원활");

	// daegu
	ScreeningIC namgu("남구보건소", "대구시", "053-664-3601", "선별", 0, 0, "");
	ScreeningIC dalseo("달서구보건소", "대구시", "053-667-5751", "선별", 0, 0, "");
	ScreeningIC seogu("서구보건소", "대구시", "053-663-3176", "선별", 0, 0, "");
	
	// gyeongbuk
	ScreeningIC gyeungju("경주시보건소", "경주시", "054-760-2080", "선별", 0, 0, "원활");
	ScreeningIC gimcheon("김천시보건소", "김천시", "054-433-4000", "선별", 0, 0, "원활");
	ScreeningIC mungyeong("문경시보건소", "문경시", "054-550-8168", "선별", 0, 0, "원활");

	// gyeongnam
	ScreeningIC geoje("거제시보건소", "거제시", "055-639-6200", "선별", 0, 0, "원활");
	ScreeningIC jinju("진주시보건소", "진주시", "055-749-5714", "선별", 0, 0, "원활");
	ScreeningIC changwon("창원보건소", "창원시", "055-225-4281", "선별", 0, 0, "원활");

	// jeonnam - 무안, 영광
	ScreeningIC muan("무안군보건소", "무안군", "061-450-5023", "선별", 0, 0, "원활");
	ScreeningIC yeonggwang("영광군보건소", "영광군", "061-350-5552", "선별", 0, 0, "원활");
	ScreeningIC hwasun("화순군보건소", "화순군", "061-379-5341", "선별", 0, 0, "원활");
	*/

	// 다형성 변수(포인터)의 배열 선언
	ScreeningIC* seoul[9];
	ScreeningIC* gyeonggi[9];
	//ScreeningIC* daejeon[9];
	//ScreeningIC* daegu[9];
	//ScreeningIC* gyeongbuk[9];
	//ScreeningIC* gyeonnam[9];
	//ScreeningIC* jeonnam[9];

	
	// 힙에 seoul 객체 인스턴스화
	
	seoul[0] = new ScreeningIC(gangnam);
	seoul[1] = new ScreeningIC(gangdong);
	seoul[2] = new ScreeningIC(mapo);
	seoul[3] = new TemporarySIC("세곡동 방죽공원 임시선별검사소", "강남구", "02-3423-5555", "임시" ,0 ,0 , "", gangnam);
	seoul[4] = new TemporarySIC("삼성역 임시선별검사소", "강남구", "02-3423-5555", "임시", 0, 0, "", gangnam);
	seoul[5] = new TemporarySIC("암사역사공원 주차장 임시선별검사소", "강동구", "070-4104-1340", "임시", 0, 0, "", gangdong);
	seoul[6] = new TemporarySIC("온조대왕옆 공영주차장 임시선별검사소", "강동구", "070-7730-0264", "임시", 0, 0, "", gangdong);
	seoul[7] = new TemporarySIC("서강대역사 광장 임시선별검사소", "마포구", "02-3153-8656", "임시", 0,  0, "", mapo);
	seoul[8] = new TemporarySIC("홍익문화공원 임시선별검사소", "마포구", "02-3153-8308", "임시", 0, 0, "", mapo);

	// 힙에 gyeonggi 객체 인스턴스화
	
	gyeonggi[0] = new ScreeningIC(pochun);
	gyeonggi[1] = new ScreeningIC(bundang);
	gyeonggi[2] = new ScreeningIC(pyeongtaek);
	gyeonggi[3] = new TemporarySIC("포천시 종합운동장 주차장", "포천시", "031-538-3686", "임시", 0, 0, "", pochun);
	gyeonggi[4] = new TemporarySIC("포천시 소흘", "포천시", "031-538-3686", "임시", 0, 0, "", pochun);
	gyeonggi[5] = new TemporarySIC("야탑역 광장 ", "성남시", "031-729-3990", "임시", 0,  0, "", bundang);
	gyeonggi[6] = new TemporarySIC("탄천종합운동장", "성남시", "031-729-3990", "임시", 0,  0, "", bundang);
	gyeonggi[7] = new DriveSIC("의료법인 양진의료재단 평택성모병원", "평택시", "031-1800-8800", "이동형", 0, 0, "", pyeongtaek);
	gyeonggi[8] = new TemporarySIC("안중보건지소 주차장", "평택시", "031-8024-8003", "임시", 0, 0, "", pyeongtaek);


	// seoul 지역 입력
	cout << "=============================================== 서울지역 입력 ====================================================" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << seoul[i]->getName() << "의 현재 대기 인원을 입력하세요: ";
		cin >> input;
		// virtual 함수를 통한 다형성(polymorphism) 사용
		seoul[i]->setWaiter(input);
		seoul[i]->setStatus();
		seoul[i]->setWTime();
	}
	cout << endl << endl;

	// gyeonggi 지역 입력
	cout << "=============================================== 경기지역 입력 ====================================================" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << gyeonggi[i]->getName() << "의 현재 대기 인원을 입력하세요: ";
		cin >> input;
		// virtual 함수를 통한 다형성(polymorphism) 사용
		gyeonggi[i]->setWaiter(input);
		gyeonggi[i]->setStatus();
		gyeonggi[i]->setWTime();
		
	}
	cout << endl << endl;

	cout << "============================================= 서울지역 선별 진료소 =================================================" << endl;
	// seoul 지역 출력
	for (int i = 0; i < 9; i++)
	{

		seoul[i]->print();
		cout << endl;
	}

	cout << endl;
	cout << "============================================= 경기지역 선별 진료소 =================================================" << endl;

	// gyeonggi 지역 출력
	for (int i = 0; i < 9; i++)
	{
		gyeonggi[i]->print();
		cout << endl;
	}

	// 힙 객체 소멸
	for (int i = 0; i < 9; i++)
	{
		delete seoul[i];
		delete gyeonggi[i];
	}

	return 0;
}
