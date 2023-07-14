#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

enum eSexes {
	male = 1, female
}sexChoice;

struct dweller {
	string fio;
	struct birthday {
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	}birthdayDate = { 0,0,0 };
	string adress;
	string sex;

	void getSex() {
		cout << "Введите пол:(1 - мужской, 2 - женский)" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case male: {
			sex = "мужской";
			break;
		}
		case female: {
			sex = "женский";
			break;
		}
		default:
			getSex();
			break;
		}
	}
	void dateInput() {
		unsigned int _day = 0, _month = 0, _year = 0;
		cout << "Введите день рождения в формате ДД ММ ГГГГ" << endl;
		cin >> _day >> _month >> _year;
		if (validDate(_year, _month, _day)) {
			birthdayDate.day = _day;
			birthdayDate.month = _month;
			birthdayDate.year = _year;
		}
		else {
			dateInput();
		}
	}
	bool validDate(unsigned int _Year, unsigned int _Month, unsigned int _DayNo)
	{
		int days_in_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (_Year % 4 == 0)
			days_in_month[2] = 29;

		else if (_Month > 12)
			return false;

		else if (_DayNo > days_in_month[_Month])
			return false;
		else
			return true;
	}
	void addObject() {
		cin.ignore();
		cout << "Введите ФИО :" << endl;
		getline(cin, fio);
		dateInput();
		cin.ignore();
		cout << "Введите адрес :" << endl;
		getline(cin, adress);
		getSex();
	}
	void outputObjects() {
		if (this->fio != "") {
			cout << "-----------------------------------------------" << endl;
			cout << "ФИО:" << fio << endl;
			cout << "Дата рождения: " << birthdayDate.day << "." << birthdayDate.month << "." << birthdayDate.year << endl;
			cout << "Адрес проживания: " << adress << endl;
			cout << "Пол : " << sex << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}
	bool deleteObjects(string deleteFIO) {
		if (this->fio == deleteFIO) {
			fio = "";
			return true;
		}
		else return false;
	}
	bool searchObject(unsigned int year__) {
		if (this->birthdayDate.year == year__) {
			outputObjects();
			return true;
		}
		else
		{
			return false;
		}
	}
}object;

int main() {
	int counter = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	dweller population[16];
	int choice;
	while (true) {
		cout << "\nВыберите подходящий вариант : " << endl;
		cout << "1 - Ввод" << endl;
		cout << "2 - Вывод на экран" << endl;
		cout << "3 - Удаление" << endl;
		cout << "4 - Поиск" << endl;
		cout << "5 - Выход из программы" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1: {
			if (counter < 16) {
				population[counter].addObject();
				counter++;
			}
			else {
				cout << "No memory!";
				exit(1);
			}
			break;
		}
		case 2: {
			for (int i = 0; i < 16; i++)
			{
				population[i].outputObjects();
			}
			break;
		}
		case 3: {
			string deleteFio;
			cin.ignore();
			cout << "Введите ФИО удаляемого гражданина :";
			getline(cin, deleteFio);
			bool flag = false;
			for (int i = 0; i < 16; i++)
			{
				flag = population[i].deleteObjects(deleteFio);
				if (flag) break;
			}
			if (!flag) {
				cout << "Не удалось удалить гражданина с таким ФИО" << endl;
			}
			break;
		}
		case 4: {
			cout << "Введите год рождения:" << endl;
			unsigned int year_;
			cin >> year_;
			bool flag = false;
			for (int i = 0; i < 16; i++)
			{
				flag = population[i].searchObject(year_);
				if (flag) break;
			}
			if (!flag) {
				cout << "Не удалось найти гражданина с таким годом рождения" << endl;
			}


			break;
		}
		case 5: {
			return EXIT_SUCCESS;
			break;
		}
		default:
			break;
		}
	}
}