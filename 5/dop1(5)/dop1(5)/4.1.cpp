
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct client
{
	string fio;
	enum type
	{
		depozit = 1, srocnyi, lgotnyi

	}typescore = { depozit };
	string numberscore;
	string sumofscore;
	struct date
	{
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 12;

	}datescore = { 0, 0, 0 };

	void Input() 
	{
		int tmpscore;
		unsigned int day, month, year;
		bool flag;
		typescore = depozit;
		do {
			flag = false;
			cin.ignore();
			cout << endl << "������� ���" << endl;
			getline(cin, fio);
			cout << endl << "������� ��� �����(1-�������, 2-�������, 3-��������)" << endl;
			cin >> tmpscore;
			if (tmpscore == 1)
				typescore = depozit;
			else if (tmpscore == 2)
				typescore = srocnyi;
			else if (tmpscore == 3)
				typescore = lgotnyi;
			else flag = true;
			
			if (tmpscore < 1 || tmpscore>3)
				flag = true;
			cin.ignore();
			cout << endl << "������� ����� �����" << endl;
			getline(cin, numberscore);
			cout << endl << "������� ����� �� �����" << endl;
			getline(cin, sumofscore);
			cout << endl << "������� ���� ���������� ���������(�� �� ����)" << endl;
			cin >> day >> month >> year;
			if (day > 0 && day < 32 && month>0 && month < 13 && year>0 && year < 4096)
			{
				datescore.day = day;
				datescore.month = month;
				datescore.year = year;
			}
			else flag = true;
			if (flag == true)
				cout << "���� �� �������� ���� ������� ������, ��������� ����" << endl;
		} while (flag == true);
	}

	int Print()
	{
		int cou;
		string tmptypescore;
		if (typescore == depozit)
			tmptypescore = "�������";
		else if (typescore == srocnyi)
			tmptypescore = "�������";
		else if (typescore == lgotnyi)
			tmptypescore = "�������";
		if (fio != "")
		{
			cout << endl << "���: " << fio << endl << "��� �����: " << tmptypescore << endl << "����� �����: " << numberscore << endl << "����� �� �����: " << sumofscore << endl << "����: " << datescore.day << "." << datescore.day << "." << datescore.year << endl;
			cou = 1;
			return cou;
		}
		else
		{
			cou = 0;
			return cou;
		}
	}

	int Delete(string nazvanie)
	{
		int cou;
		if (this->fio == nazvanie)
		{
			fio = "";
			numberscore = "";
			sumofscore = "";
			cout << "������� �������!" << endl;
			cou = 1;
			return cou;
		}
		else
		{
			cou = 0;
			return cou;
		}

	}

	int Search(string nazvanie)
	{
		int cou;
		if (this->fio == nazvanie)
		{
			cout << endl << "������ ������!\n" << endl;
			Print();
			cou = 1;
			return cou;
		}
		else
		{
			cou = 0;
			return cou;
		}

	}

	int PrintSum(int tmpsum)
	{
		int cou;
		if (fio != "")
		{
			int c = stoi(sumofscore);
			if (c > tmpsum)
			{
				
				string tmptypescore;
				if (typescore == depozit)
					tmptypescore = "�������";
				else if (typescore == srocnyi)
					tmptypescore = "�������";
				else if (typescore == lgotnyi)
					tmptypescore = "��������";

				cout << endl << "���: " << fio << endl << "��� �����: " << tmptypescore << endl << "����� �����: " << numberscore << endl << "����� �� �����: " << sumofscore << endl << "����: " << datescore.day << "." << datescore.day << "." << datescore.year << endl;
				cou = 1;
				return cou;

			}
		}
		else
		{
			cou = 0;
			return cou;
		}
	}
}clientofbank[50];


void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int con = 0;
	int choise;

	do {
		cout << "\n\n1. ���� ������ �������\n2. ����� ���� ��������\n3. ������� �������\n4. ����� �������\n5. ����� �� �����\n6. ��������� ���������\n";
		cin >> choise;
		cout << endl << endl;
		switch (choise)
		{
		case 1:
		{
			cout << endl;
			clientofbank[con].Input();
			con++;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			con = 0;
			int flag = 0;
			for (int i = 0; i < 50; i++)
			{
				con = clientofbank[i].Print();
				if (con != 0)
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "��� ��������!" << endl;
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			con = 0;
			string nazvanie;
			cout << "������� ��� �������: " << endl;
			cin.ignore();
			getline(cin, nazvanie);
			cout << endl;
			for (int i = 0; i < 50; i++)
			{
				con = clientofbank[i].Delete(nazvanie);
				if (con == 1)
				{
					break;
				}
			}
			if (con == 0)
			{
				cout << "������ �� ������!" << endl;
			}
			cout << endl;
			break;
		}
		case 4:
		{
			cout << endl;
			con = 0;
			string nazvanie;
			cout << "������� ��� �������: " << endl;
			cin.ignore();
			getline(cin, nazvanie);
			cout << endl;
			for (int i = 0; i < 50; i++)
			{
				con = clientofbank[i].Search(nazvanie);
				if (con == 1)
				{
					break;
				}
			}
			if (con == 0)
			{
				cout << "������ �� ������!" << endl;
			}
			cout << endl;
			break;
		}
		case 5:
		{
			cout << endl;
			con = 0;
			int flag = 0;
			int tmpsum;
			cout << endl;
			cout << "������� ������ ����� ����� ������ ������ ��������: " << endl;
			cin >> tmpsum;

			for (int i = 0; i < 50; i++)
			{
				con = clientofbank[i].PrintSum(tmpsum);;
				if (con != 0)
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << "��� ��������!" << endl;
			}
			cout << endl;
		}
		default:
			break;
		}
	} while (choise != 6);
}

