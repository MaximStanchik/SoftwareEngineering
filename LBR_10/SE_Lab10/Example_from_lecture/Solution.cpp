#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int target1{ 3 };

	int items1{ count(v.begin(), v.end(),target1) };
	cout << "�����:\t" << target1 << "\n����������:\t" << items1 << '\n';

	int items3{ count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; }) };
	cout << "����� ������� ����:\t" << items3 << '\n';

	cout << "\n������ ����������\n";
	for (auto i : v)[i]() {if (i % 3 == 0)cout << i << ' '; }();

	cout << "\n����� � �����������\n";
	for (auto i : v)[](auto i) {if (i % 3 == 0)cout << i << ' '; }(i);

	cout << "\n����� ��� ����������\n";
	for (auto i : v)[i] {if (i % 3 == 0)cout << i << ' '; }();

	cout << "\n���������� ������������� � ������������� �����\n";
	vector<int> dob{ 1, -2, 3, -4, 5, -6, 7, -8, -9,10 };
	for (auto i : dob)[i]() {if (i > 0)cout << i << "\ttrue\n"; else cout << i << "\tfalse\n"; }();
}