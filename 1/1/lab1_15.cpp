//#include<iostream>
//
//using namespace std;
//
//double fun(double x){
//	return pow(x, 3) + x - 2;
//}
//
//double f(double x) {
//	return sin(x) + 0.3;
//}
//
//double dihotomy(double a, double b,double(*f)(double x)) {
//
//	const double epsilon = 1e-3;
//	double c=0;
//
//	while (b - a > epsilon) {
//		c = (a + b) / 2;
//		if (f(b) * f(c) < 0)
//			a = c;
//		else
//			b = c;
//	}
//
//	return c;
//
//}
//
//int main(){
//	setlocale(LC_ALL, "rus");
//	double(*fpointer)(double a, double b,double(*f)(double x));
//	double bottom = 0, top = 0;
//	cout << "Выберите функцию :" << endl;
//	cout << "1) x^3+x-2" << endl;
//	cout << "2) sin(x) + 0.3" << endl;
//	cout << "3) Выйти из программы" << endl;
//	int choice = 0;
//	cin >> choice;
//	switch (choice)
//	{
//	case 1: {
//		cout << "Введите интервал[a,b]" << endl;
//		cout << "a = "; cin >> bottom;
//		cout << "b = "; cin >> top;
//		fpointer = dihotomy;
//		cout << "x= " << fpointer(bottom, top,fun);
//		break;
//	}
//	case 2: {
//		cout << "Введите интервал[a,b]" << endl;
//		cout << "a = "; cin >> bottom;
//		cout << "b = "; cin >> top;
//		fpointer = dihotomy;
//		if (fpointer(bottom, top,f) == -1) {
//			cout << "\nКорней на заданном промежутке нет.";
//			return 0;
//		}
//		cout << "x= " << fpointer(bottom, top,f);
//		break;
//
//	}
//	case 3: {
//		return 0;
//	}
//	default: {
//		cout << "Ошибочный ввод данных";
//	}
//		break;
//	}
//
//}