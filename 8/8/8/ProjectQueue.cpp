#include"stdafx.h"

void menu() {
	cout << "------------------------------------------------------------" << endl;
	cout << "1 - �������� ������� � �������" << endl;
	cout << "2 - ������� ������� �������" << endl;
	cout << "3 - ����� ���� �������" << endl;
	cout << "4 - �������� ������ ������� �������" << endl;
	cout << "5 - ������� �������" << endl;
	cout << "6 - ��������� ������� �� � ������� ��������� ������..." << endl;
	cout << "------------------------------------------------------------" << endl;

}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int SizeOfQueue = 0;
	cout << "������� ������������ ������ ������� = "; cin >> SizeOfQueue;
	Queue q(SizeOfQueue);
	int choice = 0;
	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1: {
			static char AddingObject;
			cout << "������� ������, ������� ������ �������� = "; cin >> AddingObject;
			q.EnQueue(AddingObject);
			q.Show();
			break;
		}
		case 2: {
			q.DeQueue();
			q.Show();
			break;
		}
		case 3: {
			q.Show();
			break;
		}
		case 4: {
			q.Peek();
		}
		case 5: {
			q.clear();
			break;
		}
		case 6: {
			static char etalon;
			cout << "������� ��������� ������ = "; cin >> etalon;
			q.LabFunction(etalon);
		}
		default:
			break;
		}
	}

}