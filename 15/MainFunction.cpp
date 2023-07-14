//#include"HashTwin.h"
//#include"HashTwinFunctions.h"
//
//int menu() {
//	cout << "\n1 - Добавить университет в хеш-таблицу\n";
//	cout << "2 - Вывести все университеты\n";
//	cout << "3 - Поиск по году создания(ключу)\n";
//	cout << "4 - Удаления университета/университета по ключу\n";
//	cout << "5 - Выход из программы\n";
//	int choice;
//	cin >> choice;
//	return choice;
//}
//UniversityInfo AddElement() {
//	UniversityInfo University;
//	string uName, cName; int crYear;
//	cout << "Введите название университета: ";
//	cin.ignore();
//	getline(cin, University.universityName);
//	cout << "Введите имя ректора: ";
//	getline(cin, University.chefName);
//	cout << "Введите год создания: ";
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
//			cout << "Введите год создания для поиска: "; cin >> search_key;
//			h.search(search_key);
//			break;
//		}
//		case 4: {
//			int remove_key;
//			cout << "Введите год создания для удаления : "; cin >> remove_key;
//			h.remove(remove_key);
//			break;
//		}
//		case 5: {
//			cout << "\nBye bye!";
//			exit(EXIT_SUCCESS);
//			break;
//		}
//		default:
//			cout << "Введён неверный вариант ответа!";
//			break;
//		}
//	}
//}