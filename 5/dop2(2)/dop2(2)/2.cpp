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
//	cout << "������� ����� ������:" << endl;
//	cin >> object.NumberOfTrain;
//	NumberOfTrain = object.NumberOfTrain;
//	cout << "������� ����� ���������� ������:" << endl;
//	cin.ignore();
//	getline(cin, object.Destination);
//	Destination = object.Destination;
//	cout << "������� ��� ���������� ������(����� ������� ���� �� ���������):" << endl;
//	getline(cin, object.TravelDays);
//	TravelDays = object.TravelDays;
//	cout << "������� ����� �������� ������ � ������� (HH:MM):" << endl;
//	getline(cin, object.ArrivalTime);
//	ArrivalTime = object.ArrivalTime;
//	cout << "������� ����� ����������� ������ � ������� (HH:MM):" << endl;
//	getline(cin, object.DepartureTime);
//	DepartureTime = object.DepartureTime;
//}
//bool TrainList::OutPutObjects() {
//	if (this->Destination != "") {
//		cout << "����� ������: " << NumberOfTrain << endl;
//		cout << "����� ����������: " << Destination << endl;
//		cout << "��� ����������: " << TravelDays << endl;
//		cout << "����� ��������: " << ArrivalTime << endl;
//		cout << "����� �����������: " << DepartureTime << endl;
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
//	cout << "\t\t�������� ������ ������� :" << endl;
//	cout << "1 - ����" << endl;
//	cout << "2 - �����" << endl;
//	cout << "3 - �����" << endl;
//	cout << "4 - ����� �� ���������" << endl;
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
//		cout << "������� ����� ������ , � ������� �� ������ �������� ����������:" << endl;
//		cin >> srchNumb;
//		for (int i = 0; i < sizeof(RailwaySchdule)/sizeof(RailwaySchdule[0]); i++)
//		{
//			flag = RailwaySchdule[i].SearchObject(srchNumb);
//			if (flag) break;
//		}
//		if (!flag) {
//			cout << "������ � ����� ������� � ���� ���!" << endl;
//		}
//		break;
//	}
//	case 4: {
//		return EXIT_SUCCESS;
//	}
//	default:
//		cout << "����� �������� �������! " << endl;
//		break;
//	}
//	}
//}