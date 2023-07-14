#include<iostream>

using namespace std;

float fun(float x, unsigned int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    return x * fun(x, n - 1) / n;
}

int main() {
    setlocale(LC_ALL, "rus");
    float x = 0; int n = 0;
    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;
    cout << "Ответ: " << fun(x, n-1);

}