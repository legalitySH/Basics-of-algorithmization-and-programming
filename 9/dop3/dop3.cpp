#include <iostream>
using namespace std;

// —оздаем структуру дл€ представлени€ каждого человека в кругу
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

void circleDelete(int n, int k) {
    // —оздаем циклический св€занный список
    Node* head = new Node(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = new Node(i);
        prev->next = curr;
        prev = curr;
    }
    prev->next = head;

    // ѕока в круге остаетс€ больше одного человека
    while (head->next != head) {
        // ѕропускаем k-1 человеков
        for (int i = 0; i < k - 1; i++) {
            head = head->next;
        }
        // ”дал€ем k-го человека из круга
        Node* temp = head->next;
        head->next = temp->next;
        cout << temp->value << " ";
        delete temp;
    }

    // ¬ыводим последнего оставшегос€ человека
    cout << head->value << endl;
    delete head;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n = 0, k = 0;
    cout << "¬ведите количество людей в кругу: "; cin >> n;
    cout << "¬ведите число k(где k-интервал между удал€емыми): "; cin >> k;
    cout << "ѕор€док удалени€: ";
    circleDelete(n, k);
    return 0;
}