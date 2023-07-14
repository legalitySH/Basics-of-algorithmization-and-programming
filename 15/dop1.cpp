//#include"HashTwin.h"
//#include"HashTwinFunctions.h"
//
//struct letter {
//	char letter_symbol;
//	int countOfuse;
//};
//
//ostream& operator<<(ostream& os, const letter& lettStruct) {
//	os << "Буква: " << lettStruct.letter_symbol << " Количество вхождений в строку: " << lettStruct.countOfuse;
//	return os;
//}
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	HashTable h(33);
//	int key = 1;
//	char let = 'a';
//	while (let >= 'a' && let <= 'z')
//	{
//		letter newLetter;
//		newLetter.countOfuse = 0;
//		newLetter.letter_symbol = let;
//		h.insert(let, newLetter);
//		let++;
//	}
//	string someStr;
//	cout << "Введите строку: ";
//	getline(cin, someStr);
//
//	for (int i = 0; i < someStr.length(); i++)
//	{
//		h.searchLetters(someStr[i]);
//
//	}
//	h.output();
//
//
//}