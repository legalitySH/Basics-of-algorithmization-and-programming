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
			cout << i << "-� ������� ����� ����� ���������� � = " <<  StackObject->head->element << endl;
			StackObject->head = StackObject->head->next;
			flag = true;
		}
		else
			StackObject->head = StackObject->head->next;
	}
	if (flag == false)
	{
		cout << "��� ������ ��������" << endl;
	}

}

void StackOutPut(Stack*& StackObject) {
	Stack* e = StackObject->head;
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
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
	cout << "������� ���������� ��������� �����:"; cin >> CountOfObjects;
	underline();
	cout << "��������� ���� !" << endl;
	underline();
	for (int i = 0; i < CountOfObjects; i++)
	{
		cout << "������� " << i + 1 << "-�� ������� ����� = "; cin >> AddingObject;
		StackPush(StackObject, AddingObject);
	}
	underline();
	cout << "���������� �����: "; StackOutPut(StackObject);
	underline();
	task(StackObject);
	underline();



}