#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

void bubble_sort(int* A, int size)//сортировка пузырьком. передается указатель на первый элемент массива и его размер
{
	int* arr = new int[size];// инициализация нового динамического массива
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	for (int i = 0; i < size; i++)// size - 1 необходимо, чтобы не выйти за память, отведенную под массив
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);//функция swap() меняет местами значения двух переменных
		}
	}
	cout << "A = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // освобождение памяти
}

void сocktail_sort(int* A, int size)//шейкер-сортировка
{
	int* arr = new int[size];// инициализация нового динамического массива
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	bool sort_or_not = true;

	int  right_border, left_border = 0;
	right_border = size - 1;
	do
	{

		//следует два пузырька, один сортирует с начала, другой - с конца
		 //если перестановок не произошло, то массив массив отсортирован, значит, sort_or_not = true - завершение do...while цикла
		sort_or_not = true;
		for (int i = left_border; i < right_border; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				sort_or_not = false;
			}

		}


		for (int i = right_border; i > left_border; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				sort_or_not = false;
			}
		}

		++left_border;
		--right_border;


	} while (sort_or_not == false);

	cout << "B = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void comb_sort(int* A, int size)//сортировка расческой
{
	double factor = 1.2473309;//фактор уменьшения шага
	int step = size - 1;//шаг сортировки
	int* arr = new int[size];// инициализация нового динамического массива
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}

	while (step >= 1)
	{

		for (int i = 0; i + step < size; i++)
		{
			if (arr[i] > arr[i + step])
			{

				swap(arr[i], arr[i + step]);
			}
		}
		step /= factor;
	}
	cout << "C = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}

void insertion_sort(int* A, int size)// сортировка вставками
{
	int* arr = new int[size];// инициализация нового динамического массива
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item;// переменная, хранящая в себе индекс предыдущего элемента
	for (int i = 1; i < size; i++)
	{
		temp = arr[i]; // инициализируем временную переменную текущим значением элемента массива
		item = i - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && arr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arr[item + 1] = arr[item]; // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
	cout << "D = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
}



void  selection_sort(int* A, int size)// сортировка выбором
{
	int* arr = new int[size];// инициализыция нового динамического массива
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = *(A + i);
	}
	for (int i = 0; i < size - 1; i++)// size - 1 необходимо, чтобы не выйти за память, отведенную под массив
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);//функция swap() меняет местами значения двух переменных
		}
	}
	cout << "E = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // освобождение памяти
}

void q_sort(int* arr, int left, int right)
{
	int i = left,//левая граница
		j = right;// правая граница
	int pivot = arr[(left + right) / 2]; // разрешающий элемент

	while (i <= j)
	{
		while (arr[i] < pivot) i++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		while (arr[j] > pivot) j--;// сдвигаем правую границу пока элемент [right] больше [pivot]

		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}

			i++; j--;
		}

	};
	 //Рекурсивно вызываем сортировку для левой и правой части массива
	if (left < j) q_sort(arr, left, j);
	if (i < right) q_sort(arr, i, right);
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL)); // для того, чтобы не поучался один и то же массив
	int size;
	clock_t time_start, time_end;
	double bubble_time, insertion_time, cocktail_time, comb_time, selection_time, qsort_time;
	cout << "Введите количество элементов массива ";
	cin >> size;
	int* arr = new int[size];// в отдельную функцию выносить не нужно
	cout << "arr = ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;// задает диапазон от 1 до 100
		cout << arr[i] << " ";
	}
	cout << endl;
	time_start = clock();
	bubble_sort(arr, size);
	time_end = clock();
	bubble_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;//вычисление времени сортировки

	time_start = clock();
	insertion_sort(arr, size);
	time_end = clock();
	insertion_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	сocktail_sort(arr, size);
	time_end = clock();
	cocktail_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	comb_sort(arr, size);
	time_end = clock();
	comb_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	selection_sort(arr, size);
	time_end = clock();
	selection_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	time_start = clock();
	q_sort(arr, 0, size - 1);
	time_end = clock();
	qsort_time = ((double)time_end - (double)time_start) / (double)CLOCKS_PER_SEC;

	cout << "F = ";
	for (int i = 0; i < size; i++)//вывод отсортированного массива
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // освобождение памяти
	cout << "Время вополнения\nПузырек = " << bubble_time << endl <<
		"Вставки = " << insertion_time << endl << "Шейкер = " << cocktail_time << endl <<
		"Расческа = " << comb_time << endl << "Выбор = " << selection_time <<
		endl << "Быстрая = " << qsort_time;
}