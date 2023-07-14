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
		cout << "Меню:" << endl;
		cout << "1. Добавить элемент в начало списка" << endl;
		cout << "2. Добавить элемент в конец списка" << endl;
		cout << "3. Найти элемент в списке" << endl;
		cout << "4. Удалить элемент из списка" << endl;
		cout << "5. Вывести список на экран" << endl;
		cout << "6. Посчитать количество элементов в списке" << endl;
		cout << "7. Удалить список" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;
		switch (choice) {
		case 1: {
			string name;
			int age = 0;
			cin.ignore();
			cout << "Введите имя: ";
			getline(cin, name);
			cout << "Введите возраст: ";
			cin >> age;
			Person* p = new Person{ name, age };
			List.Insert(p);
			break;
		}
		case 2: {
			string name; int age = 0;
			cin.ignore();
			cout << "Введите имя:"; getline(cin, name);
			cout << "Введите возраст:"; cin >> age;
			Person* p = new Person{ name, age };
			List.InsertEnd(p);
			break;
		}
		case 3: {
				string name;
				int age = 0;
				cin.ignore();
				cout << "Введите имя:";
				getline(cin, name);
				cout << "Введите возраст:";
				cin >> age;
				Person* p = new Person{ name, age };
				Element* searchedResult = List.Search(p, comparePerson);
				if (searchedResult != NULL) {
					Person* sperson = static_cast<Person*>(searchedResult->Data);
					cout << endl;
					cout << "Найден элемент: " << sperson->name << endl;
				}
				else {
					cout << "Элемент не найден" << endl;
				}
				delete p;
			break;
		}
		case 4: {
			string name;
			int age = 0;
			cin.ignore();
			cout << "Введите имя:";
			getline(cin, name);
			cout << "Введите возраст:";
			cin >> age;
			Person* p = new Person{ name, age };
			Element* searchedResult = List.Search(p, comparePerson);
			if (searchedResult != NULL) {
				List.Delete(searchedResult);
				cout << "Элемент успешно удалён!" << endl;
			}
			else {
				cout << "Элемент не найден!" << endl;
 			}
			break;
		}
		case 5: {
			if (List.GetFirst() == NULL) {
				cout << "Список пустой" << endl;
			}
			else {
				cout << "Список:" << endl;
				List.PrintList(PrintPerson);
			}
			break;
		}
		case 6: {
			cout << "Список состоит из " << List.CountList() << " элементов" << endl;
			break;
		}
		case 7: {
			List.DeleteList(List);
			cout << "Список удалён!" << endl;
			break;
		}
		case 0: {
			exit(1);
			break;
		}
		default:
			cout << "Ошибка: неверный выбор. Попробуйте ещё раз." << endl;
			break;
		}
	} while (choice != 0);



	return 0;
}
