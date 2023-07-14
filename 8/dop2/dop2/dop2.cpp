#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

struct Queue {
    int front, rear, size;
    float arr[MAX_SIZE];
};

void initQueue(Queue& q) {
    q.front = q.size = 0;
    q.rear = -1;
}

bool isFull(Queue& q) {
    return q.size == MAX_SIZE;
}

bool isEmpty(Queue& q) {
    return q.size == 0;
}

void enqueue(Queue& q, float val) {
    if (isFull(q)) {
        cout << "ќчередь переполнена!" << endl;
        return;
    }
    q.rear = (q.rear + 1) % MAX_SIZE;
    q.arr[q.rear] = val;
    q.size++;
}

float dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "ќчередь пуста!" << endl;
        return -1;
    }
    float val = q.arr[q.front];
    q.front = (q.front + 1) % MAX_SIZE;
    q.size--;
    return val;
}

void printQueue(Queue& q) {
    if (isEmpty(q)) {
        cout << "ќчередь пуста!" << endl;
        return;
    }
    cout << "ќчередь: ";
    int i = q.front;
    while (i != q.rear) {
        cout << q.arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << q.arr[i] << endl;
}

void shiftMaxToFront(Queue& q) {
    if (isEmpty(q)) {
        cout << "ќчередь пуста!" << endl;
        return;
    }
    int maxIndex = q.front;
    for (int i = q.front + 1; i <= q.rear; i++) {
        if (q.arr[i] > q.arr[maxIndex]) {
            maxIndex = i;
        }
    }
    while (q.front != maxIndex) {
        float temp = q.arr[q.front];
        dequeue(q);
        enqueue(q, temp);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    Queue q;
    initQueue(q);

    cout << "¬ведите элементы очереди:" << endl;
    float val;
    for (int i = 0; i < MAX_SIZE; i++) {
        cin >> val;
        enqueue(q, val);
    }

    shiftMaxToFront(q);

    cout << "Ёлементы очереди после циклического сдвига:" << endl;
    printQueue(q);

    return 0;
}
