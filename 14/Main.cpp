#include"HashFunctions.h"

using namespace std;
using namespace chrono;

void menu() {
	cout << "1 - �������� �������\n";
	cout << "2 - �����\n";
	cout << "3 - ��������\n";
	cout << "4 - �����\n";
	cout << "5 - ��������� �����������\n";
	cout << "6 - ��������\n";
	cout << "0 - �����\n";
}
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int choice = 0;
	int capacity;
	cout << "������� ������ ���-�������: "; cin >> capacity;
	Hash HashTable(capacity);
	while (true)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1: {
			int key, value;
			cout << "������� ����: "; cin >> key;
			cout << "������� ��������: "; cin >> value;
			HashTable.insert(key, value);
			break;
		}
		case 2: {
			HashTable.output();
			break;
		}
		case 3: {
			int deleteValue;
			cout << "������� ���� ��� ��������: "; cin >> deleteValue;
			HashTable.remove(deleteValue);
			break;
		}
		case 4: {
			int searchKey;
			cout << "������� ���� ��� ������: "; cin >> searchKey;
			auto start = high_resolution_clock::now();
			HashTable.find(searchKey);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start).count();
			cout << "����� ���������� ������: " << duration << " ����������" << endl;
			break;
		}
		case 5: {
			HashTable.clear();
			for (int i = 0; i < capacity; i++)
			{
				HashTable.insert(rand() % 100, rand() % 1000);
			}
			break;
		}
		case 6: {
			HashTable.clear();
			break;
		}
		case 0: {
			exit(0);
			break;
		}
		default:
			break;
		}
	}
}

