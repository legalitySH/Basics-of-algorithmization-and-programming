//// ������� 2
//
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    int size;
//    cout << "������� ���������� ��������� �������: ";
//    cin >> size;
//
//    int* arr = new int[size];
//
//    // ���� ��������� �������
//    cout << "������� �������� �������: ";
//    for (int i = 0; i < size; ++i) {
//        cin >> arr[i];
//    }
//
//    int maxElement = arr[0];
//    int maxIndex = 0;
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] > maxElement) {
//            maxElement = arr[i];
//            maxIndex = i;
//        }
//    }
//
//    int minElement = arr[0];
//    for (int i = 1; i < size; ++i) {
//        if (arr[i] < minElement) {
//            minElement = arr[i];
//        }
//    }
//
//    cout << "������������ �������: " << maxElement << ", ��� �����: " << maxIndex << endl;
//    cout << "����������� �������: " << minElement << endl;
//
//    delete[] arr;
//
//    return 0;
//}
