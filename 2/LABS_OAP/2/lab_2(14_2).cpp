//#include<stdio.h>
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#define LENGTH 100
//int main() {
//	setlocale(LC_ALL, "rus");
//	FILE* file;
//	char str[LENGTH];
//	fopen_s(&file, "f.txt", "r");
//	if (file != NULL) {
//		printf("Файл найден для чтения...");
//		fgets(str, LENGTH, file);
//		//fprintf(stdout, "\n%s", str);
//	}
//	else
//	{
//		fprintf(stderr,"Файл для чтения не обнаружен");
//		return 1;
//	}
//	FILE* file_g; char nstr[LENGTH]; int k = 0;
//	fopen_s(&file_g, "g.txt", "w");
//	int flag = 0;
//	for (int i = 0; i < strlen(str)+1; i++)
//	{
//		char temp = str[i];
//		for (int n = 0; n < strlen(str)+1; n++)
//		{
//			if (temp == str[n]) {
//				flag++;
//			}
//		}
//		if (flag == 1) {
//			nstr[k] = str[i];
//			k++;
//		}
//		flag = 0;
//	}
//	fwrite(nstr, strlen(nstr)+1, 1, file_g);
//
//}