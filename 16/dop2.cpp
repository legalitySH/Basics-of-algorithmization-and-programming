// //11
//#include<iostream>
//
//using namespace std;
//
//void q_sort(int* arr, int left, int right)
//{
//	int i = left,//����� �������
//		j = right;// ������ �������
//	int pivot = arr[(left + right) / 2]; // ����������� �������
//
//	while (i <= j)
//	{
//		while (arr[i] < pivot) i++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
//		while (arr[j] > pivot) j--;// �������� ������ ������� ���� ������� [right] ������ [pivot]
//
//		if (i <= j)
//		{
//			if (arr[i] > arr[j])
//			{
//				swap(arr[i], arr[j]);
//			}
//
//			i++; j--;
//		}
//
//	};
//	//���������� �������� ���������� ��� ����� � ������ ����� �������
//	if (left < j) q_sort(arr, left, j);
//	if (i < right) q_sort(arr, i, right);
//}
//
//void insertion_sort(int* A, int size)// ���������� ���������
//{
//	int* arr = new int[size];// ������������� ������ ������������� �������
//	for (int i = 0; i < size; i++)
//	{
//		*(arr + i) = *(A + i);
//	}
//	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
//		item;// ����������, �������� � ���� ������ ����������� ��������
//	for (int i = 1; i < size; i++)
//	{
//		temp = arr[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
//		item = i - 1; // ���������� ������ ����������� �������� �������
//		while (item >= 0 && arr[item] > temp) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
//		{
//			arr[item + 1] = arr[item]; // ������������ ��������� �������
//			arr[item] = temp;
//			item--;
//		}
//	}
//	cout << "C = ";
//	for (int i = 0; i < size; i++)//����� ���������������� �������
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	delete[] arr;
//}
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	int aSize;
//	srand(time(0));
//	cout << "������� ������ ������� A ="; cin >> aSize;
//	int* A = new int[aSize];
//	for (int i = 0; i < aSize; i++)
//	{
//		A[i] = (rand() % aSize ) + 1;
//		cout << A[i] << " ";
//	}
//	cout << endl;
//	int bSize;
//	cout << "������� ������ ������� B ="; cin >> bSize;
//	int* B = new int[bSize];
//	for (int i = 0; i < bSize; i++)
//	{
//		B[i] = (rand() % bSize) + 1;
//		cout << B[i] << " ";
//	}
//	cout << endl;
//	int* C = new int[bSize+aSize];
//	int counter = 0;
//	for (int i = 0; i < aSize; i++)
//	{
//		if (A[i] % 2 == 0) {
//			C[counter] = A[i];
//			counter++;
//		}
//	}
//	for (int i = 0; i < bSize; i++)
//	{
//		if (B[i] % 2 != 0)
//		{
//			C[counter] = B[i];
//			counter++;
//		}
//	}
//	for (int i = 0; i < counter; i++)
//	{
//		cout << C[i] << " ";
//	}
//	cout << endl;
//	/*bubble_sort(C, counter);*/
//	q_sort(C, 0 , counter-1);
//}