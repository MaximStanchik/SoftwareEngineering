#include"stdafx.h"

bool leapOrNot(int year)
{
	//��� �������
	if (year % 4 == 0) {
		cout <<"��� ����������"<< endl;
		return true;
		
	}
	else {
		cout << "��� �� ����������" << endl;
		return false;
	}
}