#include"stdafx.h"
int numindays(int year) {
	int num, daynumber, day, month = 1;
	cout << "������� ���������� ����� ���, ����� ���� ����� �������� ����� � �����, ��������������� ����������� ������ ���";
	cin >> num;
	daynumber = num;
	int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (num > 366) {
		cout << "�� ����� �����, ������� 366. � ��� �� ������" << endl;
		cout << "��������� �������� ���� ����������." << endl; 
		cout << "���������� �� ����������� ����� �����������!" << endl;
		return 0;
	}
	
	if (num < 1) {
		cout << "�� ����� ������������� �������� ����������� ������" << endl;
		cout << "��������� �������� ���� ����������." << endl;
		cout << "���������� �� ����������� ����� �����������!" << endl;
		return 0;
	}

	if (num == 366) {
		Months[1] = 29;
	}
	
	for (int i = 0; num > Months[i]; i++) {
		num = num - Months[i];
		month++;
	}
	day = num;
	cout << "�� ������� ����: " << day << "-�� "; monthName(month);;;


	if (daynumber == 256) {
		cout << "	� ���� ������������!!! ���������������� ��� �����!!!" << endl << endl;
		return 1;
	}

	if (day == 8 && month == 3) {
		cout << "	� ���� ������������ ���� ����������� ������� ����." << endl << endl; 
		return 1;
	}
	if (day == 1 && month == 6) {
		cout << "	����������������!!! ������ ���� ����!" << endl << endl;
		return 1;
	}

	if (day == 1 && month == 1) {
		cout << "	� ����� �����! � ����� ��������!" << endl << endl;
		return 1;
	}

	if (daynumber == 216) {
		cout << "     � ���� ����!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 45) {
		cout << "      � ���� ������� ���������!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 48) {
		cout << "      � ���� ����������� ���������� �������!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 172) {
		cout << "      � �����!!!" << endl << endl;
		return 1;
	}

	if (daynumber == 3) {
		cout << "      � ���� �������� ��������� ��� ���������!!!" << endl << endl;
		return 1;
	}

	return 1;
}