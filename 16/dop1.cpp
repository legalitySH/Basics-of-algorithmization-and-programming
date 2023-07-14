//// 12
//
//#include<iostream>
//
//using namespace std;
//
//
//void bubble_sort(int* A, int size)//сортировка пузырьком. передается указатель на первый элемент массива и его размер
//{
//	int* arr = new int[size];// инициализация нового динамического массива
//	for (int i = 0; i < size; i++)
//	{
//		*(arr + i) = *(A + i);
//	}
//	for (int i = 0; i < size; i++)// size - 1 необходимо, чтобы не выйти за память, отведенную под массив
//	{
//		for (int j = 0; j < size - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);//функция swap() меняет местами значения двух переменных
//		}
//	}
//	cout << "B = ";
//	for (int i = 0; i < size; i++)//вывод отсортированного массива
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	delete[] arr; // освобождение памяти
//}
//
//void  selection_sort(int* A, int size)// сортировка выбором
//{
//	int* arr = new int[size];// инициализыция нового динамического массива
//	for (int i = 0; i < size; i++)
//	{
//		*(arr + i) = *(A + i);
//	}
//	for (int i = 0; i < size - 1; i++)// size - 1 необходимо, чтобы не выйти за память, отведенную под массив
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (arr[i] > arr[j])
//				swap(arr[i], arr[j]);//функция swap() меняет местами значения двух переменных
//		}
//	}
//	cout << "B = ";
//	for (int i = 0; i < size; i++)//вывод отсортированного массива
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	delete[] arr; // освобождение памяти
//}
//
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	int aSize;
//	cout << "Введите размер массива A = "; cin >> aSize;
//	int* A = new int[aSize];
//	cout << "A = ";
//	for (int i = 0; i < aSize; i++)
//	{
//		A[i] = rand() % aSize;
//		cout << A[i] << " ";
//	}
//	cout << endl;
//	int* B = new int[aSize / 2];
//	int counter = 0;
//	for (int i = 0; i < aSize; i++)
//	{
//		if (i % 2 == 0)
//		{
//			B[counter] = A[i];
//			counter++;
//		}
//	}
//	/*bubble_sort(B, counter);*/
//	selection_sort(B, counter);
//
//}