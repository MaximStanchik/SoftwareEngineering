
#include"stdafx.h"

int Incorrect_Data_yes_or_no(int month, int day, int year, int data, int count) {
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
}