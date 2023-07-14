#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	ofstream fout("F1.txt");
	string str;
	cout << "¬ведите строку:" << endl;
	getline(cin,str);
	fout << str;
	fout.close();
	ifstream f1("F1.txt");
	int k = 0;
	cout << "¬ведите число k" << endl;
	cin >> k;
	string temp;
	str = "";
	while (!f1.eof()) {
		f1 >> temp;
		str += temp;
		str += " ";
	}
	if (str[k-1] != ' ') {
		cout << str[k-1];

	}
	else
	{
		k = k - 1;
		temp = "";
		str = "";
		f1.seekg(0);
		int counter = 0;
		while (!f1.eof()) {
			f1 >> temp;
			str += temp;
			if (str.length() > k) {
				cout << counter << endl;
				return 0;
			}
			counter++;
		}
	}
}