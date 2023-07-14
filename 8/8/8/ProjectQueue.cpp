#include"stdafx.h"

void menu() {
	cout << "------------------------------------------------------------" << endl;
	cout << "1 - Добавить элемент в очередь" << endl;
	cout << "2 - Удалить элемент очереди" << endl;
	cout << "3 - Вывод всей очереди" << endl;
	cout << "4 - Получить первый элемент очереди" << endl;
	cout << "5 - Очистка очереди" << endl;
	cout << "6 - Проверить имеется ли в очереде эталонный символ..." << endl;
	cout << "------------------------------------------------------------" << endl;

}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int SizeOfQueue = 0;
	cout << "Введите максимальный размер очереди = "; cin >> SizeOfQueue;
	Queue q(SizeOfQueue);
	int choice = 0;
	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1: {
			static char AddingObject;
			cout << "Введите символ, который хотите добавить = "; cin >> AddingObject;
			q.EnQueue(AddingObject);
			q.Show();
			break;
		}
		case 2: {
			q.DeQueue();
			q.Show();
			break;
		}
		case 3: {
			q.Show();
			break;
		}
		case 4: {
			q.Peek();
		}
		case 5: {
			q.clear();
			break;
		}
		case 6: {
			static char etalon;
			cout << "Введите эталонный символ = "; cin >> etalon;
			q.LabFunction(etalon);
		}
		default:
			break;
		}
	}

}