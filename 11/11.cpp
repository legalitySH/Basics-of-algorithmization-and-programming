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

		Node(const int& value,int key_value) :data(value), key_value(key_value), left(nullptr), right(nullptr) {}
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
	Node* Search(Node*,int);

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



};

void Tree::Insert(Node*& root, const int& data_val, int key_val) {
	if (root == nullptr) {
		root = new Node(data_val, key_val);
	}
	else if (key_val < root->key_value) {
		Insert(root->left, data_val, key_val);
	}
	else {
		Insert(root->right, data_val, key_val);
	}
}

void Tree::Insert(const int& data_val, int key_val) {
	Insert(root, data_val, key_val);
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

void Tree::PrintNode(Node *node) {
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
	Remove(root,key);
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

double Tree::Average(Node* root)
{
	if (root == nullptr) {
		return 0.0;
	}

	double sum = root->data;
	int count = 1;
	if (root->left != nullptr) {
		sum += Average(root->left);
		count++;
	}
	if (root->right != nullptr) {
		sum += Average(root->right);
		count++;
	}

	return sum / count;
}


double Tree::Average()
{
	return Average(root);
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
	Tree  tree;
	while (true)
	{
		switch (menu()) {
		case 1: {
			int data, key;
			cout << "Введите данные: "; cin >> data;
			cout << "Введите ключ: "; cin >> key;
			tree.Insert(data, key);
			cout << "Звено успешно добавлено!" << endl;
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
		case 0: {
			exit(0);
			break;
		}
		}
	}


	
}

