#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 4

using namespace std;

struct TRAIN
{
	string station;
	string trainNumber;
	string time;

	void input()
	{
		cout << "������� �������: ";
		getline(cin, station);
		cout << "������� ����� ������: ";
		getline(cin, trainNumber);
		cout << "������� ����� ����������� (hh:mm): ";
		getline(cin, time);
		cout << endl << endl;
	}

	void output()
	{
		cout << "�������: " << station << endl;
		cout << "����� ������: " << trainNumber << endl;
		cout << "����� �����������: " << time << endl << endl;
	}

	bool trainSearch(string time)
	{
		bool flag = false;

		if (this->time >= time)
		{
			output();
			flag = true;
		}

		return flag;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;
	TRAIN trains[SIZE];

	do
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ������ ������" << endl;
		cout << "2 - ����� � ����� �� �������" << endl;
		cout << "3 - ����� " << endl << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << endl;
			cin.ignore();
			for (int i = 0; i < SIZE; i++)
			{
				cout << endl << "������� ������ " << i + 1 << "-��� ������" << endl << endl;
				trains[i].input();
			}
			break;
		}
		case 2:
		{
			cout << "������� ����� =" << endl;
			string time;
			cin.ignore();
			getline(cin, time);

			bool check[SIZE] = {};

			for (int i = 0; i < SIZE; i++)
			{
				check[i] = trains[i].trainSearch(time);
			}

			int counterFalse = 0;

			for (int i = 0; i < SIZE; i++)
			{
				if (!check[i])
				{
					counterFalse++;
				}
				if (counterFalse == SIZE)
				{
					cout << "������� �� �������!" << endl;
				}
			}
			break;
		}
		case 3:
		{
			break;
		}
		}
	} while (choice != 3);
}