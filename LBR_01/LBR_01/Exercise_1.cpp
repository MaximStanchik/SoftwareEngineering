#include<iostream>
#include <ctime>
#include <string>
#include "stdafx.h"
//count--�������

using namespace std;

//��� � ��� ������� ��� �������� ������� ����


int main() {
	setlocale(LC_CTYPE, "ru");
	int DATA = stoi(currentDateTime());
	int data, day, month, year,A, days{}, Birthday, YearOfBirthday, NumberOfcurrentDay, left;
	int count = 0;
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cout << "������� ���� � ������� '��������': ";
	cin >> data;

	day = data / 1000000; //������ ��� ���������� �������� ������ ���� � ����� ���� � ��� ���������� � ����. �������� ������ ����. 
	month = (data % 1000000) / 10000;
	year = data % 10000;

	

	//��� ���� ������� ���������� ���-�� ���� ������� ��� ���. ���� �� ���� ��� ������� ����� ��������� �����������.

	while (data > 0) {
		data /= 10; // /= ������ ��������� ���������� �� �������� � ����� ��������� ���� �� ����������
		count++;
	}
	if (count < 7 && count > 8) {
		cout << "�������� ���������� ������ ��� � ���� �������� �����";
		exit(0);
	}

	//��� ���������� ��������� �� ������ ����

	if (month == 01 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������ 31 ����)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 != 0 && day > 28) {
		cout << "�� ����� ������� ������� �������� (� ������� � ������������ ���� 28 ����)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 == 0 && day > 29) {
		cout << "�� ����� ������� ������� �������� (� ������� � ���������� ���� 29 ����)" << endl;
		return 0;
	}
	if (month == 03 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ����� 31 ����)" << endl;
		return 0;
	}
	if (month == 04 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
		return 0;
	}
	if (month == 05 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ��� 31 ����)" << endl;
		return 0;
	}
	if (month == 06 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ���� 30 ����)" << endl;
		return 0;
	}
	if (month == 07 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ���� 31 ����)" << endl;
		return 0;
	}
	if (month == 8 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}
	if (month == 9 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� �������� 30 ����)" << endl;
		return 0;
	}
	if (month == 10 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}
	if (month == 11 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
		return 0;
	}
	if (month == 12 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}

	//��� ���������� ��������� �� ������ �����

	if (month > 12) {
		cout << "�������� ������ ������, � ������:����� ������ 12";
		exit(0);
	}
	if (month < 1) {
		cout << "�������� ������ ������, � ������:����� ������ 1";
		exit(0);
	}


	//��� ���������� ��������� �� ����� ��� ��� ���
	if (year < 0) {
		cout << "�� ����������� ����� ���, � ������: ��� �������������" << endl;
		return 0;
	}

	//��� ���������� ��� ���������� ��� ���

	leapOrNot(year);


	//��� �� ������� ���������� ����� ��� � ����


	NumberOfDay(month, days, day, year);
	/*A= NumberOfDay(month, days, day, year);*/
	cout << "���������� ����� ���: " << NumberOfDay(month, days, day, year)<< endl;
	days = 0;
	day = 0;




	//��� �� ������ ���� �������� 
	cout << "������� ���� ��������� ���� ��� �������� '��������': ";
	cin >> data;

	day = data / 1000000; //������ ��� ���������� �������� ������ ���� � ����� ���� � ��� ���������� � ����. �������� ������ ����. 
	month = (data % 1000000) / 10000;
	year = data % 10000;

	

	//���� ��� ���������� � ������� 29 ����
	if (year % 4 == 0) {
		Months[1] = 29;
	}


	//�������� ������������ ��������� ����
	if (month == 01 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������ 31 ����)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 != 0 && day > 28) {
		cout << "�� ����� ������� ������� �������� (� ������� � ������������ ���� 28 ����)" << endl;
		return 0;
	}
	if (month == 02 && year % 4 == 0 && day > 29) {
		cout << "�� ����� ������� ������� �������� (� ������� � ���������� ���� 29 ����)" << endl;
		return 0;
	}
	if (month == 03 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ����� 31 ����)" << endl;
		return 0;
	}
	if (month == 04 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
		return 0;
	}
	if (month == 05 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ��� 31 ����)" << endl;
		return 0;
	}
	if (month == 06 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ���� 30 ����)" << endl;
		return 0;
	}
	if (month == 07 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ���� 31 ����)" << endl;
		return 0;
	}
	if (month == 8 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}
	if (month == 9 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� �������� 30 ����)" << endl;
		return 0;
	}
	if (month == 10 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}
	if (month == 11 && day > 30) {
		cout << "�� ����� ������� ������� �������� (� ������ 30 ����)" << endl;
		return 0;
	}
	if (month == 12 && day > 31) {
		cout << "�� ����� ������� ������� �������� (� ������� 31 ����)" << endl;
		return 0;
	}
	
	//�������� ���-�� ���� (�� ������ ���� 8)
	while (data > 0) {
		data /= 10; // /= ������ ��������� ���������� �� �������� � ����� ��������� ���� �� ����������
		count++;
	}
	if (count < 7 && count > 8) {
		cout << "�������� ���������� ������ ��� � ���� �������� �����";
		exit(0);
	}
	//��� ���������� ��������� �� ������ �����

	if (month > 12) {
		cout << "�������� ������ ������, � ������:����� ������ 12";
		exit(0);
	}
	if (month < 1) {
		cout << "�������� ������ ������, � ������:����� ������ 1";
		exit(0);
	}


	////����� � ��� �������������� ������� ���� ��� ����,����� ����� ��������� ������� ���� �������� �� ���������� ��� ��������
	
	
	

	
	NumberOfDay(month, days, day, year);
	Birthday = NumberOfDay(month, days, day, year);
	days = 0;
	day = 0;
	YearOfBirthday = year;
	int MOUNTH = month;
	year = 0;
	month = 0;

	day = DATA / 1000000; //������ ��� ���������� �������� ������ ���� � ����� ���� � ��� ���������� � ����. �������� ������ ����. 
	month = (DATA % 1000000) / 10000;
	year = DATA % 10000;


	//���� ��� ���������� � ������� 29 ����
	if (year % 4 == 0) {
		Months[1] = 29;
	}




	NumberOfDay(month, days, day, year);
	NumberOfcurrentDay = NumberOfDay(month, days, day, year);
	//cout << "���������� ����� ���: " << numberofday << endl;
	days = 0;
	day = 0;



	//����������� ������� ���� �������� �� ��� ��������
	if (year == YearOfBirthday && Birthday>NumberOfcurrentDay) {
		left=Birthday-NumberOfcurrentDay;
		cout << "�� ������ ��� �������� �������� "<<left<<" ����"<< endl;	
	}
	else if (YearOfBirthday==year+1 && year % 4 == 0) {
		left = 366-NumberOfcurrentDay + Birthday;
		cout << "�� ������ ��� �������� �������� " << left << " ����" << endl;
	}
	else if (YearOfBirthday == year + 1 && year % 4 != 0) {
		left = 365 - NumberOfcurrentDay + Birthday;
		cout << "�� ����� ����������� ��������� ���� ��������, � ������: ��� ��������� ���� �������� ����� � ���� ����."<< endl;
	}
	else if (YearOfBirthday<year) {
		cout << "�� ����� ����������� ��������� ���� ��������, � ������: ��� ���������� ��� �������� ������ ��� ������� ���." << endl;
	}
	else if (YearOfBirthday > year + 1) {
		cout << "�� ����� ����������� ��������� ���� ��������, � ������: ��������� ���� �������� ����� ��������� ���?! ���! ���, ����������, ������� ���� ���������." << endl;
	}
	else if (year == YearOfBirthday && NumberOfcurrentDay > NumberOfcurrentDay && year % 4 == 0) {
		left =366- NumberOfcurrentDay+ Birthday;
		cout << "�� ������ ��� �������� �������� " << left << " ����"<< endl;
	}
	else if (year == YearOfBirthday && NumberOfcurrentDay > NumberOfcurrentDay && year % 4 != 0) {
		left = 365 - NumberOfcurrentDay + Birthday;
		cout << "�� ������ ��� �������� �������� " << left << " ����"<< endl;
	}
	else if (month >month && YearOfBirthday>year) {
		cout << "�� ����������� ����� ����. ������ ������������." << endl;	
	}
	cout << "��������� ��������� ���� ����������. ���������� �� ������������� ������ ����������" << endl;
	system("pause");
	return 0;
}




