#include <iostream>
#include <Windows.h>

struct Node {
    int key;
    bool color;
    Node* left;
    Node* right;
    Node* parent;
};

class RedBlackTree {
public:
    
    RedBlackTree() {
        root = nullptr;
    }

    void add(int key) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->color = true;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;
        insert(newNode);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    void print() {
        print(root, "", true);
    }

    void findMinRedPath() {
        Node* minPathEnd = findMinRedPath(root);
        std::cout << "Минимальный путь " << minPathEnd->key ;
        printPathToRoot(minPathEnd);
        std::cout << std::endl;
    }


    Node* root;

    void insert(Node* newNode) {
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (newNode->key < x->key) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        newNode->parent = y;
        if (y == nullptr) {
            root = newNode;
        }
        else if (newNode->key < y->key) {
            y->left = newNode;
        }
        else {
            y->right = newNode;
        }
        fixInsert(newNode);
    }

    void fixInsert(Node* newNode) {
        while (newNode->parent != nullptr && newNode->parent->color == true) {
            if (newNode->parent == newNode->parent->parent->left) {
                Node* uncle = newNode->parent->parent->right;
                if (uncle != nullptr && uncle->color == true) {
                    newNode->parent->color = false;
                    uncle->color = false;
                    newNode->parent->parent->color = true;
                    newNode = newNode->parent->parent;
                }
                else {
                    if (newNode == newNode->parent->right) {
                        newNode = newNode->parent;
                        rotateLeft(newNode);
                    }
                    newNode->parent->color = false;
                    newNode->parent->parent->color = true;
                    rotateRight(newNode->parent->parent);
                }
            }
            else {
                Node* uncle = newNode->parent->parent->left;
                if (uncle != nullptr && uncle->color == true) {
                    newNode->parent->color = false;
                    uncle->color = false;
                    newNode->parent->parent->color = true;
                    newNode = newNode->parent->parent;
                }
                else {
                    if (newNode == newNode->parent->left) {
                        newNode = newNode->parent;
                        rotateRight(newNode);
                    }
                    newNode->parent->color = false;
                    newNode->parent->parent->color = true;
                    rotateLeft(newNode->parent->parent);
                }
            }
        }
        root->color = false;
    }

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left != nullptr) {
            rightChild->left->parent = node;
        }
        rightChild->parent = node->parent;
        if (node->parent == nullptr) {
            root = rightChild;
        }
        else if (node == node->parent->left) {
            node->parent->left = rightChild;
        }
        else {
            node->parent->right = rightChild;
        }
        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;
        if (leftChild->right != nullptr) {
            leftChild->right->parent = node;
        }
        leftChild->parent = node->parent;
        if (node->parent == nullptr) {
            root = leftChild;
        }
        else if (node == node->parent->right) {
            node->parent->right = leftChild;
        }
        else {
            node->parent->left = leftChild;
        }
        leftChild->right = node;
        node->parent = leftChild;
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void print(Node* node, std::string prefix, bool isLast) {
        if (node != nullptr) {
            std::cout << prefix;
            if (isLast) {
                std::cout << "|__";
                prefix += "   ";
            }
            else {
                std::cout << "|--";
                prefix += "|  ";
            }
            std::cout << (node->color ? "\033[1;31m" : "") << node->key << (node->color ? "\033[0m" : "") << std::endl;
            print(node->left, prefix, false);
            print(node->right, prefix, true);
        }
    }

    Node* findMinRedPath(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (node->color == true) {
            Node* leftMinPathEnd = findMinRedPath(node->left);
            Node* rightMinPathEnd = findMinRedPath(node->right);
            if (leftMinPathEnd == nullptr && rightMinPathEnd == nullptr) {
                return node;
            }
            else if (leftMinPathEnd == nullptr) {
                return rightMinPathEnd;
            }
            else if (rightMinPathEnd == nullptr) {
                return leftMinPathEnd;
            }
            else {
                return (leftMinPathEnd->key < rightMinPathEnd->key ? leftMinPathEnd : rightMinPathEnd);
            }
        }
        else {
            Node* leftMinPathEnd = findMinRedPath(node->left);
            Node* rightMinPathEnd = findMinRedPath(node->right);
            return (leftMinPathEnd->key < rightMinPathEnd->key ? leftMinPathEnd : rightMinPathEnd);
        }
    }

    void printPathToRoot(Node* node) {
        if (node != nullptr) {
            printPathToRoot(node->parent);
            std::cout << (node->color ? "\033[1;31m" : "") << node->key << (node->color ? "\033[0m" : "") << " ";
        }
    }
    Node* getRoot() {
        return root;
    }




    void searchForMinRedPath(Node* node, int current_red_count, int& min_red_count) {
        if (node == NULL) {
            return;
        }
        if (node->color == true) {
            current_red_count++;
        }

        if (node->left == NULL && node->right == NULL) {
            if (current_red_count < min_red_count) {
                min_red_count = current_red_count;
            }
            return;
        }

        searchForMinRedPath(node->left, current_red_count, min_red_count);
        searchForMinRedPath(node->right, current_red_count, min_red_count);
    }

    int minRedPath(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int min_red_count = INT_MAX;
        int current_red_count = 0;

        searchForMinRedPath(root, current_red_count, min_red_count);

        return min_red_count;
    }



    

};


int min_red_path_len = 1e9;
int min_red_path[100];

void dfs(Node* node, int* path, int path_len, int red_count) {
    if (node == nullptr) {
        return;
    }
    path[path_len++] = node->key;
    if (!node->left && !node->right) {
        if (red_count < min_red_path_len) {
            min_red_path_len = red_count;
            for (int i = 0; i < path_len; ++i) {
                min_red_path[i] = path[i];
            }
        }
    }
    if (node->left) {
        dfs(node->left, path, path_len, red_count + node->left->color);
    }
    if (node->right) {
        dfs(node->right, path, path_len, red_count + node->right->color);
    }
}

int main() {

    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    RedBlackTree tree;
    int choice;
    do {
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Очистить дерево" << std::endl;
        std::cout << "3. Вывод дерева" << std::endl;
        std::cout << "4. Найти минимальный красный путь" << std::endl;
        std::cout << "5. Вызод" << std::endl;
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            std::cout << "Введите ключ: ";
            std::cin >> key;
            tree.add(key);
            std::cout << "Элемент добавлен." << std::endl;
            break;
        }
        case 2: {
            tree.clear();
            std::cout << "Дерево очищено." << std::endl;
            break;
        }
        case 3: {
            tree.print();
            break;
        }
        case 4: {
            
            int path[100];
            dfs(tree.getRoot(), path, 0, (tree.getRoot())->color);
            std::cout << "Длина: " << min_red_path_len << std::endl;
            std::cout << "Путь: ";
            for (int i = 0; i < min_red_path_len; ++i) {
                std::cout << min_red_path[i] << " ";
            }
            break;

        }
        case 5: {
            std::cout << "Выход..." << std::endl;
            break;
        }
        default: {
            std::cout << "Некорректный выбор." << std::endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}
