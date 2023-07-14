#include<iostream>

using namespace std;

struct Stack {
	int element;
	Stack* next;
	Stack* head;
};

void underline() {
	cout << "--------------------------------------------------" << endl;
}

void task(Stack*& StackObject)
{
	int i = 0;
	bool flag = false;
	while (StackObject->head->next != NULL)
	{
		i++;
		if (StackObject->head->element == StackObject->head->next->element)
		{
			cout << i << "-й элемент стека равен следующему и = " <<  StackObject->head->element << endl;
			StackObject->head = StackObject->head->next;
			flag = true;
		}
		else
			StackObject->head = StackObject->head->next;
	}
	if (flag == false)
	{
		cout << "Нет такого элемента" << endl;
	}

}

void StackOutPut(Stack*& StackObject) {
	Stack* e = StackObject->head;
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

void StackPush(Stack*& StackObject, int PushValue) {
	Stack* e = new Stack;
	e->element = PushValue;
	e->next = StackObject->head;
	StackObject->head = e;
}

int main() {
	setlocale(0, "");
	Stack* StackObject = new Stack;
	int AddingObject = 0;
	StackObject->head = NULL;
	int CountOfObjects = 0;
	cout << "Введите количество элементов стека:"; cin >> CountOfObjects;
	underline();
	cout << "Заполните стек !" << endl;
	underline();
	for (int i = 0; i < CountOfObjects; i++)
	{
		cout << "Введите " << i + 1 << "-ый элемент стека = "; cin >> AddingObject;
		StackPush(StackObject, AddingObject);
	}
	underline();
	cout << "Содержимое стека: "; StackOutPut(StackObject);
	underline();
	task(StackObject);
	underline();



}