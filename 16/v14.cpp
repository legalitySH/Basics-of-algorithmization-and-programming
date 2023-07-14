//#include<iostream>
//
//using namespace std;
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
//			if (arr[j] < arr[j + 1]) // измененное условие
//				swap(arr[j], arr[j + 1]);//функция swap() меняет местами значения двух переменных
//		}
//	}
//	cout << "C = ";
//	for (int i = 0; i < size; i++)//вывод отсортированного массива
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	delete[] arr; // освобождение памяти
//}
//
//void insertion_sort(int* A, int size)// сортировка вставками
//{
//	int* arr = new int[size];// инициализация нового динамического массива
//	for (int i = 0; i < size; i++)
//	{
//		*(arr + i) = *(A + i);
//	}
//	int temp, // временная переменная для хранения значения элемента сортируемого массива
//		item;// переменная, хранящая в себе индекс предыдущего элемента
//	for (int i = 1; i < size; i++)
//	{
//		temp = arr[i]; // инициализируем временную переменную текущим значением элемента массива
//		item = i - 1; // запоминаем индекс предыдущего элемента массива
//		while (item >= 0 && arr[item] < temp) // измененное условие
//		{
//			arr[item + 1] = arr[item]; // перестановка элементов массива
//			arr[item] = temp;
//			item--;
//		}
//	}
//	cout << "C = ";
//	for (int i = 0; i < size; i++)//вывод отсортированного массива
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
//	cout << "Введите размер массива A ="; cin >> aSize;
//	int* A = new int[aSize];
//	for (int i = 0; i < aSize; i++)
//	{
//		A[i] = (rand() % aSize ) + 1;
//		cout << A[i] << " ";
//	}
//	cout << endl;
//	int bSize;
//	cout << "Введите размер массива B ="; cin >> bSize;
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
//	insertion_sort(C, counter);
//}