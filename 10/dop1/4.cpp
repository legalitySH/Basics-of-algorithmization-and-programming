// 4

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void permute(int arr[], int n, int i) {
    if (i == n) {
        printArray(arr, n);
    }
    else {
        for (int j = i; j < n; j++) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            permute(arr, n, i + 1);
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    permute(arr, n, 0);
    return 0;
}