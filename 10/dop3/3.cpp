#include <iostream>
using namespace std;

char getChar(int n, int c) {
    if (c == 0) {
        return 'A' + (n - 1) % 26; // ���������� ������ �� n-�� ����� � �������� ��������
    }
    else {
        int m = (n - 1) / 26; // ���������� ����� ������� � �������� ����� ���� c
        return getChar(m, c - 1); // �������� ������� ��� ��������� ������� �� m-�� ����� � �������� ����� ���� c-1
    }
}

int main() {
    int n = 701; // ������ ������� ������
    int c = 26; // ���
    char result = getChar(n, c);
    cout << result << endl; // ������� ������, ������� ����� �� n-�� ����� � �������� ����� ���� c
    return 0;
}