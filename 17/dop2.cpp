//#include <iostream>
//
//using namespace std;
//
//// ������� ��� ���������� ������ 4 ��������� �� �����������
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
//// ������� ��� ���������� ��������� 4 ��������� �� ��������
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
//    // ���� ��������� �������
//    cout << "������� �������� �������: ";
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//
//    // ���������� ������ 4 ��������� �� �����������
//    sortAscending(arr);
//
//    // ���������� ��������� 4 ��������� �� ��������
//    sortDescending(arr);
//
//    // ����� ���������������� �������
//    cout << "��������������� ������: ";
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
