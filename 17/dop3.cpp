//#include <iostream>
//
//using namespace std;
//
//// Функция для проверки, содержит ли массив заданное число
//bool contains(int arr[], int size, int num) {
//    for (int i = 0; i < size; ++i) {
//        if (arr[i] == num) {
//            return true;
//        }
//    }
//    return false;
//}
//
//// Функция для удаления повторяющихся элементов из массива
//int removeDuplicates(int arr[], int size) {
//    int uniqueCount = 0;
//    int* uniqueArr = new int[size];
//
//    for (int i = 0; i < size; ++i) {
//        if (!contains(uniqueArr, uniqueCount, arr[i])) {
//            uniqueArr[uniqueCount] = arr[i];
//            uniqueCount++;
//        }
//    }
//
//    for (int i = 0; i < uniqueCount; ++i) {
//        arr[i] = uniqueArr[i];
//    }
//
//    delete[] uniqueArr;
//
//    return uniqueCount;
//}
//
//// Функция для сортировки массива по возрастанию
//void sortArray(int arr[], int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    const int size = 15;
//    int arr[size];
//    int validValue;
//    // Ввод элементов массива
//    cout << "Введите элементы массива (числа от -5 до 5): ";
//    for (int i = 0; i < size; ++i) {
//        cin >> validValue;
//        if (validValue < -5 || validValue > 5) {
//            cout << "Ошибка ввода!";
//            return 0;
//        }
//        arr[i] = validValue;
//    }
//
//    // Удаление повторяющихся элементов
//    int uniqueCount = removeDuplicates(arr, size);
//
//    // Сортировка массива по возрастанию
//    sortArray(arr, uniqueCount);
//
//    // Вывод отсортированного массива без повторений
//    cout << "Отсортированный массив без повторений: ";
//    for (int i = 0; i < uniqueCount; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
