//#include"HashTwin.h"
//#include"HashTwinFunctions.h"
//
//int menu() {
//	cout << "\n1 - �������� ����������� � ���-�������\n";
//	cout << "2 - ������� ��� ������������\n";
//	cout << "3 - ����� �� ���� ��������(�����)\n";
//	cout << "4 - �������� ������������/������������ �� �����\n";
//	cout << "5 - ����� �� ���������\n";
//	int choice;
//	cin >> choice;
//	return choice;
//}
//UniversityInfo AddElement() {
//	UniversityInfo University;
//	string uName, cName; int crYear;
//	cout << "������� �������� ������������: ";
//	cin.ignore();
//	getline(cin, University.universityName);
//	cout << "������� ��� �������: ";
//	getline(cin, University.chefName);
//	cout << "������� ��� ��������: ";
//	cin >> University.createYear;
//	return University;
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	HashTable h(32);
//	while (true) {
//		switch (menu())
//		{
//		case 1: {
//			UniversityInfo AddingUniversity = AddElement();
//			h.insert(AddingUniversity.createYear, AddingUniversity);
//			break;
//		}
//		case 2: {
//			h.output();
//			break;
//		}
//		case 3: {
//			int search_key;
//			cout << "������� ��� �������� ��� ������: "; cin >> search_key;
//			h.search(search_key);
//			break;
//		}
//		case 4: {
//			int remove_key;
//			cout << "������� ��� �������� ��� �������� : "; cin >> remove_key;
//			h.remove(remove_key);
//			break;
//		}
//		case 5: {
//			cout << "\nBye bye!";
//			exit(EXIT_SUCCESS);
//			break;
//		}
//		default:
//			cout << "����� �������� ������� ������!";
//			break;
//		}
//	}
//}