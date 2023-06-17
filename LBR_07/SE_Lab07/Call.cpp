#include <iostream>


int _cdecl sum(int x, int y, int z) { return x + y + z; };
int _stdcall mul(int& a, int b, int c) { return a * b * c; };
int _fastcall sum(int x, int y, int z, int d) { return x + y + z + d; };





int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	int x, y, z;
	std::cout << "������� �������� x: ";
	std::cin >> x;
	std::cout << "������� �������� y: ";
	std::cin >> y;
	std::cout << "������� �������� z: ";
	std::cin >> z;
	int rc_cdecl = sum(x, y, z);
	std::cout << "(_cdecl) ����� � y z: " << rc_cdecl << std::endl;
	int a = 2, b = 3, c = 4;
	int result = mul(c, a, b);
	std::cout << "(_stdcall) ���������: " << result << std::endl; // ������� "���������: 24"
	int rc_fastcall = sum(1, 2, 3, 4);
	std::cout << "(_fastcall): ����� � y z d: " << rc_fastcall << std::endl;
	return 0;
}