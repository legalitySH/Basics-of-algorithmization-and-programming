#include<iostream>
#include <string>
#include <stdio.h>
#include<Windows.h>
#include<fstream>

using namespace std;
void print() {
	cout << "\nУспешно !\n";
}
void error() {
	cout << "\nНе успешно !\n";
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
		cout << "Введите ФИО работника :"; getline(cin,fio);
		cout << "Введите образование работника: "; getline(cin, education);
		cout << "Введите специальность работника: "; getline(cin, specialty);
		cout << "Введите подразделение работника: "; getline(cin, subdivision);
		cout << "Введите должность работника: "; getline(cin, position);
		cout << "Введите оклад работника($): "; getline(cin, salary);
		cout << "Введите дату поступления на предприятия: "; getline(cin, inviteDate);
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
			cout << "ФИО: " << fio << "\nОбразование: " << education << "\nСпециальность: " << specialty << "\nПодразделение: " << subdivision << "\nДолжность: " << position << "\nОклад: " << salary << "\nДата поступления на предприятия: " << inviteDate << endl;

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
		cout << "Введите ФИО работника :"; getline(cin, fio);
		cout << "Введите образование работника: "; getline(cin, education);
		cout << "Введите специальность работника: "; getline(cin, specialty);
		cout << "Введите подразделение работника: "; getline(cin, subdivision);
		cout << "Введите должность работника: "; getline(cin, position);
		cout << "Введите оклад работника($): "; getline(cin, salary);
		cout << "Введите дату поступления на предприятия: "; getline(cin, inviteDate);
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
		cout << "\t\t\tВыберите вариант :" << endl;
		cout << "1 - Добавить кадр" << endl;
		cout << "2 - Удалить кадр" << endl;
		cout << "3 - Вывод всех существующих кадров" << endl;
		cout << "4 - Поиск по должности" << endl;
		cout << "5 - Запись в файл" << endl;
		cout << "6 - Чтение из файла" << endl;
		cout << "7 - Выход из программы" << endl;
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
			cout << "Введите ФИО работника , которого вы хотите удалить :";
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
			cout << "Введите дожность работника: ";
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
			cout << "Введите количество работников, которых вы хотите записать= ";
			int count = 0;
			cin >> count;
			for (int i = 0; i <count; i++)
			{
				worker[254].write();
			}
			break;
		}
		case 6: {
			cout << "Сколько вы хотите прочитать с файла кадров ? Введите число...";
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
			cout << "Ошибочный ввод";
			return EXIT_FAILURE;
			break;
		}

	}
}
