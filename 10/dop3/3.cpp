#include <iostream>
using namespace std;

char getChar(int n, int c) {
    if (c == 0) {
        return 'A' + (n - 1) % 26; // определяем символ на n-ом месте в исходном алфавите
    }
    else {
        int m = (n - 1) / 26; // определяем номер символа в алфавите после шага c
        return getChar(m, c - 1); // вызываем функцию для получения символа на m-ом месте в алфавите после шага c-1
    }
}

int main() {
    int n = 701; // пример входных данных
    int c = 26; // шаг
    char result = getChar(n, c);
    cout << result << endl; // выводим символ, который стоит на n-ом месте в алфавите после шага c
    return 0;
}