#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>
#include<string>
#include<map>

using namespace std;

struct PhoneData
{
	string owner_name;
	string phone_number;
	string tariff_plan;

	PhoneData(const string& owner_name, const string& phone_number, const string& tariff_plan)
		:owner_name(owner_name), phone_number(phone_number), tariff_plan(tariff_plan)
	{}

	friend ostream& operator<<(ostream& os, const PhoneData& pd) {
		os << "Владелец: " << pd.owner_name << ", Телефонный номер: " << pd.phone_number << ", Тарифный план: " << pd.tariff_plan;
		return os;
	}

	bool operator==(const string& other_phone_number) const {
		return this->phone_number == other_phone_number;
	}
	
};

class Tree {
private:
public:
	struct Node {
		PhoneData data;
		int key_value;
		Node* left;
		Node* right;

		Node(const PhoneData& value, int key_value) :data(value), key_value(key_value), left(nullptr), right(nullptr) {}
	};

	Node* root;
	Tree() {
		root = nullptr;
	}


	void Insert(Node*&, const PhoneData&, int key_val);
	void Insert(const PhoneData&, int);
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



	string mostPopularTariff(Node*);
	string mostPopularTariff();

	void countTariffs(Node*, int[]);


};

void Tree::Insert(Node*& node, const PhoneData& value, int key_val) {
	if (node == nullptr) {
		node = new Node(value, key_val);
	}
	else if (key_val == node->key_value) {
		cout << "Ошибка : Узел с таким узлом уже существует! " << endl;
	}
	else if (key_val < node->key_value) {
		Insert(node->left, value, key_val);
	}
	else {
		Insert(node->right, value, key_val);
	}
}

void Tree::Insert(const PhoneData& value, int key_val) {
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

Tree::Node* Tree::Search(Node* root, int key_val) {
	if (root == nullptr || root->key_value == key_val) {
		return root;
	}
	if (root->key_value < key_val) {
		return Search(root->right, key_val);
	}
	return Search(root->left, key_val);
}

Tree::Node* Tree::Search(int key_val) {
	return Search(root, key_val);
}

void Tree::PrintNode(Node* node) {
	if (node != nullptr) { cout << node->data << " "; }
	else { cout << "Элемента с таким ключом не существует!" << endl; }
}

Tree::Node* Tree::FindMin(Node* root) {
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


string Tree::mostPopularTariff(Node* root) {
	const int numTariffs = 3; 
	int counts[numTariffs] = {}; 
	countTariffs(root, counts);
	int maxIndex = 0;
	for (int i = 1; i < numTariffs; i++) {
		if (counts[i] > counts[maxIndex]) {
			maxIndex = i;
		}
	}
	switch (maxIndex) {
	case 0:
		return "Тарифный план A";
	case 1:
		return "Тарифный план B";
	case 2:
		return "Тарифный план C";
	default:
		return "Неизвестный тарифный план";
	}
}

void Tree::countTariffs(Node* node, int counts[]) {
	if (node == nullptr) {
		return;
	}
	// Извлекаем данные из узла
	PhoneData pd = node->data;

	// Увеличиваем значение в массиве для соответствующего тарифного плана
	if (pd.tariff_plan == "A") {
		counts[0]++;
	}
	else if (pd.tariff_plan == "B") {
		counts[1]++;
	}
	else if (pd.tariff_plan == "C") {
		counts[2]++;
	}

	// Рекурсивно обрабатываем левое и правое поддерево
	countTariffs(node->left, counts);
	countTariffs(node->right, counts);
}

string Tree::mostPopularTariff() {
	return mostPopularTariff(root);
}






int menu() {
	int choice;
	cout << endl;
	cout << "1 - Добавить клиента\n";
	cout << "2 - Найти клиента\n";
	cout << "3 - Удалить клиента\n";
	cout << "4 - Вывод всей базы\n";
	cout << "5 - Самый популярный тариф\n";
	cin >> choice;
	cout << "\n";
	return choice;
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("ClientInfo.txt");
	if (!file.is_open()) {
		cerr << "Не удалось открыть файл!" << endl;
		return 1;
	}
	string str;
	string line;
	getline(file, line);

	Tree  phoneTree;

	while (!file.eof()) {
		string key, number, owner, tariff;
		int key_value;
		getline(file, key, '.');
		getline(file, number, ',');
		getline(file, owner, ',');
		getline(file, tariff);
		key_value = stoi(key);
		PhoneData client(owner, number, tariff);
		phoneTree.Insert(client, key_value);
	}

	while (true)
	{
		switch (menu()) {
		case 1: {
			int key;
			string number, owner, tariff;
			cout << "Введите данные о клиенте:" << endl;
			cout << "Введите ключ:";
			cin >> key;
			cout << "Введите имя владельца: ";
			cin.ignore();
			getline(cin, owner);
			cout << "Введите номер телефона владельца: ";
			getline(cin, number);
			cout << "Введите тариф клиента: ";
			getline(cin, tariff);
			PhoneData Inserted_Client(owner, number, tariff);
			phoneTree.Insert(Inserted_Client, key);
			break;
		}
		case 2: {
			int key;
			cout << "Введите ключ: "; cin >> key;
			cout << "Данные: ";
			phoneTree.PrintNode(phoneTree.Search(key));

			break;
		}
		case 3: {
			int remove_key;
			cout << "Введите ключ звена, которого хотите удалить: "; cin >> remove_key;
			phoneTree.Remove(remove_key);
			break;
		}
		case 4: {
			cout << "Бинарное дерево:\n\n";
			phoneTree.Output();
			break;
		}
		case 5: {
			cout << "Самый популярный тариф: " << phoneTree.mostPopularTariff() << endl;
			break;
		}
		case 0: {
			exit(0);
		}
		}
	}
}

