#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

struct list {
	char symbol;
	list* next;
	list* head;
};

void input(char* str) {
	cout << "Введите строку с чётным количеством символов!" << endl;
	cin.getline(str, 255);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* str = new char[255];
	input(str);
	if (strlen(str) % 2 != 0) {
		cout << "Ошибка , количество символов нечётное!" << endl;
		input(str);
	}
	list* plist_1 = nullptr, *plist_2 = nullptr;
	list* reverse_1, * reverse_2;

	for (int i = 0; i < strlen(str)/2; i++)
	{
		reverse_1 = new list;
		reverse_1->symbol = str[i];
		reverse_1->next = plist_1;
		plist_1 = reverse_1;
	}
	reverse_1 = plist_1;
	for (int i = strlen(str) / 2; i < strlen(str); i++)
	{
		reverse_2 = new list;
		reverse_2->symbol = str[i];
		reverse_2->next = plist_2;
		plist_2 = reverse_2;
	}
	reverse_2 = plist_2;
	while (reverse_1)
	{
		cout << reverse_1->symbol;
		reverse_1 = reverse_1->next;
	}
	while (reverse_2)
	{
		cout << reverse_2->symbol;
		reverse_2 = reverse_2->next;
	}

}