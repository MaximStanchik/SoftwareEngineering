//������� 2.
//1. ������� � ���� ��������� �������, ����������� � ������� 1.
//2. ���������� ���������� ����� ������ ��� ����� ��������� �� ��������.
//3. ������������ ��� �������� ��� ������, ���������� � ����� �������� ����, ����������� ��������� � ����������������� �� ����������.

//������� 11
//������� �� ������������ ������: �����: ��� �����(�����, ��������������, �����������); ��������, ����������� � ���� ������


#include<iostream>
#include <complex>
using namespace std;


typedef int whole;
typedef int valid;
typedef complex<double> comprehensive;

struct Number {
	whole X;
	valid Y;
	comprehensive Z;
};

bool operator < (Number n1, Number n2)
{
	if (n1.X < n2.X)
		return 1;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	Number numb1{50, -3367, (2.0, 3.0)};
	Number numb2{500, 10,  (-4.0, 2.0)};
	if (numb1 < numb2)
		cout << "������ ����� ����� ������ �������" << endl;
	else
		cout << "������ ����� ����� �� ������ �������"<<endl;
	std::cout << "�������� ��������:" << std::endl;
	std::cout << numb1.X + numb2.X;
	}



