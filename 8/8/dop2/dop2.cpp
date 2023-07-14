#include <iostream>

using namespace std;

struct Queue {
    int front, rear, size;
    float* elements;
    int capacity;
};

Queue* createQueue(int capacity) {
    Queue* queue = new Queue;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->elements = new float[capacity];
    return queue;
}

void enqueue(Queue* queue, float item) {
    if (queue->size == queue->capacity) {
        cout << "Queue is full\n";
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
    queue->size++;
}

float dequeue(Queue* queue) {
    if (queue->size == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    float item = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

float front(Queue* queue) {
    if (queue->size == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue->elements[queue->front];
}

float rear(Queue* queue) {
    if (queue->size == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue->elements[queue->rear];
}

void rotateQueue(Queue* queue) {
    // Находим индекс максимального элемента
    int max_idx = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->elements[i] > queue->elements[max_idx]) {
            max_idx = i;
        }
    }
    // Сдвигаем очередь так, чтобы максимальный элемент оказался в начале
    while (queue->front != max_idx) {
        float temp = dequeue(queue);
        enqueue(queue, temp);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер очереди: ";
    cin >> n;
    Queue* queue = createQueue(n);
    cout << "Введите " << n << " чисел с плавающей запятой :\n";
    for (int i = 0; i < n; i++) {
        float num;
        cin >> num;
        enqueue(queue, num);
    }
    rotateQueue(queue);
    cout << "После циклического сдвига: ";
    while (queue->size > 0) {
        cout << dequeue(queue) << " ";
    }
    cout << endl;
    delete[] queue->elements;
    delete queue;
    return 0;
}
