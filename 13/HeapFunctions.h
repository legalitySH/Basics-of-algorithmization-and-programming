#pragma once
#include "Heap.h"


Heap::Heap(int maxsz)
{
	currentSize = 0;
	maxSize = maxsz;
	storage = new int[maxSize];
}

int Heap::getElement(int index) {
	return storage[index];
}

int Heap::size() {
	return currentSize;
}

bool Heap::isFull()
{
	return currentSize >= maxSize;
}

bool Heap::isEmpty()
{
	return currentSize <= 0;
}

bool Heap::isLess(int data1, int data2)
{
	return data1 < data2;
}

bool Heap::isGreat(int data1, int data2)
{
	return data1 > data2;
}

int Heap::parent(int i)
{
	return (i - 1) / 2;
}

void Heap::swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heap::insert(int data)
{
	if (isFull())
	{
		cout << " уча переполнена!\n";
	}
	else
	{
		storage[currentSize] = data;
		currentSize++;
		heapifyUp(currentSize - 1);
	}
}

void Heap::output()
{
	if (isEmpty())
	{
		cout << " уча пуста€!" << endl;
		return;
	}

	for (int i = 0; i < currentSize; i++)
	{
		cout << storage[i] << " ";
	}cout << endl;
}

void Heap::search(int data) {
	int sind = 0;
	bool flag = false;
	for (int i = 0; i < currentSize; i++)
	{
		if (data == storage[i])
		{
			sind = i;
			flag = true;
		}
	}
	if (flag) {
		cout << "Ёлемент " << data << " найден под номером " << sind + 1 << endl;
	}
	else {
		cout << "Ёлемент не найден!" << endl;
	}
}
 
int Heap::left(int i) {
	return 2 * i + 1;
}

int Heap::right(int i) {
	return 2 * i + 2;
}

void Heap::heapifyDown(int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int smallest = i;

	if (left < currentSize && isLess(storage[left], storage[smallest])) {
		smallest = left;
	}

	if (right < currentSize && isLess(storage[right], storage[smallest])) {
		smallest = right;
	}

	if (smallest != i) {
		swap(storage[i], storage[smallest]);
		heapifyDown(smallest);
	}
}

void Heap::heapifyUp(int i)
{
	while (i != 0 && isLess(storage[i], storage[(i - 1) / 2])) {
		swap(storage[i], storage[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void Heap::remove(int index)
{
	if (isEmpty()) {
		cout << " уча пуста\n";
		return;
	}

	if (index > currentSize || index < 0) {
		cout << "ќшибка ввода индекса\n";
		return;
	}

	storage[index] = storage[currentSize-1];
	currentSize--;

	int parent = (index - 1) / 2;
	if (index != 0 && isLess(storage[index], storage[parent])) {
		heapifyUp(index);
	}
	else {
		heapifyDown(index);
	}
}

void Heap::externMin() {
	if (isEmpty()) {
		cout << " уча пуста€!\n";
		return;
	}
	else {
		int min = storage[0];
		int min_index = 0;
		for (int i = 0; i < currentSize; i++)
		{
			if (storage[i] < min) {
				min = storage[i];
				min_index = i;
			}
		}
		remove(min_index);
	}
}

void Heap::externMax() {
	if (isEmpty()) {
		cout << " уча пуста€!\n";
		return;
	}
	else {
		int max = storage[0];
		int max_index = 0;
		for (int i = 0; i < currentSize; i++)
		{
			if (storage[i] > max) {
				max = storage[i];
				max_index = i;
			}
		}
		remove(max_index);
	}
}

void Heap::unionHeap(Heap h) {
	maxSize += h.size();
	for (int i = 0; i < h.size(); i++)
	{
		insert(h.getElement(i));
	}
}
