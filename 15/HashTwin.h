#pragma once
#include<string>
#include<iostream>
using namespace std;

struct UniversityInfo {
	int createYear;
	string universityName;
	string chefName;
	UniversityInfo& operator=(const UniversityInfo& other) {
		this->universityName = other.universityName;
		this->chefName = other.chefName;
		this->createYear = other.createYear;
		return *this;
	}
	int countOfuse;
};

ostream& operator<<(ostream& os, const UniversityInfo& univ) {
	os << "Университет: " << univ.universityName << ", Ректор: " << univ.chefName << ", Год создания :" << univ.createYear;
	return os;
}

class HashTable
{
public:
	HashTable(int maxSz);
	~HashTable();

	void insert(int,UniversityInfo value);
	void search(int);
	bool remove(int);
	void output();
	void searchLetters(int key);

private:
	bool isEmpty();
	bool isFull();
	struct node {
		UniversityInfo data;
		node* prev;
		node* next;
		int key;
		node(int key, UniversityInfo value) {
			this->key = key;
			this->data = value;
			prev = nullptr;
			next = nullptr;
		}
	};
	int capacity;
	int currentSize;
	node** data;

	int hash(int);
};

