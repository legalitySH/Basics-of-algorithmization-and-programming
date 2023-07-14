#include<iostream>
#include<string>
#include"HashTwin.h"
using namespace std;


HashTable::HashTable(int maxSz) {
	capacity = maxSz;
	currentSize = 0;
	data = new node * [capacity]{nullptr};
}

HashTable::~HashTable() {
	delete[] data;
}

bool HashTable::isEmpty() {
	return currentSize == 0;
}

bool HashTable::isFull() {
	return currentSize >= capacity;
}

int HashTable::hash(int key) {
	return key % capacity;
}

void HashTable::insert(int key, UniversityInfo value)
{
	if (isFull()) {
		cout << "Хеш-таблица заполнена!" << endl;
		return;
	}
	int index = hash(key);
	node* current = data[index];
	if (data[index] == nullptr) {
		current = new node(key, value);
		data[index] = current;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->next == nullptr) {
				node* temp = new node(key, value);
				current->next = temp;
				temp->prev = current;
				break;
			}
			current = current->next;
		}
	}
	currentSize++;
}

void HashTable::output()
{
	if (isEmpty()) {
		cout << "Хеш-таблица пустая!" << endl;
		return;
	}
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] != nullptr) {
			node* current = data[i];
			cout << current->data << endl;
			while (current->next != nullptr)
			{
				cout << current->data << endl;
				current = current->next;
			}
		}

	}
}

void HashTable::search(int key) {
	int index = hash(key);
	node* current = data[index];
	bool found = false;
	while (current != nullptr)
	{
		if (current->key == key) {
			cout << current->data << endl;

			found = true;
		}
		current = current->next;
	}
	if (!found) {
		cout << "Не найдено элементов с ключом " << key << endl;
	}
}

bool HashTable::remove(int key) {
	int index = hash(key);
	node* current = data[index];
	bool removed = false;
	while (current != nullptr) {
		if (current->key == key) {
			if (current->prev != nullptr) {
				current->prev->next = current->next;
			}
			else {
				data[index] = current->next;
			}
			if (current->next != nullptr) {
				current->next->prev = current->prev;
			}
			node* temp = current;
			current = current->next;
			delete temp;
			currentSize--;
			removed = true;
		}
		else {
			current = current->next;
		}
	}
	return removed;
}

void HashTable::searchLetters(int key) {
	bool found = false;
	int hashIndex = hash(key);

	node* ptr = data[hashIndex];
	if (ptr == nullptr) {
		cout << "Элемент с ключом " << key << " не найден." << endl;
		return;
	}

	while (ptr != nullptr) {
		if (ptr->key == key) {
			found = true;
			if (ptr != nullptr) {
				ptr->data.countOfuse++;
				break;
			}
		}
		ptr = ptr->next;
	}

	if (!found) {
		cout << "Элемент с ключом " << key << " не найден." << endl;
	}
}

