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

	Node* Search(int);
	Node* Search(Node*, int);

	void PrintNode(Node*);

	void Remove(Node*&, int);
	void Remove(int);

	Node* FindMin(Node*);

	int CountNodes(Node*);
	int CountNodes();

	void Clear(Node*);
	void Clear();


	double Average(Node*);
	double Average();

	int CountRightNodes(Node*);
	int CountRightNodes();

	double SumValues(Node*);
	double SumValues();

	int CountEvenKeys(Node*);
	int CountEvenKeys();

	void TraversalOutput(Node*, const int);
	void TraversalOutput();

	void PreOrderTraversal(Node*, const int);
	void PreOrderTraversal();

	int height(Node*);

	bool isBalanced(Node*);
	bool isBalanced();

	double sum_element(Node* node) const;


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

typename Tree::Node* Tree::Search(Node* root, int key_val) {
	if (root == nullptr || root->key_value == key_val) {
		return root;
	}
	if (root->key_value < key_val) {
		return Search(root->right, key_val);
	}
	return Search(root->left, key_val);
}

typename Tree::Node* Tree::Search(int key_val) {
	return Search(root, key_val);
}

void Tree::PrintNode(Node* node) {
	if (node != nullptr) { cout << node->data << " "; }
	else { cout << "Элемента с таким ключом не существует!" << endl; }
}

typename Tree::Node* Tree::FindMin(Node* root) {
	if (root == nullptr) {
		return nullptr;
	}
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

void Tree::Remove(Node*& root, int key) {
	if (root == nullptr) {
		cout << "Элемент не найден!" << endl;
		return;
	}
	if (key < root->key_value) {
		Remove(root->left, key);
	}
	else if (key > root->key_value) {
		Remove(root->right, key);
	}
	else { // key == root->key_value
		if (root->left == nullptr && root->right == nullptr) { // случай 1: нет потомков
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) { // случай 2a: только правый потомок
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) { // случай 2b: только левый потомок
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else { // случай 3: два потомка
			Node* min_right = FindMin(root->right);
			root->key_value = min_right->key_value;
			root->data = min_right->data;
			Remove(root->right, min_right->key_value);
		}
	}
}

void Tree::Remove(int key) {
	Remove(root, key);
}

int Tree::CountNodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int Tree::CountNodes() {
	return CountNodes(root);
}

void Tree::Clear(Node* node) {
	if (node == nullptr) {
		return;
	}
	Clear(node->left);
	Clear(node->right);
	delete node;
}

void Tree::Clear() {
	Clear(root);
	root = nullptr;
}

int Tree::CountRightNodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->right == nullptr) {
		return 0;
	}
	return 1 + CountRightNodes(root->right);
}

int Tree::CountRightNodes() {
	return CountRightNodes(root);
}

double Tree::SumValues(Node* root) {
	if (root == nullptr) {
		return 0.0;
	}
	return root->data + SumValues(root->left) + SumValues(root->right);
}

double Tree::SumValues() {
	return SumValues(root);
}

int Tree::CountEvenKeys(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	int count = (root->key_value % 2 == 0) ? 1 : 0;
	return count + CountEvenKeys(root->left) + CountEvenKeys(root->right);
}

int Tree::CountEvenKeys() {
	return CountEvenKeys(root);
}

void Tree::TraversalOutput(Node* node, const int level) {
	if (node == nullptr) {
		return;
	}
	TraversalOutput(node->left, level + 1);
	for (int i = 0; i < level; i++) {
		cout << "--";
	}
	cout << "[" << node->key_value << "] " << node->data << endl;
	TraversalOutput(node->right, level + 1);
}

void Tree::TraversalOutput() {
	TraversalOutput(root, 0);
}

void Tree::PreOrderTraversal(Node* node, const int level) {
	if (node == nullptr) {
		return;
	}
	for (int i = 0; i < level; i++) {
		cout << "--";
	}
	cout << "[" << node->key_value << "] " << node->data << endl;
	PreOrderTraversal(node->left, level + 1);
	PreOrderTraversal(node->right, level + 1); 
}

