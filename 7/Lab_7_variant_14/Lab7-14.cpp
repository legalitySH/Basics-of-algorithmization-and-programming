#include<iostream>

using namespace std;

struct FirstStack {
	int element;
	FirstStack* next;
	FirstStack* head;
};

struct SecondStack
{
	int element;
	SecondStack* next;
	SecondStack* head;
};

struct ResultStack {
	int element;
	ResultStack* next;
	ResultStack* head;
};

void underline() {
	cout << "--------------------------------------------------" << endl;
}

void StackOutPut(FirstStack*& StackObject) {
	FirstStack* e = StackObject->head;    
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->element;          
		cout << a << " ";
		e = e->next;
	}
	cout << endl;

}

void StackOutPut(SecondStack*& StackObject) {
	SecondStack* e = StackObject->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->element;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;

}

void StackOutPut(ResultStack*& StackObject) {
	ResultStack* e = StackObject->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->element;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;

}

void StackPush(FirstStack*& StackObject, int PushValue) {
	FirstStack* e = new FirstStack;  
	e->element = PushValue;         
	e->next = StackObject->head; 
	StackObject->head = e;
}

void StackPush(SecondStack*& StackObject, int PushValue) {
	SecondStack* e = new SecondStack;
	e->element = PushValue;
	e->next = StackObject->head;
	StackObject->head = e;
}

void StackPush(ResultStack*& StackObject, int PushValue) {
	ResultStack* e = new ResultStack;
	e->element = PushValue;
	e->next = StackObject->head;
	StackObject->head = e;
}

int main() {
	setlocale(0, "");
	FirstStack* FirstStackObject = new FirstStack;
	SecondStack* SecondStackObject = new SecondStack;
	ResultStack* ResultStackObject = new ResultStack;
	FirstStackObject->head = NULL;
	SecondStackObject->head = NULL;
	ResultStackObject->head = NULL;
	int FirstSize = 0, SecondSize = 0, AddingObject = 0;
	cout << "Введите размер 1 стека ="; cin >> FirstSize;
	int* farray = new int[FirstSize];
	underline();
	cout << "Заполните первый стек!" << endl;
	underline();
	for (int i = 0; i < FirstSize; i++)
	{
		cout << "Введите " << i + 1 << "-ый элемент стека = "; cin >> AddingObject;
		StackPush(FirstStackObject, AddingObject);
		farray[i] = AddingObject;
	}
	underline();
	cout << "Содержимое первого стека : "; StackOutPut(FirstStackObject);
	underline();
	cout << "Введите размер 2 стека ="; cin >> SecondSize;
	underline();
	cout << "Заполните второй стек!" << endl;
	underline();
	int* sarray = new int[SecondSize];
	for (int i = 0; i < SecondSize; i++)
	{
		cout << "Введите " << i + 1 << "-ый элемент стека = "; cin >> AddingObject;
		StackPush(SecondStackObject, AddingObject);
		sarray[i] = AddingObject;
	}
	underline();
	cout << "Содержимое второго стека : "; StackOutPut(SecondStackObject);
	underline();

	for (int i = 0; i < FirstSize; i++)
	{
		for (int j = 0; j < SecondSize; j++)
		{
			if (farray[i] == sarray[j]) {
				StackPush(ResultStackObject, farray[i]);
			}
		}
	}

	underline();
	cout << "Содержимое результирующего стека : "; StackOutPut(ResultStackObject);



	
}