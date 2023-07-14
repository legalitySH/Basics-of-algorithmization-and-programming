#include<iostream>
#include<string>

using namespace std;
enum eTypeOfRoom {
	emp = 0,
	lux,singleRoom, doubleRoom, tripleRoom, appartamentsRoom
};

struct hostel {
	string passportNumber;
	struct comeDate {
		unsigned int comeDay : 5;
		unsigned int comeMonths : 4;
		unsigned int comeYear : 11;
	}comeDate = { 0,0,0 };
	struct backDate {
		unsigned int day : 5;
		unsigned int month : 4;
		unsigned int year : 11;
	}backDate = { 0,0,0 };
	string TelephoneNumber;
	eTypeOfRoom TypeOfRoom;

	int ComeDate_valid() {
		unsigned int day = 0, month = 0, year = 0;
		cout << "Введите дату приезда:" << endl;
		cin >> day >> month >> year;
		if (day < 32 && day>0 && month > 0 && month < 13 && year < 2049 && year > 0) {
			comeDate.comeDay = day;
			comeDate.comeMonths = month;
			comeDate.comeYear = year;
		}
		else {
			return 0;
		}
	}

	int BackDate_valid() {
		unsigned int day = 0, month = 0, year = 0;
		cout << "Введите дату уезда:" << endl;
		cin >> day >> month >> year;
		if (day < 32 && day>0 && month > 0 && month < 13 && year < 2049 && year > 0) {
			backDate.day = day;
			backDate.month = month;
			backDate.year = year;
		}
		else {
			return 0;
		}
	}

	void ClientAdding() {
		cin.ignore();
		cout << "Введите паспортные данные клиента : " << endl;
		getline(cin, passportNumber);
		//Функция ввода даты и проверка введенных значений на валидность
		if (ComeDate_valid() == 0) {
			cout << "Введите верную дату! " << endl;
			ComeDate_valid();
		}
		if (BackDate_valid() == 0) {
			cout << "Введите верную дату! " << endl;
			ComeDate_valid();
		}
		cout << "Введите номер телефона:" << endl;
		cin.ignore();
		getline(cin, TelephoneNumber);
		cout << "Введите тип размещения (lux = люкс, singleRoom - одноместный, doubleRoom - двухместный, tripleRoom - трехместный, appartamentsRoom - апартаменты):" << endl;
		string type;
		getline(cin, type);
		if (type == "lux") {
			TypeOfRoom = lux;
		}
		else if (type == "singleRoom") {
			TypeOfRoom = singleRoom;
		}
		else if (type == "doubleRoom") {
			TypeOfRoom = doubleRoom;
		}
		else if (type == "tripleRoom") {
			TypeOfRoom = tripleRoom;
		}
		else if (type == "appartamentsRoom") {
			TypeOfRoom = appartamentsRoom;
		}

	}

	void ClientsInput() {
		if (comeDate.comeDay != 0) {
			cout << "\nПаспортные данные: " << passportNumber << endl;
			cout << "Дата приезда: " << comeDate.comeDay << "." << comeDate.comeMonths << "." << comeDate.comeYear << endl;
			cout << "Дата уезда: " << backDate.day << "." << backDate.month << "." << backDate.year << endl;
			cout << "Телефонный номер: " << TelephoneNumber << endl;
			cout << "Тип номера(1-люкс, 2-одноместный, 3-двухместный, 4-трехместный, 5-апартаменты) :" << TypeOfRoom;
		}
	}

	bool ClientDeleting(string deleteValue) {
		bool flag = false;
			if (this->passportNumber == deleteValue)
			{
				passportNumber = "";
				comeDate.comeDay = 0;
				comeDate.comeMonths = 0;
				comeDate.comeYear = 0;
				backDate.day = 0;
				backDate.month = 0;
				TypeOfRoom = emp;
				flag = true;
			}
			return flag;
		}

	bool ClientSearch(unsigned int day, unsigned int month , unsigned int year) {
		bool flag = false;
		if (this->comeDate.comeDay == day && this->comeDate.comeMonths == month && this->comeDate.comeYear == year) {
			ClientsInput();
			flag = true;
		}
		return flag;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	hostel customers[155];
	int choice;
	int counter = 0;
	while (true)
	{
		cout << "\n\t\t\tВыберите подходящий вариант :" << endl;
		cout << "1 - Ввод клиента гостиницы" << endl;
		cout << "2 - Вывод всех клиентов" << endl;
		cout << "3 - Удалить клиента" << endl;
		cout << "4 - Поиск клиента" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			customers[counter].ClientAdding();
			counter++;
			break;
		}
		case 2: {
			for (int i = 0; i < 155; i++)
			{
				customers[i].ClientsInput();
			}
			break;
		}
		case 3: {
			string deleteValue;
			cout << "Введите паспортные данные клиента,которого хотите удалить" << endl;
			cin.ignore();
			bool valid = false;
			getline(cin, deleteValue);
			for (int i = 0; i < 155; i++)
			{
				valid = customers[i].ClientDeleting(deleteValue);
				if (valid) {
					cout << "Успешно!" << endl;
					break;
				}
			}
			if (!valid) {
				cout << "Введены неверные данные!" << endl;
			}
			break;
		}
		case 4: {
			unsigned int day = 0, month = 0, year = 0;
			cout << "Введите дату приезда:" << endl;
			cin >> day >> month >> year;
			bool valid = false;
			for (int i = 0; i < 155; i++)
			{
				valid = customers[i].ClientSearch(day, month, year);
			}
			if (!valid) {
				cout << "Клиент не найден!" << endl;
			}
			break;
		}
		default: cout << "Введен неверный вариант,попробуйте снова" << endl;
			break;
		}

	}

}