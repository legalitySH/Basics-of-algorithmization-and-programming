#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

void menu()
{
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. ReturnN" << endl;
    cout << "6. Выход" << endl;
    cout << endl;
}

void insert(Address* e, Address** phead, Address** plast)
{
    if (*plast == nullptr) {
        e->next = nullptr;
        e->prev = nullptr;
        *plast = e;
        *phead = e;
    }
    else {
        (*plast)->next = e;
        e->prev = *plast;
        e->next = nullptr;
        *plast = e;
    }
}

Address* setElement()
{
    Address* temp = new Address();
    if (!temp) {
        cerr << "Ошибка выделения памяти" << endl;
        return nullptr;
    }
    cout << "Введите имя: ";
    cin.ignore();
    cin.getline(temp->name, NAME_SIZE - 1);
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE - 1);
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

void outputList(Address** phead, Address** plast)
{
    Address* t = *phead;
    while (t != nullptr) {
        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}

void find(char name[NAME_SIZE], Address** phead)
{
    Address* t = *phead;
    while (t != nullptr) {
        if (!strcmp(name, t->name)) {
            cout << t->name << ' ' << t->city << endl;
            return;
        }
        t = t->next;
    }
    cerr << "Имя не найдено" << endl;
}

void delet(char name[NAME_SIZE], Address** phead, Address** plast)
{
    Address* t = *phead;
    while (t != nullptr) {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (t == nullptr) {
        cerr << "Имя не найдено" << endl;
        return;
    }
    if (*phead == t) {
        *phead = t->next;
        if (*phead != nullptr)
            (*phead)->prev = nullptr;
        else
            *plast = nullptr;
    }
    else {
        t->prev->next = t->next;
        if (t != *plast)
            t->next->prev = t->prev;
        else
            *plast = t->prev;
    }
    delete t;
    cout << "Элемент удален" << endl;
}

void writeToFile(Address** phead) // Запись в файл
{
    Address* t = *phead;
    ofstream fout("mlist.txt", ios::out | ios::binary);
    if (!fout)
    {
        cerr << "Файл не открывается" << endl;
        exit(1);
    }
    cout << "Сохранение в файл" << endl;
    while (t)
    {
        fout.write((char*)t, sizeof(Address));
        t = t->next;
    }
    fout.close();
}

void readFromFile(Address** phead, Address** plast) // Чтение из файла
{
    Address* temp = new Address();
    ifstream fin("mlist.txt", ios::in | ios::binary);
    if (!fin)
    {
        cerr << "Файл не открывается" << endl;
        return;
    }
    while (fin.read((char*)temp, sizeof(Address)))
    {
        insert(temp, phead, plast);
        temp = new Address();
    }
    fin.close();
}

bool ReturnN(Address *&phead) {
    if (phead==NULL) {
        return true;
    }
    return false;
}


int main()
{
    setlocale(LC_ALL, "");
    Address* head = nullptr;
    Address* last = nullptr;
    int choice=0;
    char name[NAME_SIZE];
   ifstream inFile("address.dat", ios::binary);
    if (inFile) {
        while (inFile.peek() != EOF) {
            Address* temp = new Address();
            inFile.read(reinterpret_cast<char*>(temp), sizeof(Address));
            insert(temp, &head, &last);
        }
        inFile.close();
    }

    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            insert(setElement(), &head, &last);
            break;
        case 2:
            cout << "Введите имя: ";
            cin.ignore();
            cin.getline(name, NAME_SIZE - 1);
            delet(name, &head, &last);
            break;
        case 3:
            outputList(&head, &last);
            break;
        case 4:
            cout << "Введите имя: ";
            cin.ignore();
            cin.getline(name, NAME_SIZE - 1);
            find(name, &head);
            break;
        case 5:
            if (ReturnN(head)) {
                cout << "True" << endl;
            }
            else cout << "False" << endl;
        case 6:
            ofstream outFile("address.dat", ios::binary);
            if (outFile) {
                Address* t = head;
                while (t != nullptr) {
                    outFile.write(reinterpret_cast<char*>(t), sizeof(Address));
                    t = t->next;
                }
                outFile.close();
            }
            else
                cerr << "Не удалось открыть файл для записи" << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}