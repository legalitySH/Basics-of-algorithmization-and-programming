//#include<stdio.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<cstdlib>
//#include<string>
//#include <iostream>
//
//int main() {
//	setlocale(LC_ALL, "rus");
//	FILE* f1;
//	FILE* f2;
//	fopen_s(&f2, "f2.txt", "w");
//	fopen_s(&f1, "f1.txt", "w");
//	std::string buff;
//	char* c;
//	char tmp[255];
//	for (int i = 0; i < 8; i++)
//	{
//		std::cin.getline(tmp, 255);
//		fprintf(f1, "%s\n", tmp);
//	}
//	fclose(f1);
//	fopen_s(&f1, "f1.txt", "r");
//	int k = 0;
//	printf("¬ведите число k ,с которого будет начинатьс€ программирование...");
//	scanf_s("%d", &k);
//	if (k + 3 > 8) {
//		printf("FAILURE");
//		return EXIT_FAILURE;
//	}
//	int n = 0;
//	char buffer_sentence[255];
//	while (!feof(f1)) {
//		n++;
//		fgets(buffer_sentence, 255, f1);
//		if (n <= k + 3 && n>=k) {
//			fprintf(f2, "%s", buffer_sentence);
//		}
//	}
//	fclose(f2);
//}