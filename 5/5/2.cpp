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
//			cout << "���������� ������: " << passportNumber << endl;
//			cout << "���� �������: " << comeDate << endl;
//			cout << "���� �����: " << backDate << endl;
//			cout << "���������� �����: " << phoneNumber << endl;
//			cout << "��� ����������: " << type << endl;
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
//		cout << "\n\t\t�������� ������� :" << endl;
//		cout << "1 - ���������� �������" << endl;
//		cout << "2 - ����� �� �����" << endl;
//		cout << "3 - ����� �������" << endl;
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1: {
//			cin.ignore();
//			cout << "������� ���������� ������ �������" << endl;
//			getline(cin,client.passportNumber);
//			cout << "������� ���� ������� � ������� ��.��.����" << endl;
//			getline(cin, client.comeDate);
//			cout << "������� ���� ����� � ������� ��.��.����" << endl;
//			getline(cin, client.backDate);
//			cout << "������� ����� �������� � �������(+375...)" << endl;
//			getline(cin, client.phoneNumber);
//			cout << "������� ��� ��������� (���� - lux, ����������� - single, ����������� - double, ����������� - triple, ����������� - apart)" << endl;
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
//			cout << "������� ���������� ������ ������� :" << endl;
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
//				cout << "������ ������� �� �������!" << endl;
//			}
//			break;
//		}
//		default:
//			break;
//		}
//	}
//}