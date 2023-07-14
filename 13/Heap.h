#pragma once
#include<ctime>
#include<iostream>
using namespace std;

class Heap
{
public:
	void insert(int);
	void output();
	void search(int);
	void remove(int);
	void externMin();
	void externMax();
	void unionHeap(Heap);
	Heap(int);

private:
	int currentSize;
	int maxSize;
	int* storage;
	int getElement(int);
	int size();
	bool isFull();
	bool isEmpty();
	int parent(int);
	bool isLess(int,int);
	bool isGreat(int,int);
	void swap(int, int);
	int left(int);
	int right(int);
	void heapifyDown(int i);
	void heapifyUp(int i);


	
};

