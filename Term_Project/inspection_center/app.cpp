/* ������ ����ҿ� ���� ��� �ο��� �Է��ϸ� ȥ�⵵�� ���ð��� �����ִ� ���α׷� */
#include "screeningIC.h"
#include "temporarySIC.h"
#include "driveSIC.h"

int main()
{

	int input;
	
	// seoul
	ScreeningIC gangnam("���������Ǽ�", "������", "02-3423-5555", "����", 0, 0, "");
	ScreeningIC gangdong("���������Ǽ�", "������", "02-3425-6713", "����", 0, 0, "");
	ScreeningIC mapo("���������Ǽ�", "������", "02-3153-9037", "����", 0, 0, "");
	
	// gyeonggi
	ScreeningIC pochun("��õ�ú��Ǽ�", "��õ��", "031-538-3686", "����", 0, 0, "");
	ScreeningIC bundang("�д籸���Ǽ�", "������", "031-729-3990", "����", 0, 0, "");
	ScreeningIC pyeongtaek("���ú��Ǽ�", "���ý�", "031-8024-8003", "����", 0, 0, "");

	/*
	// daejeon
	ScreeningIC donggu("�������Ǽ�", "������", "042-251-6106", "����", 0, 0, "");
	ScreeningIC yuseong("���������Ǽ�", "������", "042-611-5000", "����", 0, 0, "");
	ScreeningIC junggu("�߱����Ǽ�", "������", "042-288-8043", "����", 0, 0, "��Ȱ");

	// daegu
	ScreeningIC namgu("�������Ǽ�", "�뱸��", "053-664-3601", "����", 0, 0, "");
	ScreeningIC dalseo("�޼������Ǽ�", "�뱸��", "053-667-5751", "����", 0, 0, "");
	ScreeningIC seogu("�������Ǽ�", "�뱸��", "053-663-3176", "����", 0, 0, "");
	
	// gyeongbuk
	ScreeningIC gyeungju("���ֽú��Ǽ�", "���ֽ�", "054-760-2080", "����", 0, 0, "��Ȱ");
	ScreeningIC gimcheon("��õ�ú��Ǽ�", "��õ��", "054-433-4000", "����", 0, 0, "��Ȱ");
	ScreeningIC mungyeong("����ú��Ǽ�", "�����", "054-550-8168", "����", 0, 0, "��Ȱ");

	// gyeongnam
	ScreeningIC geoje("�����ú��Ǽ�", "������", "055-639-6200", "����", 0, 0, "��Ȱ");
	ScreeningIC jinju("���ֽú��Ǽ�", "���ֽ�", "055-749-5714", "����", 0, 0, "��Ȱ");
	ScreeningIC changwon("â�����Ǽ�", "â����", "055-225-4281", "����", 0, 0, "��Ȱ");

	// jeonnam - ����, ����
	ScreeningIC muan("���ȱ����Ǽ�", "���ȱ�", "061-450-5023", "����", 0, 0, "��Ȱ");
	ScreeningIC yeonggwang("���������Ǽ�", "������", "061-350-5552", "����", 0, 0, "��Ȱ");
	ScreeningIC hwasun("ȭ�������Ǽ�", "ȭ����", "061-379-5341", "����", 0, 0, "��Ȱ");
	*/

	// ������ ����(������)�� �迭 ����
	ScreeningIC* seoul[9];
	ScreeningIC* gyeonggi[9];
	//ScreeningIC* daejeon[9];
	//ScreeningIC* daegu[9];
	//ScreeningIC* gyeongbuk[9];
	//ScreeningIC* gyeonnam[9];
	//ScreeningIC* jeonnam[9];

	
	// ���� seoul ��ü �ν��Ͻ�ȭ
	
	seoul[0] = new ScreeningIC(gangnam);
	seoul[1] = new ScreeningIC(gangdong);
	seoul[2] = new ScreeningIC(mapo);
	seoul[3] = new TemporarySIC("��� ���װ��� �ӽü����˻��", "������", "02-3423-5555", "�ӽ�" ,0 ,0 , "", gangnam);
	seoul[4] = new TemporarySIC("�Ｚ�� �ӽü����˻��", "������", "02-3423-5555", "�ӽ�", 0, 0, "", gangnam);
	seoul[5] = new TemporarySIC("�ϻ翪����� ������ �ӽü����˻��", "������", "070-4104-1340", "�ӽ�", 0, 0, "", gangdong);
	seoul[6] = new TemporarySIC("������տ� ���������� �ӽü����˻��", "������", "070-7730-0264", "�ӽ�", 0, 0, "", gangdong);
	seoul[7] = new TemporarySIC("�����뿪�� ���� �ӽü����˻��", "������", "02-3153-8656", "�ӽ�", 0,  0, "", mapo);
	seoul[8] = new TemporarySIC("ȫ�͹�ȭ���� �ӽü����˻��", "������", "02-3153-8308", "�ӽ�", 0, 0, "", mapo);

	// ���� gyeonggi ��ü �ν��Ͻ�ȭ
	
	gyeonggi[0] = new ScreeningIC(pochun);
	gyeonggi[1] = new ScreeningIC(bundang);
	gyeonggi[2] = new ScreeningIC(pyeongtaek);
	gyeonggi[3] = new TemporarySIC("��õ�� ���տ�� ������", "��õ��", "031-538-3686", "�ӽ�", 0, 0, "", pochun);
	gyeonggi[4] = new TemporarySIC("��õ�� ����", "��õ��", "031-538-3686", "�ӽ�", 0, 0, "", pochun);
	gyeonggi[5] = new TemporarySIC("��ž�� ���� ", "������", "031-729-3990", "�ӽ�", 0,  0, "", bundang);
	gyeonggi[6] = new TemporarySIC("źõ���տ��", "������", "031-729-3990", "�ӽ�", 0,  0, "", bundang);
	gyeonggi[7] = new DriveSIC("�Ƿ���� �����Ƿ���� ���ü��𺴿�", "���ý�", "031-1800-8800", "�̵���", 0, 0, "", pyeongtaek);
	gyeonggi[8] = new TemporarySIC("���ߺ������� ������", "���ý�", "031-8024-8003", "�ӽ�", 0, 0, "", pyeongtaek);


	// seoul ���� �Է�
	cout << "=============================================== �������� �Է� ====================================================" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << seoul[i]->getName() << "�� ���� ��� �ο��� �Է��ϼ���: ";
		cin >> input;
		// virtual �Լ��� ���� ������(polymorphism) ���
		seoul[i]->setWaiter(input);
		seoul[i]->setStatus();
		seoul[i]->setWTime();
	}
	cout << endl << endl;

	// gyeonggi ���� �Է�
	cout << "=============================================== ������� �Է� ====================================================" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << gyeonggi[i]->getName() << "�� ���� ��� �ο��� �Է��ϼ���: ";
		cin >> input;
		// virtual �Լ��� ���� ������(polymorphism) ���
		gyeonggi[i]->setWaiter(input);
		gyeonggi[i]->setStatus();
		gyeonggi[i]->setWTime();
		
	}
	cout << endl << endl;

	cout << "============================================= �������� ���� ����� =================================================" << endl;
	// seoul ���� ���
	for (int i = 0; i < 9; i++)
	{

		seoul[i]->print();
		cout << endl;
	}

	cout << endl;
	cout << "============================================= ������� ���� ����� =================================================" << endl;

	// gyeonggi ���� ���
	for (int i = 0; i < 9; i++)
	{
		gyeonggi[i]->print();
		cout << endl;
	}

	// �� ��ü �Ҹ�
	for (int i = 0; i < 9; i++)
	{
		delete seoul[i];
		delete gyeonggi[i];
	}

	return 0;
}
