#pragma once

#include<iostream>
#include<ctime>
#include <chrono>

using namespace std;

class Hash {
public:
    Hash(int size) : currentSize(0), maxSize(size) {
        table = new node[size];
        for (int i = 0; i < maxSize; i++) {
            table[i].key = -1;
        }
    }
    ~Hash() {
        delete[] table;
    }
    void insert(int, const int&);
    void output();
    void remove(int key);
    void find(int key);
    void clear();

private:
    struct node {
        int key;
        int data;
    };
    int currentSize;
    int maxSize;
    node* table;
    int hash(int);
};


