//#include<iostream>
//#include<string>
//#include<Windows.h>
//
//using namespace std;
//
//union railwayStation {
//	struct TrainInfo {
//		unsigned int NumberOfTrain;
//		string Destination;
//		string TravelDays;
//		string ArrivalTime;
//		string DepartureTime;
//	};
//};
//
//struct TrainList {
//	unsigned int NumberOfTrain;
//	string Destination;
//	string TravelDays;
//	string ArrivalTime;
//	string DepartureTime;
//	void AddObject(railwayStation::TrainInfo object);
//	bool OutPutObjects();
//	bool SearchObject(int SearchNumber);
//};
//
//void TrainList::AddObject(railwayStation::TrainInfo object) {
//	cout << "Введите номер поезда:" << endl;
//	cin >> object.NumberOfTrain;
//	NumberOfTrain = object.NumberOfTrain;
//	cout << "Введите пункт назначения поезда:" << endl;
//	cin.ignore();
//	getline(cin, object.Destination);
//	Destination = object.Destination;
//	cout << "Введите дни следования поезда(через запятую если их несколько):" << endl;
//	getline(cin, object.TravelDays);
//	TravelDays = object.TravelDays;
//	cout << "Введите время прибытия поезда в формате (HH:MM):" << endl;
//	getline(cin, object.ArrivalTime);
//	ArrivalTime = object.ArrivalTime;
//	cout << "Введите время отправления поезда в формате (HH:MM):" << endl;
//	getline(cin, object.DepartureTime);
//	DepartureTime = object.DepartureTime;
//}
//bool TrainList::OutPutObjects() {
//	if (this->Destination != "") {
//		cout << "Номер поезда: " << NumberOfTrain << endl;
//		cout << "Пункт назначения: " << Destination << endl;
//		cout << "Дни следования: " << TravelDays << endl;
//		cout << "Время прибытия: " << ArrivalTime << endl;
//		cout << "Время отправления: " << DepartureTime << endl;
//		cout << "----------------------------------------------" << endl;
//		return true;
//	}
//	return false;
//}
//bool TrainList::SearchObject(int SearchNumber) {
//	if (this->NumberOfTrain == SearchNumber) {
//		OutPutObjects();
//		return true;
//	}
//	return false;
//}
//void Menu() {
//	cout << "\t\tВыберите верный вариант :" << endl;
//	cout << "1 - Ввод" << endl;
//	cout << "2 - Вывод" << endl;
//	cout << "3 - Поиск" << endl;
//	cout << "4 - Выход из программы" << endl;
//}
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int choice = 0, counter = 0;
//	railwayStation::TrainInfo TempObject;
//	TrainList RailwaySchdule[16]{};
//	while (true) {
//	Menu();
//	cin >> choice;
//	switch (choice)
//	{
//	case 1: {
//		RailwaySchdule[counter].AddObject(TempObject);
//		counter++;
//		break;
//	}
//	case 2: {
//		bool flag = false;
//		for (int i = 0; i <sizeof(RailwaySchdule)/sizeof(RailwaySchdule[0]); i++)
//		{
//			flag = RailwaySchdule[i].OutPutObjects();
//		}
//		break;
//	}
//	case 3: {
//		bool flag = false;
//		int srchNumb=0;
//		cout << "Введите номер поезда , о котором вы хотите получить информацию:" << endl;
//		cin >> srchNumb;
//		for (int i = 0; i < sizeof(RailwaySchdule)/sizeof(RailwaySchdule[0]); i++)
//		{
//			flag = RailwaySchdule[i].SearchObject(srchNumb);
//			if (flag) break;
//		}
//		if (!flag) {
//			cout << "Поезда с таким номером в базе нет!" << endl;
//		}
//		break;
//	}
//	case 4: {
//		return EXIT_SUCCESS;
//	}
//	default:
//		cout << "Введён неверный вариант! " << endl;
//		break;
//	}
//	}
//}