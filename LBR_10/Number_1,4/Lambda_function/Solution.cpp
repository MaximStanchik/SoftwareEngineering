//����������� ������-�������, ������� ��������� ��� ������ � ���������� �� ������, ������� �������.

#include <iostream>
#include <string>

using namespace std;

bool toDefinePositiveOrNot(double number)
{
    auto checkPositive = [](double number) {
        return number > 0;
    };

    return checkPositive(number);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "��� ������� 1:" << endl;

    double number;
    cout << "������� �����: ";
    cin >> number;
    if (number == 0) {
        cout << "����� ���������������." << endl;
    }

    if (toDefinePositiveOrNot(number)) {
        cout << "����� �������������." << endl;
    }
    else {
        cout << "����� �� �������������." << endl;
    }

    cout << "��� ������� 4:" << endl;

    string str1, str2;

    cout << "������� ������ ������: ";
    getline(cin, str1);

    cout << "������� ������ ������: ";
    getline(cin, str2);

    auto longer = [&str1, &str2]() {
        return str1.length() > str2.length();
    };

    if (longer()) {
        cout << "������ ������ �������" << endl;
    }
    else if (longer()) {
        cout << "������ ������ �������" << endl;
    }
    else {
        cout << "������ ��������� �� ������" << endl;
    }

    return 0;
}








