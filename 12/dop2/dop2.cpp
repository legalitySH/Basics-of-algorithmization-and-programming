#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;


class Tree {
private:
public:
	struct Node {
		int data;
		int key_value;
		Node* left;
		Node* right;

		Node(const int& value, int key_value) :data(value), key_value(key_value), left(nullptr), right(nullptr) {}
	};

	Node* root;
	Tree() {
		root = nullptr;
	}


	void Insert(Node*&, const int&, int key_val);
	void Insert(const int&, int);
	void Output(Node*, const int);
	void Output();

};

void Tree::Insert(Node*& node, const int& value, int key_val) {
	if (node == nullptr) {
		node = new Node(value, key_val);
	}
	else if (key_val == node->key_value) {
		cout << "Ошибка : Узел с таким узлом уже существует! " << endl;
	}
	else if (value < node->data) {
		Insert(node->left, value, key_val);
	}
	else {
		Insert(node->right, value, key_val);
	}
}

void Tree::Insert(const int& value, int key_val) {
	Insert(root, value, key_val);
}

void Tree::Output(Node* root, int indent) {
	if (root == nullptr) {
		return;
	}
	Output(root->right, indent + 4);
	if (indent > 0) {
		std::cout << std::setw(indent) << " ";
	}
	std::cout << root->data << std::endl;
	Output(root->left, indent + 4);
}

void Tree::Output() {
	Output(root, 0);
}

void createTreeFromSequence(Tree& tree, int* arr, int start, int end, int key) {
	if (start > end) {
		return;
	}

	int mid = (start + end) / 2;
	tree.Insert(arr[mid], key);

	createTreeFromSequence(tree, arr, start, mid - 1, 2 * key);
	createTreeFromSequence(tree, arr, mid + 1, end, 2 * key + 1);
}

int main() {
	int N;
	cout << "N = "; cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 100;
	}

	Tree tree;
	createTreeFromSequence(tree, arr, 0, N - 1, 1);
	tree.Output();

	return 0;
}


