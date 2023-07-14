#include<iostream>
#include <string>
#include <stdio.h>
#include<Windows.h>
#include<fstream>

using namespace std;
void print() {
	cout << "\n������� !\n";
}
void error() {
	cout << "\n�� ������� !\n";
}
struct HumanResourcesDepartment
{
	string fio;
	string education;
	string specialty;
	string subdivision;
	string position;
	string salary;
	string inviteDate;
	
	void add() {
		cin.ignore();
		cout << "������� ��� ��������� :"; getline(cin,fio);
		cout << "������� ����������� ���������: "; getline(cin, education);
		cout << "������� ������������� ���������: "; getline(cin, specialty);
		cout << "������� ������������� ���������: "; getline(cin, subdivision);
		cout << "������� ��������� ���������: "; getline(cin, position);
		cout << "������� ����� ���������($): "; getline(cin, salary);
		cout << "������� ���� ����������� �� �����������: "; getline(cin, inviteDate);
		print();
		
	}
	int del(string del_fio) {
		int counter = 0;
			if (this->fio == del_fio)
			{
				fio = "";
				education = "";
				specialty = "";
				subdivision = "";
				position = "";
				salary = "";
				inviteDate = "";
				print();
				counter++;
			}
			return counter;
	}
	void inpWorkers() {
		if (fio != "")
			cout << "���: " << fio << "\n�����������: " << education << "\n�������������: " << specialty << "\n�������������: " << subdivision << "\n���������: " << position << "\n�����: " << salary << "\n���� ����������� �� �����������: " << inviteDate << endl;

	}
	int search(string searchPosition,int counter) {
		if (this->position == searchPosition) {
			inpWorkers();
			counter++;
		}
		return counter;
	}
	void write() {
		cin.ignore();
		cout << "������� ��� ��������� :"; getline(cin, fio);
		cout << "������� ����������� ���������: "; getline(cin, education);
		cout << "������� ������������� ���������: "; getline(cin, specialty);
		cout << "������� ������������� ���������: "; getline(cin, subdivision);
		cout << "������� ��������� ���������: "; getline(cin, position);
		cout << "������� ����� ���������($): "; getline(cin, salary);
		cout << "������� ���� ����������� �� �����������: "; getline(cin, inviteDate);
		ofstream fout("workers.txt",ios::app);
		fout << fio << endl;
		fout << education << endl;
		fout << specialty << endl;
		fout << subdivision << endl;
		fout << position << endl;
		fout << salary << endl;
		fout << inviteDate << endl;
		fout << endl;
		fout.close();
		del(fio);
	}
	void read(int i,int g) {
		string tmp;
		ifstream fin("workers.txt");
		
		for (g; g < i+1; g++)
		{
			getline(fin, fio);
			getline(fin, education);
			getline(fin, specialty);
			getline(fin, subdivision);
			getline(fin, position);
			getline(fin, salary);
			getline(fin, inviteDate);
			getline(fin, tmp);
		}
		fin.close();
	}
};
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HumanResourcesDepartment worker[255];
	setlocale(LC_ALL, "rus");
	while (true) {
		cout << "\t\t\t�������� ������� :" << endl;
		cout << "1 - �������� ����" << endl;
		cout << "2 - ������� ����" << endl;
		cout << "3 - ����� ���� ������������ ������" << endl;
		cout << "4 - ����� �� ���������" << endl;
		cout << "5 - ������ � ����" << endl;
		cout << "6 - ������ �� �����" << endl;
		cout << "7 - ����� �� ���������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			int counter = 0;
			worker[counter].add();
			counter++;
			break;
		}
		case 2: {
			cout << "������� ��� ��������� , �������� �� ������ ������� :";
			cin.ignore();
			string del_fio;
			getline(cin, del_fio);
			int flag = 0;
			for (int i = 0; i < 255; i++)
			{
				flag = worker[i].del(del_fio);
				if (flag == 1) {
					break;
				}
			}
			if (flag == 0) {
				error();
			}
			break;
		}
		case 3: {
			for (int i = 0; i < 255; i++)
			{
				worker[i].inpWorkers();
			}
			break;
		}
		case 4: {
			int flag = 0;
			cout << "������� �������� ���������: ";
			cin.ignore();
			string searchPosition;
			getline(cin, searchPosition);
			for (int i = 0; i < 255; i++)
			{
				flag = worker[i].search(searchPosition, flag);
			}
			if (flag == 0) {
				error();
			}
			break;
		}
		case 5: {
			cout << "������� ���������� ����������, ������� �� ������ ��������= ";
			int count = 0;
			cin >> count;
			for (int i = 0; i <count; i++)
			{
				worker[254].write();
			}
			break;
		}
		case 6: {
			cout << "������� �� ������ ��������� � ����� ������ ? ������� �����...";
			int n;
			cin >> n;
			int i = 150;
			int f = n + i;
			int g = i;
			string tmp;
			int counter = 0;
			ifstream fin("workers.txt");
			while (!fin.eof()) {
				getline(fin, worker[i].fio);
				getline(fin, worker[i].education);
				getline(fin, worker[i].specialty);
				getline(fin, worker[i].subdivision);
				getline(fin, worker[i].position);
				getline(fin, worker[i].salary);
				getline(fin, worker[i].inviteDate);
				getline(fin, tmp);
				counter++;
			}
			fin.close();
			if (n>counter-1)
			{
				error();
			}
			else
			{
				for (int i = 150; i < f; i++)
				{
					worker[i].read(i, g);
				}
				i = f;
				print();
			}
			break;
		}
		default:
			cout << "��������� ����";
			return EXIT_FAILURE;
			break;
		}

	}
}
