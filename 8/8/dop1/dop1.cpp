

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
void enqueue3(Node*& head, Node*& tail, int priority, int data) {
	Node* newNode = new Node;
	newNode->priority = priority;
	newNode->data = data;
	newNode->prev = tail;
	newNode->next = nullptr;

	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		Node* current = tail;
		while (current != nullptr && current->priority > priority) {
			current = current->prev;
		}

		if (current == nullptr) {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->prev = current;
			newNode->next = current->next;
			if (current->next != nullptr) {
				current->next->prev = newNode;
			}
			else {
				tail = newNode;
			}
			current->next = newNode;
		}
	}
}
void enqueue4(Node*& head, Node*& tail, int priority, int data) {
	Node* newNode = new Node;
	newNode->priority = priority;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr) { // ���� ������� �����
		head = newNode;
		tail = newNode;
	}
	else if (priority > head->priority) { // ���� ����� ������� ����� ����� ������� ���������, ��� �������� �������
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if (priority <= tail->priority) { // ���� ����� ������� ����� ����� ������ ���������, ��� ��������� �������
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else { // ���� ����� ������� ����� ��������� ����� �������� � ��������� ����������
		Node* current = tail;
		while (priority > current->priority) {
			current = current->prev;
		}
		newNode->prev = current;
		newNode->next = current->next;
		current->next->prev = newNode;
		current->next = newNode;
	}
}

int main() {
	setlocale(LC_ALL, "");

	Node* head1 = nullptr;
	Node* tail1 = nullptr;

	enqueue1(head1, tail1, 2, 5);
	enqueue1(head1, tail1, 3, 8);
	enqueue1(head1, tail1, 1, 1);
	enqueue1(head1,	tail1, 3, 7);
	cout << "1: ";
	while (head1 != nullptr) {
		cout << head1->data << " ";
		head1 = head1->next;
	}
	cout << endl;

	Node* head2 = nullptr;
	Node* tail2 = nullptr;

	enqueue2(&head2, &tail2, 2, 5);
	enqueue2(&head2, &tail2, 3, 8);
	enqueue2(&head2, &tail2, 1, 1);
	enqueue2(&head2, &tail2, 3, 7);

	cout << "2: ";
	while (head2 != nullptr) {
		cout << head2->data << " ";
		head2 = head2->next;
	}
	cout << endl;

	Node* head3 = nullptr;
	Node* tail3 = nullptr;

	enqueue3(head3, tail3, 2, 5);
	enqueue3(head3, tail3, 3, 8);
	enqueue3(head3, tail3, 1, 1);
	enqueue3(head3, tail3, 3, 7);

	cout << "3: ";
	while (head3 != nullptr) {
		cout << head3->data << " ";
		head3 = head3->next;
	}
	cout << endl;


	Node* head4 = nullptr;
	Node* tail4 = nullptr;

	enqueue4(head4, tail4, 2, 5);
	enqueue4(head4, tail4, 3, 7);
	enqueue4(head4, tail4, 1, 1);
	enqueue4(head4, tail4, 3, 8);

	cout << "4: ";
	while (head4 != nullptr) {
		cout << head4->data << " ";
		head4 = head4->next;
	}
}


