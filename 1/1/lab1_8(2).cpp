//#include<iostream>
//
//using namespace std;
//
//void prost(int n, int top, int bottom, int first, ...) {
//	setlocale(LC_ALL, "rus");
//	int* ptr = &first;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (*ptr > bottom && *ptr < top) {
//			cout << *ptr << " ";
//		}
//		ptr += 2;
//	}
//
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	int top, bottom;
//	cout << "������� ����������:" << endl;
//	cout << "��:";
//	cin >> bottom;
//	cout << "��:";
//	cin >> top;
//	prost(3, top, bottom, 7, 5, 6);
//	cout << "������� ����������:" << endl;
//	cout << "��:";
//	cin >> bottom;
//	cout << "��:";
//	cin >> top;
//	prost(4, top, bottom, 2, 5, 7, 10);
//}