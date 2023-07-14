//#include<iostream>
//#include <string>
//#include<fstream>
//
//using namespace std;
//
//union client_info {
//
//	struct custom {
//		string passportNumber;
//		string comeDate;
//		string backDate;
//		string phoneNumber;
//		string type;
//	};
//};
//
//struct clients {
//	string passportNumber;
//	string comeDate;
//	string backDate;
//	string phoneNumber;
//	string type;
//
//	void ClientAdding(client_info::custom temp_client) {
//		passportNumber = temp_client.passportNumber;
//		comeDate = temp_client.comeDate;
//		backDate = temp_client.backDate;
//		phoneNumber = temp_client.phoneNumber;
//		type = temp_client.type;
//	}
//
//	void ClientsInput() {
//		
//		if (this->passportNumber != "") {
//			cout << "Паспортные данные: " << passportNumber << endl;
//			cout << "Дата приезда: " << comeDate << endl;
//			cout << "Дата уезда: " << backDate << endl;
//			cout << "Телефонный номер: " << phoneNumber << endl;
//			cout << "Тип размещения: " << type << endl;
//		}
//	}
//
//	bool ClientSearch(string pass) {
//		bool valid = false;
//		if (this->passportNumber == pass) {
//			ClientsInput();
//			valid = true;
//		}
//		return valid;
//	}
//
//};
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	int choice;
//	client_info::custom client;
//	clients cust[155] = {};
//	int counter = 0;
//
//	while (true)
//	{
//		cout << "\n\t\tВыберите вариант :" << endl;
//		cout << "1 - Добавление клиента" << endl;
//		cout << "2 - Вывод на экран" << endl;
//		cout << "3 - Поиск клиента" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1: {
//			cin.ignore();
//			cout << "Введите паспортные данные клиента" << endl;
//			getline(cin,client.passportNumber);
//			cout << "Введите дату приезда в формате ДД.ММ.ГГГГ" << endl;
//			getline(cin, client.comeDate);
//			cout << "Введите дату уезда в формате ДД.ММ.ГГГГ" << endl;
//			getline(cin, client.backDate);
//			cout << "Введите номер телефона в формате(+375...)" << endl;
//			getline(cin, client.phoneNumber);
//			cout << "Введите тип заселения (люкс - lux, одноместный - single, двухместный - double, трехместный - triple, апартаменты - apart)" << endl;
//			getline(cin, client.type);
//			cust[counter].ClientAdding(client);
//			counter++;
//			break;
//		}
//		case 2: {
//			for (int i = 0; i < 155; i++)
//			{
//				cust[i].ClientsInput();
//			}
//			break;
//		}
//		case 3: {
//			string pass;
//			bool valid = false;
//			cout << "Введите паспортные данные клиента :" << endl;
//			cin.ignore();
//			getline(cin, pass);
//			for (int i = 0; i < 155; i++)
//			{
//				valid = cust[i].ClientSearch(pass);
//				if (valid) {
//					break;
//				}
//			}
//			if (!valid) {
//				cout << "Такого клиента не найдено!" << endl;
//			}
//			break;
//		}
//		default:
//			break;
//		}
//	}
//}