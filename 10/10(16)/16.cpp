#include <iostream>
using namespace std;

int F(int n, int m) {
    if (n == 0) { 
        return 1;
    }
    else if (n < m) { 
        return -1;
    }
    else { 
        return 2 * F(n - 1, m);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m =  ";
    cin >> m;
    cout << "Ответ: " << F(n, m) << endl;
    return 0;
}