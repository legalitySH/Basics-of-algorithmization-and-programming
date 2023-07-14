///*
//e^x + x^4,
//x2 – 4
//*/
//#include<iostream>
//using namespace std;
//double e = 0.001;
//double fun(float x){
//	return pow(x,3)+2*x-4;
//	
//}
//double f(double x) {
//
//	return pow(x,2)-1;
//}
//double dih(double a, double b) { // функции осуществления дихотомии
//	float x = a;
//	if (fun(a) * fun(b) >= 0) { // предусмотрение ошибочного ввода данных
//		return  -1;
//	}
//	while (b-a>e)
//	{
//		x = (a + b) / 2;
//		if (fun(x) == 0) {
//			break;
//		}
//		else if (fun(x) * fun(a) < 0) {
//			b = x;
//		}
//		else
//		{
//			a = x;
//		}
//	}
//	return x;
//}
//double dih_2(double a, double b) {
//	double x = a;
//	if (f(a) * f(b) >= 0) {
//		return  -1;
//	}
//	while (b - a > e)
//	{
//		x = (a + b) / 2;
//		if (f(x) == 0) {
//			break;
//		}
//		else if (f(x) * f(a) < 0) {
//			b = x;
//		}
//		else
//		{
//			a = x;
//		}
//	}
//	return x;
//}
//int main(){
//	setlocale(LC_ALL, "rus");
//	double(*fpointer)(double a, double b); // инициализация указателя на функцию
//	double bottom = 0, top = 0; // инициализация пределов интегрирования
//	cout << "Выберите функцию :" << endl;
//	cout << "1) x^3+2*x-4" << endl;
//	cout << "2) x^2-1;" << endl;
//	cout << "3) Выйти из программы" << endl;
//	int choice = 0;
//	cin >> choice;
//	switch (choice)
//	{
//	case 1: {
//		cout << "Введите интервал[a,b]" << endl;
//		cout << "a = "; cin >> bottom; 
//		cout << "b = "; cin >> top;
//		fpointer = dih;
//		if (fpointer(bottom, top) == -1) {
//			cout << "\nКорней на заданном промежутке нет.";
//			return 0;
//		}
//		cout << "x= " << fpointer(bottom, top); // Вызов указательной функции
//		break;
//	}
//	case 2: {
//		cout << "Введите интервал[a,b]" << endl;
//		cout << "a = "; cin >> bottom;
//		cout << "b = "; cin >> top;
//		fpointer = dih_2;
//		if (fpointer(bottom, top) == -1) {
//			cout << "\nКорней на заданном промежутке нет.";
//			return 0;
//		}
//		cout << "x= " << fpointer(bottom, top);
//		break;
//
//	}
//	case 3: {
//		return 0;
//	}
//	default: {
//		cout << "Ошибочный ввод данных"; // Предусмотрение ошибочного ввода данных
//	}
//		break;
//	}
//
//}