#include <iostream>
using namespace std;

// ������� ��������� ��� ������������� ������� �������� � �����
struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

void circleDelete(int n, int k) {
    // ������� ����������� ��������� ������
    Node* head = new Node(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = new Node(i);
        prev->next = curr;
        prev = curr;
    }
    prev->next = head;

    // ���� � ����� �������� ������ ������ ��������
    while (head->next != head) {
        // ���������� k-1 ���������
        for (int i = 0; i < k - 1; i++) {
            head = head->next;
        }
        // ������� k-�� �������� �� �����
        Node* temp = head->next;
        head->next = temp->next;
        cout << temp->value << " ";
        delete temp;
    }

    // ������� ���������� ����������� ��������
    cout << head->value << endl;
    delete head;
}

int main() {
    setlocale(LC_ALL, "rus");
    int n = 0, k = 0;
    cout << "������� ���������� ����� � �����: "; cin >> n;
    cout << "������� ����� k(��� k-�������� ����� ����������): "; cin >> k;
    cout << "������� ��������: ";
    circleDelete(n, k);
    return 0;
}