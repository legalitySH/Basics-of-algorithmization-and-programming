//#include"HeaderFile.h"
//
//void PrintMenu() {
//	cout << "\n----------------------------------------------------------\n";
//	cout << "\n�������� �������:" << endl;
//	cout << "1 - ����������" << endl;
//	cout << "2 - ����������" << endl;
//	cout << "3 - ����� �����" << endl;
//	cout << "4 - ������� �����" << endl;
//	cout << "5 - ������ � ����" << endl;
//	cout << "6 - ������ �� �����" << endl;
//	cout << "7 - ����� �� ���������" << endl;
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
//			cout << "������� �������: "; cin >> AddingObject;
//			push(AddingObject, stack);
//
//			break;
//		}
//
//		case 2: {
//			if (pop(stack)) {
//				cout << "��������� ������� ����� ������� �������� !" << endl;
//			}
//			else {
//				cout << "���� ������! ������� �������� �������? (1 - ��, 2 - ���)" << endl;
//				int choice = 0;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1: {
//					char AddingObject{};
//					cout << "������� �������: "; cin >> AddingObject;
//					push(AddingObject, stack);
//
//					break;
//				}
//				case 2: {
//					continue;
//				}
//				default:
//					cout << "����� �������� ������� ������ !" << endl;
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
//				cout << "���� ������! ������� �������� �������? (1 - ��, 2 - ���)" << endl;
//				int choice = 0;
//				cin >> choice;
//				switch (choice)
//				{
//				case 1: {
//					char AddingObject{};
//					cout << "������� �������: "; cin >> AddingObject;
//					push(AddingObject, stack);
//
//					break;
//				}
//				case 2: {
//					continue;
//				}
//				default:
//					cout << "����� �������� ������� ������ !" << endl;
//					break;
//				}
//			}
//
//			break;
//		}
//
//		case 4: {
//			if (clear(stack)) {
//				cout << "���� ������� ������!" << endl;
//			}
//			else {
//				cout << "���� ��� �������� ������!" << endl;
//			}
//
//			break;
//		}
//
//		case 5: {
//			writeToFile(stack);
//			cout << "������ ����� ������� �������� � ����!" << endl;
//			
//			break;
//		}
//
//		case 6: {
//			readFromFile(stack);
//			cout << "������ ������� �� ����� � ����!" << endl;
//
//			break;
//		}
//
//		case 7: {
//			cout << "Bye bye !" << endl;
//			exit(0);
//			break;
//		}
//		default: cout << "����� ������������ �������!" << endl;
//		}
//	}
//}
//
