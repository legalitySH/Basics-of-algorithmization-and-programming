

#include<iostream>

using namespace std;


struct Node {
    int priority;
    int data;
    Node* next, * prev;
};

// ������� ���������� ��������



void enqueue1(Node*& head, Node*& tail, int priority, int data) {
    // ������� ����� ����
    Node* newNode = new Node;
    newNode->priority = priority;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // ���� ������� �����, �� ����� ���� ���������� �������� � ���������
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // ���� ����� ������� ����� ����� ������� ���������, �� �� ���������� ��������
        if (priority < head->priority) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            // ���� ��������� ������� � ����� �� �����������
            Node* lastSamePriorityNode = nullptr;
            Node* current = head;
            while (current != nullptr && current->priority <= priority) {
                if (current->priority == priority) {
                    lastSamePriorityNode = current;
                }
                current = current->next;
            }

            // ���� �� ����� �������� � ����� �� �����������, �� ��������� ����� ������� � ����� �������
            if (lastSamePriorityNode == nullptr) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            else {
                // ��������� ����� ������� ����� ���������� �������� � ����� �� �����������
                newNode->prev = lastSamePriorityNode;
                newNode->next = lastSamePriorityNode->next;
                if (lastSamePriorityNode->next != nullptr) {
                    lastSamePriorityNode->next->prev = newNode;
                }
                else {
                    tail = newNode;
                }
                lastSamePriorityNode->next = newNode;
            }
        }
    }
}
void enqueue2(Node** head, Node** tail, int priority, int data) {
    // ������� ����� ����
    Node* new_node = new Node;
    new_node->priority = priority;
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    // ���� ������� �����, ��������� ����� ������� ��� ������
    if (*head == nullptr) {
        *head = new_node;
        *tail = new_node;
        return;
    }

    // ���� ����� ��� ������� ��������
    Node* curr = *head;
    while (curr != nullptr && curr->priority >= priority) {
        curr = curr->next;
    }

    // ��������� �������
    if (curr == nullptr) {
        // ��������� � �����
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }
    else {
        // ��������� ����� ������� ���������
        new_node->prev = curr->prev;
        new_node->next = curr;
        if (curr->prev != nullptr) {
            curr->prev->next = new_node;
        }
        else {
            *head = new_node;
        }
        curr->prev = new_node;
    }
}

int main() {
    setlocale(LC_ALL, "");

    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    
    //1

    enqueue1(head1, tail1, 1, 1);
    enqueue1(head1, tail1, 3, 7);
    enqueue1(head1, tail1, 2, 5);
    enqueue1(head1, tail1, 3, 6);
    cout << "1: ";
    while (head1 != nullptr) {
        cout << head1->data << " ";
        head1 = head1->next;
    }


}


