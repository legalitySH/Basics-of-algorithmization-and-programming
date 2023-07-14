#include "stdafx.h"

struct Person
{
	string name;
	int age;
	Person* next;

};

bool comparePerson(void* p1, void* p2) {
	Person* person1 = static_cast<Person*>(p1);
	Person* person2 = static_cast<Person*>(p2);
	return (person1->name == person2->name) && (person1->age == person2->age);
}

void PrintPerson(void* data)
{
	Person* p = (Person*)data;
	std::cout << "Name: " << p->name << ", Age: " << p->age << std::endl;
}

int main(int argc, char* argv[])
{
	setlocale(0, "");
	Object List = List.Create();
	int choice;
	do {
		cout << "����:" << endl;
		cout << "1. �������� ������� � ������ ������" << endl;
		cout << "2. �������� ������� � ����� ������" << endl;
		cout << "3. ����� ������� � ������" << endl;
		cout << "4. ������� ������� �� ������" << endl;
		cout << "5. ������� ������ �� �����" << endl;
		cout << "6. ��������� ���������� ��������� � ������" << endl;
		cout << "7. ������� ������" << endl;
		cout << "0. �����" << endl;
		cout << "�������� ��������: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			string name;
			int age = 0;
			cin.ignore();
			cout << "������� ���: ";
			getline(cin, name);
			cout << "������� �������: ";
			cin >> age;
			Person* p = new Person{ name, age };
			List.Insert(p);
			break;
		}
		case 2: {
			string name; int age = 0;
			cin.ignore();
			cout << "������� ���:"; getline(cin, name);
			cout << "������� �������:"; cin >> age;
			Person* p = new Person{ name, age };
			List.InsertEnd(p);
			break;
		}
		case 3: {
				string name;
				int age = 0;
				cin.ignore();
				cout << "������� ���:";
				getline(cin, name);
				cout << "������� �������:";
				cin >> age;
				Person* p = new Person{ name, age };
				Element* searchedResult = List.Search(p, comparePerson);
				if (searchedResult != NULL) {
					Person* sperson = static_cast<Person*>(searchedResult->Data);
					cout << endl;
					cout << "������ �������: " << sperson->name << endl;
				}
				else {
					cout << "������� �� ������" << endl;
				}
				delete p;
			break;
		}
		case 4: {
			string name;
			int age = 0;
			cin.ignore();
			cout << "������� ���:";
			getline(cin, name);
			cout << "������� �������:";
			cin >> age;
			Person* p = new Person{ name, age };
			Element* searchedResult = List.Search(p, comparePerson);
			if (searchedResult != NULL) {
				List.Delete(searchedResult);
				cout << "������� ������� �����!" << endl;
			}
			else {
				cout << "������� �� ������!" << endl;
 			}
			break;
		}
		case 5: {
			if (List.GetFirst() == NULL) {
				cout << "������ ������" << endl;
			}
			else {
				cout << "������:" << endl;
				List.PrintList(PrintPerson);
			}
			break;
		}
		case 6: {
			cout << "������ ������� �� " << List.CountList() << " ���������" << endl;
			break;
		}
		case 7: {
			List.DeleteList(List);
			cout << "������ �����!" << endl;
			break;
		}
		case 0: {
			exit(1);
			break;
		}
		default:
			cout << "������: �������� �����. ���������� ��� ���." << endl;
			break;
		}
	} while (choice != 0);



	return 0;
}
