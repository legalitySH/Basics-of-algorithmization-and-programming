//#include <iostream>
//
//using namespace std;
//
//// Функция для сортировки первых 4 элементов по возрастанию
//void sortAscending(int arr[]) {
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3 - i; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                int temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// Функция для сортировки последних 4 элементов по убыванию
//void sortDescending(int arr[]) {
//    for (int i = 6; i < 9; ++i) {
//        for (int j = 6; j < 9 - (i - 6); ++j) {
//            if (arr[j] < arr[j + 1]) {
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
//    const int size = 10;
//    int arr[size];
//
//    // Ввод элементов массива
//    cout << "Введите элементы массива: ";
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//
//    // Сортировка первых 4 элементов по возрастанию
//    sortAscending(arr);
//
//    // Сортировка последних 4 элементов по убыванию
//    sortDescending(arr);
//
//    // Вывод отсортированного массива
//    cout << "Отсортированный массив: ";
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
