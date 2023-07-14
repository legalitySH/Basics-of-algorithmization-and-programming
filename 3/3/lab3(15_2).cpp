//#include<iostream>
//#include<fstream>
//#include <string>
//
//using namespace std;
//
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	string str;
//	cout << "¬ведите строку,состо€щую из слов, разделЄнных пробелами..." << endl;
//	getline(cin, str);
//	ofstream fin("f1.txt");
//	fin << str;
//	str = "";
//	fin.close();
//	string x = "x";
//	ifstream fout("f1.txt");
//	while (!fout.eof()) {
//		fout >> str;
//		if (str.find(x)!=-1)
//		{
//			cout << str << endl;
//		}
//	}
//	
//	fout.close();
//
//}