void Tree::PreOrderTraversal() {
	PreOrderTraversal(root, 0);
}

int Tree::height(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int left_height = height(node->left);
	int right_height = height(node->right);
	return 1 + max(left_height, right_height);
}

bool Tree::isBalanced(Node* node) {
	if (node == nullptr) {
		return true;
	}
	int left_height = height(node->left);
	int right_height = height(node->right);
	int height_diff = abs(left_height - right_height);
	if (height_diff > 1) {
		return false;
	}
	return isBalanced(node->left) && isBalanced(node->right);
}

bool Tree::isBalanced() {
	return isBalanced(root);
}

double Tree::sum_element(Node* node) const
{
  if (node == nullptr) { return 0; }
  double sum = double(node->data);
  return sum + sum_element(node->left) + sum_element(node->right);
}

double Tree::Average() { return sum_element(root) /	CountNodes(root); }












int menu() {
	int choice;
	cout << endl;
	cout << "1 -	Добавление узла\n";
	cout << "2 -	Поиск по ключу\n";
	cout << "3 -	Удаление элемента\n";
	cout << "4 -	Вывод дерева\n";
	cout << "5 -	Подсчет количества узлов\n";
	cout << "6 -	Очистка дерева\n";
	cout << "7 -     Cреднее арифметическое узлов\n"; // 14 вариант
	cout << "8 -     Количество узлов правой ветви дерево\n";// 15 вариант
	cout << "9 -     Общая сумма значений всех узлов\n"; // 16 вариант
	cout << "10 -    Количество узлой с чётными узлами\n"; // 12 вариант
	cout << "11 -    Смешанный обход дерева\n";
	cout << "12 -    Нисходящий обход дерева\n";
	cout << "13 -    Проверить дерево на сбалансированность\n";
	cout << "0 -	Выход\n";
	cout << "Выберите вариант:\n";
	cin >> choice;
	cout << "\n";
	return choice;
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Tree tree;
	while (true)
	{
		switch (menu()) {
		case 1: {
			int data, key;
			cout << "Введите данные: "; cin >> data;
			cout << "Введите ключ: "; cin >> key;
			tree.Insert(data, key);
			break;
		}
		case 2: {
			int key;
			cout << "Введите ключ: "; cin >> key;
			cout << "Данные: ";
			tree.PrintNode(tree.Search(key));

			break;
		}
		case 3: {
			int remove_key;
			cout << "Введите ключ звена, которого хотите удалить: "; cin >> remove_key;
			tree.Remove(remove_key);
			break;
		}
		case 4: {
			cout << "Бинарное дерево:\n\n";
			tree.Output();
			break;
		}
		case 5: {
			cout << "Количество звён в бинарном дереве : " << tree.CountNodes();
			break;
		}
		case 6: {
			tree.Clear();
			break;
		}
		case 7: {
			cout << "Среднее арифметическое всех элементов: " << tree.Average() << endl;
			break;
		}
		case 8: {
			cout << "Количество узлов правой части дерева :" << tree.CountRightNodes() << endl;
			break;
		}
		case 9: {
			cout << "Сумма значений всех узлов бинарного дерева: " << tree.SumValues() << endl;
		}
		case 10: {
			cout << "Количество узлов с чётными ключами : " << tree.CountEvenKeys() << endl;
		}
		case 11: {
			tree.TraversalOutput();
			break;
		}
		case 12: {
			tree.PreOrderTraversal();
			break;
		}
		case 13: {
			if (tree.isBalanced()) {
				cout << "Дерево сбалансировано!" << endl;
			}
			else {
				cout << "Дерево не сбалансировано!" << endl;
			}
			break;
		}
		case 0: {
			exit(0);
			break;
		}
		default: cout << "Неправильный вариант ответа!" << endl;
			break;
		}
	}



}

