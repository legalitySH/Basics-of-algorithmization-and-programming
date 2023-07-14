#include <iostream>
using namespace std;

char getChar(int n, int step,char letter) {
    if (step == 0) {
        return letter + n % n;
    }
    else {
        int m = (n - 1) / 26 + 1;
        return getChar(m, step - 1,letter);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n = 12, step = 0; char letter;
    cout << "¬ведите количество шагов ="; cin >> step;
    cout << "¬ведите букву относительно которой введЄтс€ счЄт = "; cin >> letter;
        if (!isalpha(letter)) {
            cout << "ќшибка ввода!" << endl;
            return 0;
        }
    char result = getChar(n, step,letter);
    cout <<"ќтвет:" << char(result+1) << endl; 
    return 0;
}