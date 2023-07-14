//#include<iostream>
//using namespace std;
//
//double dopF2_1(double x) {
//    return(pow(x, 3) + (3 * x) - 1);
//}
//double dopF2_2(double x) {
//    return (exp(x) - 4);
//}
//
//void dihotomy(double a, double b, double(*f)(double x)) {
//
//    const double epsilon = 1e-3;
//    double c;
//
//    while (b - a > epsilon) {
//        c = (a + b) / 2;
//        if (f(b) * f(c) < 0)
//            a = c;
//        else
//            b = c;
//    }
//
//    cout << (a + b) / 2 << endl;
//
//}
