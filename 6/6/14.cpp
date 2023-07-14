#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;


struct list
{
	char symbol;
	list* next;
};

struct int_list {
	int num;
	int_list* next;
};

void insert(list*& p, char value);
void printList(list* p);
void toFile(list*& p);
void fromFile(list*& p);
void Interface() {
	cout << "\t\t�������� �������:" << endl;
	cout << "1 - ���������� �������� � ������" << endl;
	cout << "2 - ����� ���� ������������ ��������� ������" << endl;
	cout << "3 - �������� ������ � ����" << endl;
	cout << "4 - ������ ������ �� �����" << endl;
	cout << "5 - ������� � ��������� ������������ ������" << endl;
	cout << "6 - ����� �� ���������" << endl;
}
// labratory work functions
void lab14function() {
	int_list* plist = nullptr; // ��������� �� ������ ������
	int_list* ptr;
	int N = 0;
	cout << "������� ���������� ��������� ������(N):" << endl;
	cin >> N;
	int number = 0;

	for (int i = 0; i < N; i++)
	{
		cout << "������� " << i + 1 << " ���� ������:" << endl;
		cin >> number;
		ptr = new int_list;
		ptr->num = number;
		ptr->next = plist;
		plist = ptr;
	}

	ptr = plist;
	int sum = 0;
	cout << "�� �����: ";

	for (int i = 0; i < N; i++)
	{
		cout << ptr->num << " ";
		ptr = ptr->next;
	}

	cout << endl;
	ptr = plist;

	for (int i = 0; i < N; i++)
	{
		if (ptr->num % 5 == 0 && ptr->num < 0) {
			sum += ptr->num;
		}
		ptr = ptr->next;
	}
	if (sum != 0)
		cout << "����� ������������� ���������,������� 5: " << sum << endl;
	else
		cout << "����� ��������� ���!" << endl;


}
void lab1function() {
	int_list* plist = nullptr; // ��������� �� ������ ������
	int_list* ptr;
	int N = 0;
	cout << "������� ���������� ��������� ������(N):" << endl;
	cin >> N;
	int number = 0;

	for (int i = 0; i < N; i++)
	{
		cout << "������� " << i + 1 << " ���� ������:" << endl;
		cin >> number;
		ptr = new int_list;
		ptr->num = number;
		ptr->next = plist;
		plist = ptr;
	}

	ptr = plist;
	int sum = 0;
	cout << "�� �����: ";

	for (int i = 0; i < N; i++)
	{
		cout << ptr->num << " ";
		ptr = ptr->next;
	}

	cout << endl;
	ptr = plist;

	for (int i = 0; i < N; i++)
	{
		if (ptr->num>0) {
			sum += ptr->num;
		}
		ptr = ptr->next;
	}
	if (sum != 0)
		cout << "����� ������������� ���������: " << sum << endl;
	else
		cout << "����� ��������� ���!" << endl;


}
void lab6function() {
		int_list* plist = nullptr; // ��������� �� ������ ������
		int_list* ptr;
		int N = 0;
		cout << "������� ���������� ��������� ������(N):" << endl;
		cin >> N;
		int number = 0;
	
		for (int i = 0; i < N; i++)
		{
			cout << "������� " << i + 1 << " ���� ������:" << endl;
			cin >> number;
			ptr = new int_list;
			ptr->num = number;
			ptr->next = plist;
			plist = ptr;
		}
	
		ptr = plist;
		int sum = 0;
		cout << "�� �����: ";
	
		for (int i = 0; i < N; i++)
		{
			cout << ptr->num << " ";
			ptr = ptr->next;
		}
	
		cout << endl;
		ptr = plist;
	
		for (int i = 0; i < N; i++)
		{
			if (ptr->num <= -10 && ptr->num >-100) {
				sum += ptr->num;
			}
			ptr = ptr->next;
		}
		if (sum != 0)
			cout << "����� ������������� ����������� ���������: " << sum << endl;
		else
			cout << "����� ��������� ���!" << endl;
}
void lab8function() {
	int_list* plist = nullptr; // ��������� �� ������ ������
	int_list* ptr;
	int N = 0;
	cout << "������� ���������� ��������� ������(N):" << endl;
	cin >> N;
	int number = 0;

	for (int i = 0; i < N ; i++)
	{
		cout << "������� " << i + 1 << " ���� ������:" << endl;
		cin >> number;
		ptr = new int_list;
		ptr->num = number;
		ptr->next = plist;
		plist = ptr;
	}
	
	ptr = plist;
	int sum = 0;
	cout << "�� �����: ";

	for (int i = 0; i < N; i++)
	{
		cout << ptr->num << " ";
		ptr = ptr->next;
	}
	
	cout << endl;
	ptr = plist;

	for (int i = 0; i < N; i++)
	{
		if (ptr->num < 0 && ptr->num % 2 == 0) {
			sum += ptr->num;
		}
		ptr = ptr->next;
	}
	if (sum != 0)
		cout << "����� ������������� ���������,������� 5: " << sum << endl;
	else
		cout << "����� ��������� ���!" << endl;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list* listPointer = nullptr;
	int choice;
	while (true) {
		Interface();
		cin >> choice;
		switch (choice)
		{
		case 1: {
			char AddingSymbol;
			cout << "������� ������� , ������� ������ ��������:" << endl;
			cin >> AddingSymbol;
			insert(listPointer, AddingSymbol);
			break;
		}
		case 2: {
			printList(listPointer);
			break;
		}
		case 3: {
			toFile(listPointer);
			break;
		}
		case 4: {
			fromFile(listPointer);
			break;
		}
		case 5: {
			cout << "1 - ������� 14" << endl;
			cout << "2 - ������� 1" << endl;
			cout << "3 - ������� 6" << endl;
			cout << "4 - ������� 8" << endl;
			cout << "5 - ��������� � ������� ����" << endl;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				lab14function();
				break;
			}
			case 2: {
				lab1function();
				break;
			}
			case 3: {
				lab6function();
				break;
			}
			case 4: {
				lab8function();
				break;
			}
			case 5: {
				continue;
			}
			default:
				break;
			}
			break;
		}
		case 6: {
			return EXIT_SUCCESS;
		}
		default:
			cout << "������� ������ ������� !" << endl;
			break;
		}
	}
}

void insert(list*& p, char value)
{
	list* newP = new list;
	if (newP != NULL)
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}

void printList(list* p)
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	char buf;
	ofstream frm("InfoFile.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = temp->symbol;
		frm << buf;
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� InfoFile.txt\n";
}

void fromFile(list*& p)
{
	char buf;
	list* first = nullptr;
	ifstream frm("InfoFile.txt");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (!frm.eof())
	{
		frm >> buf;
		insert(first, buf);
		cout << "-->" << buf;
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\n������ ������ �� ����� InfoFile.txt\n";
}
