#include<iostream>
#include<fstream>
#include<string>


using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	ofstream file1("f1.txt");
	string str;
	cout << "¬ведите строку разделЄнную пробелами..." << endl;
	getline(cin, str);
	file1 << str;
	str = "";
	file1.close();
	ifstream file2("f1.txt");
	getline(file2, str);
	file2.close();
	ofstream file("f2.txt");
	cout << "¬ведите позицию k =";
	int k = 0;
	cin >> k;
	string temp;
	for (size_t i = 0; i < k; i++)
	{
		file << str[i];
		temp += str[i];
		
	}
	size_t pos = str.find(temp);
	if (str[k] != ' ') {
		str.replace(pos, temp.length(), "");
		file << str;
	}
	file.close();



}