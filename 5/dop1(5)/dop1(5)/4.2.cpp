//#include <iostream>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//union client_info {
//
//	struct client2
//	{
//		string fio;
//		int typescore;
//		string numberscore;
//		string sumofscore;
//		struct date
//		{
//			unsigned int day : 5;
//			unsigned int month : 4;
//			unsigned int year : 12;
//
//		}datescore = { 0,0,0 };
//	};
//};
//
//
//
//struct client
//{
//	string fio;
//	int typescore;
//	string numberscore;
//	string sumofscore;
//	struct date
//	{
//		unsigned int day : 5;
//		unsigned int month : 4;
//		unsigned int year : 12;
//
//	}datescore = { 0,0,0 };
//
//	void ClientAdding(client_info::client2 temp_client) {
//		fio = temp_client.fio;
//		typescore = temp_client.typescore;
//		numberscore = temp_client.numberscore;
//		sumofscore = temp_client.sumofscore;
//		datescore.day = temp_client.datescore.day;
//		datescore.month = temp_client.datescore.month;
//		datescore.year= temp_client.datescore.year;
//	}
//
//	
//
//	int Print()
//	{
//		int cou;
//		string tmptypescore;
//		if (typescore == 1)
//			tmptypescore = "�������";
//		else if (typescore == 2)
//			tmptypescore = "�������";
//		else if (typescore == 3)
//			tmptypescore = "��������";
//		if (fio != "")
//		{
//			cout << endl << "���: " << fio << endl << "��� �����: " << tmptypescore << endl << "����� �����: " << numberscore << endl << "����� �� �����: " << sumofscore << endl << "����: " << datescore.day << "." << datescore.day << "." << datescore.year << endl;
//			cou = 1;
//			return cou;
//		}
//		else
//		{
//			cou = 0;
//			return cou;
//		}
//	}
//
//
//
//	int Search(string nazvanie)
//	{
//		int cou;
//		if (this->numberscore == nazvanie)
//		{
//			cout << endl << "������ ������!\n" << endl;
//			Print();
//			cou = 1;
//			return cou;
//		}
//		else
//		{
//			cou = 0;
//			return cou;
//		}
//
//	}
//
//
//}clientofbank[50] = {};
//
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int con = 0;
//	int choise;
//	client_info::client2 client = {};
//	do {
//		cout << "\n\n1. ���� ������ �������\n2. ����� ���� ��������\n3. ����� �������\n4. ��������� ���������\n";
//		cin >> choise;
//		cout << endl << endl;
//		switch (choise)
//		{
//		case 1:
//		{
//			cout << endl;
//			unsigned int day, month, year;
//			bool flag;
//			do {
//				flag = false;
//				cin.ignore();
//				cout << endl << "������� ���" << endl;
//				getline(cin, client.fio);
//				cout << endl << "������� ��� �����(1-�������, 2-�������, 3-��������)" << endl;
//				cin >>client.typescore;
//				if (client.typescore < 1 || client.typescore>3)
//					flag = true;
//				cin.ignore();
//				cout << endl << "������� ����� �����" << endl;
//				getline(cin, client.numberscore);
//				cout << endl << "������� ����� �� �����" << endl;
//				getline(cin, client.sumofscore);
//				cout << endl << "������� ���� ���������� ���������(�� �� ����)" << endl;
//				cin >> day >> month >> year;
//				if (day > 0 && day < 32 && month>0 && month < 13 && year>0 && year < 4096)
//				{
//					client.datescore.day = day;
//					client.datescore.month = month;
//					client.datescore.year = year;
//				}
//				else flag = true;
//				if (flag == true)
//					cout << "���� �� �������� ���� ������� ������, ��������� ����" << endl;
//			} while (flag == true);
//			clientofbank[con].ClientAdding(client);
//			con++;
//			cout << endl;
//			break;
//		}
//		case 2:
//		{
//			cout << endl;
//			con = 0;
//			int flag = 0;
//			for (int i = 0; i < 50; i++)
//			{
//				con = clientofbank[i].Print();
//				if (con != 0)
//				{
//					flag = 1;
//				}
//			}
//			if (flag == 0)
//			{
//				cout << "��� ��������!" << endl;
//			}
//			cout << endl;
//			break;
//		}
//		case 3:
//		{
//			cout << endl;
//			con = 0;
//			string nazvanie;
//			cout << "������� ����� ����� �������: " << endl;
//			cin.ignore();
//			getline(cin, nazvanie);
//			cout << endl;
//			for (int i = 0; i < 50; i++)
//			{
//				con = clientofbank[i].Search(nazvanie);
//				if (con == 1)
//				{
//					break;
//				}
//			}
//			if (con == 0)
//			{
//				cout << "������ �� ������!" << endl;
//			}
//			cout << endl;
//			break;
//		}
//	
//		default:
//			break;
//		}
//	} while (choise != 4);
//}
