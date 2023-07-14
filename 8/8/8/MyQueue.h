#pragma once

#include<iostream>
#include<Windows.h>

using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int head;
    int tail;
    int size;
    char arr[MAX_SIZE]{};
public:
    Queue(int QueueSize) {
        head = -1;
        tail = -1;
        size = QueueSize;
    }
    ~Queue() { // деструктор класса 
        clear();
    }

    bool isEmpty();

    bool isFull();

    void EnQueue(char value);

    void DeQueue();

    void Show();

    void clear();

    void Peek();

    bool Aviability(char EtalonSymbol);

    void LabFunction(char EtalonSymbol);

};





