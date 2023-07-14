#pragma once
#include"Hash.h"

//template<typename T, typename K>  // unique hash
//int Hash<T, K>::hash(K key_value) {
//    auto h1 = [this](K key_value) {
//        unsigned int hash_value = 0;
//        for (int i = 0; i < sizeof(K); i++)
//        {
//            hash_value = rand() % 20 + hash_value;
//        }
//        return hash_value % maxSize;
//    };
//    auto h2 = [this](K key_value) {
//        return key_value * 4 % maxSize;
//    };
//    auto h3 = [this](K key_value) { return (key_value - 1) % maxSize; };
//    auto h4 = [this](K key_value) { return 15 * key_value % maxSize; };
//    int choice = rand() % 5;
//    int hash_value = 0;
//    switch (choice)
//    {
//    case 1: {
//        hash_value = h1(key_value);
//        break;
//    }
//    case 2: {
//        hash_value = h2(key_value);
//        break;
//    }
//    case 3: {
//        hash_value = h3(key_value);
//        break;
//    }
//    case 4: {
//        hash_value = h4(key_value);
//        break;
//    }
//    default:
//        return hash(key_value);
//    }
//    return hash_value;
//}

// module hash
int Hash::hash(int key) {
    int tableSize = maxSize;
    int hashValue = key % tableSize;
    if (hashValue < 0) {
        hashValue += tableSize;
    }

    return hashValue;
}

//int Hash::hash(int key) {
//    const double A = 0.6180339887499;
//    double fract_part = key * A;
//    int index = static_cast<int>(maxSize * fract_part);
//    return index;
//}

void Hash::insert(int key, const int& data)
{
    int i = 0;
    if (currentSize == maxSize) {
        cout << "Хеш-таблица переполнена!\n";
        return;
    }
    int index = hash(key);
    if (table[index].key == -1) {
        table[index].data = data;
        table[index].key = key;
        currentSize++;
        return;
    }
    while (table[index].key != -1)
    {
        index = (index + 1) % maxSize;
        i++;
        if (i == maxSize)
        {
            cout << "Хеш-таблица переполнена!\n";
            return;
        }
    }

    table[index].data = data;
    table[index].key = key;
    currentSize++;
}


void Hash::output() {

	for (int i = 0; i < maxSize; i++)
	{
		if (table[i].key != -1) {
			cout << "Ключ: " << table[i].key << " Данные: " << table[i].data << endl;
		}
	}
}

void Hash::remove(int key)
{
    int index = 0;
    int i = 1;
    bool found = false;

    while (table[index].key != key && table[index].key != int()) {
        index = (index + 1) % maxSize;
    }

    while (table[index].key == key) {
        table[index].key = -1;
        table[index].data = int();
        currentSize--;
        found = true;
        index = (index + i * i) % maxSize;
        i++;
    }

    if (found) {
        cout << "Элементы с ключом " << key << " удалены!" << endl;
    }
    else {
        cout << "Элементы с ключом " << key << " не найдены!" << endl;
    }
}


void Hash::find(int key) {
    int size = 0;
    int index = hash(key);
    int i = 1;
    while (table[index].key != key && table[index].key != -1) {
        index++;
        if (index == hash(key)) {
            break;
        }
    }

    if (table[index].key == key) {

        /*cout << "Найденные элементы с ключом " << key << ":" << endl;*/
        while (table[index].key == key) {
           /* cout << table[index].data << endl;*/
            size++;
            index = (index + 1) % maxSize;
        }

    }
    else {
       /* cout << "Элементы с ключом " << key << " не найдены!" << endl;*/
    }
}

void Hash::clear() {
    for (int i = 0; i < maxSize; i++) {
        table[i].key = -1;
        table[i].data = int();
    }
    currentSize = 0;
}