#include"Heap.h"
#include"HeapFunctions.h"

void menu() {
	cout << "\n1 - Добавить элемент в кучу\n";
	cout << "2 - Найти элемент в куче\n";
	cout << "3 - Вывод всей кучи\n";
	cout << "4 - Удаление элемента кучи по индексу\n";
	cout << "5 - Удаление минимального элемента кучи\n";
	cout << "6 - Удаление максимального элемента кучи\n";
	cout << "7 - Объединение двух куч в одну\n";
	cout << "0 - Выход из программы\n\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int choice = 0;
	int capacity;
	cout << "Введите размер желаемой кучи: "; cin >> capacity;
	Heap heap(capacity);
	while (true) {
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1: {
			heap.insert(rand() % 100);
			break;
		}
		case 2: {
			int searchData;
			cout << "Введите элемент для поиска: "; cin >> searchData;
			heap.search(searchData);
		}
		case 3: {
			heap.output();
			break;
		}
		case 4: {
			int deletedElement; 
			cout << "Введите индекс удаляемого элемента: "; cin >> deletedElement;
			heap.remove(deletedElement);
			break;
		}
		case 5: {
			heap.externMin();
			break;
		}
		case 6: {
			heap.externMax();
			break;
		}
		case 7: {
			int size;
			cout << "Введите размер второй кучи:"; cin >> size;
			Heap h(size);
			for (int i = 0; i < size; i++)
			{
				h.insert(rand() % 100 + 100);
			} 
			cout << "Вторая куча сформирована!\n";
			h.output();
			heap.unionHeap(h);
			cout << "Результат объединения куч: " << endl;
			heap.output();
			break;
		}
		case 0: {
			exit(EXIT_SUCCESS);
			break;
		}
		default:
			break;
		}
	}
}