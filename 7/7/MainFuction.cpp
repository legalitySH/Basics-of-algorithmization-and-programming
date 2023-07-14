//#include"HeaderFile.h"
//
//void PrintMenu() {
//	cout << "\n----------------------------------------------------------\n";
//	cout << "\nВыберите команду:" << endl;
//	cout << "1 - Добавление" << endl;
//	cout << "2 - Извлечение" << endl;
//	cout << "3 - Вывод стека" << endl;
//	cout << "4 - Очистка стека" << endl;
//	cout << "5 - Запись в файл" << endl;
//	cout << "6 - Чтения из файла" << endl;
//	cout << "7 - Выход из программы" << endl;
//	cout << "\n----------------------------------------------------------\n";
//}
//
//int main(int argc, char argv[]) {
//	{
//		SetConsoleCP(1251);
//		SetConsoleOutputCP(1251);
//	}
//	Stack* stack = new Stack;
//	int choice = 0;
//	stack->head = NULL;
//	int CountOfObjects = 0;
//
//	while (true)
//	{
//		PrintMenu();
//
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1: {
//			char AddingObject{};
//			cout << "Введите элемент: "; cin >> AddingObject;
//			push(AddingObject, stack);
//
//			break;
//		}
//
//		case 2: {
//			if (pop(stack)) {
//				cout << "Последний элемент стека успешно извлечён !" << endl;
//			}
//			else {
//				cout << "Стек пустой! Желаете добавить элемент? (1 - да, 2 - нет)" << endl;
//				int choice = 0;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1: {
//					char AddingObject{};
//					cout << "Введите элемент: "; cin >> AddingObject;
//					push(AddingObject, stack);
//
//					break;
//				}
//				case 2: {
//					continue;
//				}
//				default:
//					cout << "Введён неверный вариант ответа !" << endl;
//					break;
//				}
//			}
//
//			break;
//		}
//
//		case 3: {
//			if (output(stack)) {
//				cout << endl;
//			}
//			else {
//				cout << "Стек пустой! Желаете добавить элемент? (1 - да, 2 - нет)" << endl;
//				int choice = 0;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1: {
//					char AddingObject{};
//					cout << "Введите элемент: "; cin >> AddingObject;
//					push(AddingObject, stack);
//
//					break;
//				}
//				case 2: {
//					continue;
//				}
//				default:
//					cout << "Введён неверный вариант ответа !" << endl;
//					break;
//				}
//			}
//
//			break;
//		}
//
//		case 4: {
//			if (clear(stack)) {
//				cout << "Стек успешно очищен!" << endl;
//			}
//			else {
//				cout << "Стек уже является пустым!" << endl;
//			}
//
//			break;
//		}
//
//		case 5: {
//			writeToFile(stack);
//			cout << "Данные стека успешно записаны в файл!" << endl;
//			
//			break;
//		}
//
//		case 6: {
//			readFromFile(stack);
//			cout << "Данные считаны из файла в стек!" << endl;
//
//			break;
//		}
//
//		case 7: {
//			cout << "Bye bye !" << endl;
//			exit(0);
//			break;
//		}
//		default: cout << "Введён неправильный вариант!" << endl;
//		}
//	}
//}
//
