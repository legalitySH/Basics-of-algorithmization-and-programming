#include <iostream>
#include <fstream>
using namespace std;

void generateNumbers(int A, int* arr, int index, ofstream& outfile) {
    if (index == A) {
        for (int i = 0; i < A; i++) {
            outfile << arr[i];
        }
        outfile << endl;
    }
    else {
        for (int i = 1; i <= A; i++) {
            arr[index] = i;
            generateNumbers(A, arr, index + 1, outfile);
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int A;
    cout << "Введите число A = ";
    cin >> A;

    int* arr = new int[A];

    ofstream outfile("numbers.txt");

    generateNumbers(A, arr, 0, outfile);
    cout << "Успешно!" << endl;
    outfile.close();

    delete[] arr;

    return 0;
}