#include <iostream>
#include <fstream>
#include<string>

using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int data[MAX_SIZE]{};
    int top; 

    Stack() { 
        top = -1;
    }

    bool isFull() { 
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() { 
        return top == -1;
    }

    void push(int value) { 
        if (!isFull()) {
            top++;
            data[top] = value;
        }
        else {
            cout << "���� ����������" << endl;
        }
    }

    int pop() { 
        if (!isEmpty()) {
            int value = data[top];
            top--;
            return value;
        }
        else {
            cout << "���� ����������" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return data[top];
        }
        else {
            cout << "���� ������!" << endl;
            return -1;
        }
    }
};

int main() {
    setlocale(0, "");
    ifstream file("input.txt"); 
    Stack stack;
    int shortest_length = -1;
    int shortest_number = -1;

    if (file.is_open()) { 
        string line;

        while (getline(file, line)) { 
            int length = line.length();
            stack.push(length); 

            if (shortest_length == -1 || length < shortest_length) { 
                shortest_length = length;
                shortest_number = stack.top; 
            }
        }

        file.close(); 
    }
    else {
        cout << "������ �������� �����!" << endl;
        return 1;
    }

    cout << "���������� ����� : " << endl;

    while (!stack.isEmpty()) { 
        cout << stack.pop() << endl;
    }

    cout << "����� ������� ������ ��� ������� " << shortest_number+1 << " , �����: " << shortest_length << endl;

    return 0;
}
