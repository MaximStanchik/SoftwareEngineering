#include "stdafx.h"
using namespace std;
void monthName(int month) {
	setlocale(LC_CTYPE, "");
	string names[12] = { "������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "�������", "������", "�������" };
	cout << names[month - 1] << endl << endl;

}