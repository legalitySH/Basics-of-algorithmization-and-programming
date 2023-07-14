#include"Heap.h"
#include"HeapFunctions.h"

void menu() {
	cout << "\n1 - �������� ������� � ����\n";
	cout << "2 - ����� ������� � ����\n";
	cout << "3 - ����� ���� ����\n";
	cout << "4 - �������� �������� ���� �� �������\n";
	cout << "5 - �������� ������������ �������� ����\n";
	cout << "6 - �������� ������������� �������� ����\n";
	cout << "7 - ����������� ���� ��� � ����\n";
	cout << "0 - ����� �� ���������\n\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int choice = 0;
	int capacity;
	cout << "������� ������ �������� ����: "; cin >> capacity;
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
			cout << "������� ������� ��� ������: "; cin >> searchData;
			heap.search(searchData);
		}
		case 3: {
			heap.output();
			break;
		}
		case 4: {
			int deletedElement; 
			cout << "������� ������ ���������� ��������: "; cin >> deletedElement;
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
			cout << "������� ������ ������ ����:"; cin >> size;
			Heap h(size);
			for (int i = 0; i < size; i++)
			{
				h.insert(rand() % 100 + 100);
			} 
			cout << "������ ���� ������������!\n";
			h.output();
			heap.unionHeap(h);
			cout << "��������� ����������� ���: " << endl;
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