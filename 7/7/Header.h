#pragma once
#include <iostream>
#include <Windows.h>
#include<fstream>

using namespace std;

struct Stack {
	char element;
	Stack* head;
	Stack* next;
};

bool output(Stack* mystk);

void push(char x, Stack* myStk);

bool pop(Stack* mystk);

void readFromFile(Stack*& myStk);

void writeToFile(Stack*& myStk);

bool clear(Stack*& myStk);