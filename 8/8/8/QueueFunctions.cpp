#include"MyQueue.h"
#include"stdafx.h"


bool Queue::,

() {
    return (head == -1 && tail == -1);
}

bool Queue::isFull() {
    return ((tail + 1) % size == head);
}

void Queue::EnQueue(char value) {
    if (isFull()) {
        cout << "������� �����������!" << endl;
        return;
    }
    else if (isEmpty()) {
        head = 0;
        tail = 0;
    }
    else {
        tail = (tail + 1) % size;
    }
    arr[tail] = value;
}

void Queue::DeQueue() {
    if (isEmpty()) {
        cout << "������� ������!" << endl;
        return;
    }
    else if (head == tail) {
        head = -1;
        tail = -1;
    }
    else {
        head = (head + 1) % size;
    }
}

void Queue::Show() {
    if (isEmpty()) {
        cout << "������� ������!" << endl;
        return;
    }
    else {
        cout << "�������: ";
        int i = head;
        while (i != tail) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[tail] << endl;
    }
}

void Queue::clear(){
        head = -1;
        tail = -1;
}

void Queue::Peek() {
    if (isEmpty()) {
        cout << "������� ������!" << endl;
        return;
    }
    else {
        cout << "������ ������� ������� = " << arr[head] << endl;
    }
}

bool Queue::Aviability(char EtalonSymbol) {
    if (isEmpty()) {
        cout << "������� ������!" << endl;
        return false;
    }
    else {
        int i = head;
        while (i != tail) {
            if (arr[i] == EtalonSymbol) {
                return true;
            }
            i = (i + 1) % size;
        }
        return false;
    }
}

void Queue::LabFunction(char EtalonSymbol) {
    if (Aviability(EtalonSymbol)) {
        int i = head;
        while (arr[i] != EtalonSymbol) {
            DeQueue();
            i = (i + 1) % size;
        }
        cout << "�������!" << endl;
        Show();
    }
    else {
        cout << "������ ������� � ������� ���!" << endl;
    }
}


