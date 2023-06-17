#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<time.h>

using namespace std;

struct hashTable
{
	int number{};
	string name{};
	hashTable* next{ NULL }, * prev{ NULL };
};

struct helpTable
{
	int number{};
	string name{};
	helpTable* next;
};

int creat(int, hashTable**, int);
void show(hashTable**, int);
hashTable* locate(int, hashTable*);
void dele(int, hashTable**);
int sort(hashTable**, int, int*, string*);
int creat2(helpTable*, hashTable**, int);

void main()
{
	setlocale(LC_ALL, "ru");
	HANDLE color{ GetStdHandle(STD_OUTPUT_HANDLE) };

	int numb{}, n{ 16 }, schet{}, var{};
	hashTable** start{ new hashTable * [n] };

	for (int i{}; i < n; i++)
		start[i] = NULL;

	while (true)
	{
		SetConsoleTextAttribute(color, 15);
		system("cls");
		cout << "�������� �����\n";
		cout << "1 - �������� ��������� �������\n";
		cout << "2 - �������� �����\n";
		cout << "3 - ������� �����\n";
		cout << "4 - ����� �� ������\n";
		cout << "5 - ������� ���\n";
		cout << "6 - �����\n";
		cin >> var;

		switch (var)
		{
		case 1:
		{
			int col{};
			cout << "������ ���������� �������:\t";
			cin >> col;
			for (int i{}; i < col; i++)
			{
				cout << i + 1 << ") ������� ����� ��������:\t";
				cin >> numb;
				if (!cin || numb < 1)
				{
					cout << "������ �� ����� ����\n";
					cin.clear();
					cin.ignore(100, '\n');

					continue;
				}
				try
				{
					schet = creat(numb, &start[numb % n], schet);
				}
				catch (const std::exception& el)
				{
					SetConsoleTextAttribute(color, 4);
					cout << el.what() << '\n';
					SetConsoleTextAttribute(color, 15);
					i--;
				}
			}
		}
		break;

		case 2:
			while (true)
			{
				cout << "������� ����� ��������:\t";
				cin >> numb;
				if (!cin || numb < 1)
				{
					cout << "������ �� ����� ����\n";
					cin.clear();
					cin.ignore(100, '\n');
					continue;
				}
				try
				{
					schet = creat(numb, &start[numb % n], schet);
				}
				catch (const std::exception& el)
				{
					SetConsoleTextAttribute(color, 4);
					cout << el.what() << '\n';
				}
				break;
			}
			break;

		case 3:
			cout << "������� ����� ������� ���� �������:\t";
			cin >> numb;
			if (!cin || numb < 1)
			{
				cout << "������ �� ����� ����\n";
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
			try
			{
				dele(numb, &start[numb % n]);
			}
			catch (const std::exception& el)
			{
				SetConsoleTextAttribute(color, 4);
				cout << el.what() << '\n';
				cin.clear();
				cin.ignore(100, '\n');
			}
			break;

		case 4:
			cout << "������� ������� �����:\t";
			cin >> numb;
			if (!cin || numb < 1)
			{
				cout << "������ ������ ����� ���\n";
				cin.clear();
				cin.ignore(100, '\n');
				break;
			}
			try
			{
				hashTable* help{ locate(numb, start[numb % n]) };
				cout << "���� ����� �����������:\t" << help->name << '\n';
			}
			catch (const std::exception& el)
			{
				SetConsoleTextAttribute(color, 4);
				cout << el.what() << '\n';
			}
			break;

		case 5:
			try
			{
				show(start, n);
			}
			catch (const std::exception& el)
			{
				SetConsoleTextAttribute(color, 4);
				cout << el.what() << '\n';
			}
			break;

		case 6:
			cout << "�����\n";
			SetConsoleTextAttribute(color, 0);
			exit(0);
			break;

		default:
			cout << "������ �������� ���\n";
			cin.clear();
			cin.ignore(100, '\n');
			break;
		}
		if (var == 1 || var == 2)
		{
			if (schet >= (double)(n * 0.7))
			{
				hashTable* q{}, * m{};
				helpTable* go{ NULL }, * j{}, * l{};

				for (int i = 0; i < n; i++)
				{
					if (start[i] != NULL)
					{
						q = start[i];
						while (q != NULL)
						{
							j = new helpTable;

							j->number = q->number;
							j->name = q->name;
							j->next = NULL;

							if (go == NULL)
							{
								go = l = j;
							}
							else
							{
								l->next = j;
								l = j;
							}

							m = q;
							q = q->prev;
							delete m;
						}
					}
				}

				schet = 0;
				start = new hashTable * [n];
				n *= 2;
				for (int i{}; i < n; i++)
					start[i] = NULL;

				while (go != NULL)
				{
					schet = creat2(go, &start[(go->number) % n], schet);
					l = go;
					go = go->next;
					delete l;
				}
			}
		}

		SetConsoleTextAttribute(color, 0);
		system("pause");
	}

	delete[] start;
}

int creat(int numb, hashTable** use, int st)
{
	hashTable* q{ new hashTable };
	string name{};

	q->number = numb;

	if (*use != NULL)
	{
		hashTable* c{ *use };

		while (c != NULL)
		{
			if (c->number == q->number)
			{
				delete q;
				throw exception("����� ����� ��� ���");
			}
			c = c->prev;
		}
		(**use).next = q;
		q->prev = (*use);
		q->next = NULL;
	}
	else
	{
		q->next = q->prev = NULL;
		st++;
	}

	*use = q;

	cout << "������� ������� ��� ��� �����:\t";
	cin >> name;
	(*q).name += name;
	cout << "������� ��� ��������� ������:\t";

	cin >> name;
	(*q).name += ' ';
	(*q).name += name;

	cout << "������� ���������\n";

	return st;
}

void dele(int numb, hashTable** use)
{
	int var{};
	hashTable* del{ *use };
	while (del != NULL && del->number != numb)
		del = del->prev;

	if (del == NULL)
		throw exception("���� ����� �� ������");

	cout << "��� ����� " << del->name << '\n';
	cout << "���� �� ��� ��� ������� ��� ������ ������� ������� �� 1:\t";
	cin >> var;

	if (var != 1)
		throw exception("�������� ������ ��������");

	if (del == *use)
	{
		*use = del->prev;
		if (*use != NULL)
			(**use).next = NULL;
		else
			*use = NULL;
	}
	else
	{
		if (del->prev == NULL)
			(del->next)->prev = NULL;
		else
		{
			(del->next)->prev = del->prev;
			(del->prev)->next = del->next;
		}
	}

	delete del;
	cout << "����� ������\n";
}

void show(hashTable** start, int n)
{
	int schet{};
	hashTable* q{};
	cout << "�����\t\t\t\t" << "������\n" << setw(50) << setfill('=') << '=' << '\n';
	for (int i = 0; i < n; i++)
	{
		if (start[i] != NULL)
		{
			q = start[i];
			while (q != NULL)
			{
				cout << ++schet << ")" << q->name << '(';
				cout.width(20);
				cout << ") \"" << q->number << "\"\n";
				q = q->prev;
			}
		}
	}
	if (schet == 0)
		throw exception("������ �����");
}

hashTable* locate(int numb, hashTable* use)
{
	clock_t start{ clock() };

	hashTable* c{ use };
	while (c != NULL && c->number != numb)
		c = c->prev;

	if (c == NULL)
		throw exception("���� ����� �� ������");
	clock_t end{ clock() };
	double time{ (double)(end - start) / CLOCKS_PER_SEC };
	cout << time * 1'000'000'000'000 << " ������\n\n";
	return c;
}

int creat2(helpTable* g, hashTable** use, int st)
{
	hashTable* q{ new hashTable };
	q->number = g->number;
	q->name = g->name;

	if (*use != NULL)
	{
		(**use).next = q;
		q->prev = (*use);
		q->next = NULL;
	}
	else
	{
		q->next = q->prev = NULL;
		st++;
	}

	*use = q;

	return st;
}o9