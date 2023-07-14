#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h> /* atoi() */
#include <ctype.h> /* isdigit() */

#define XSIZE 4
#define YSIZE 100

int main()
{
	setlocale(0, "");
	int data[YSIZE];
	char tmp[XSIZE];
	char c;
	FILE* a, * b;
	int K, x = 0, y = 0, i = 0, j = 0;

	do {
		printf("¬ведите K (в диапазоне [-99,99]): ");
		scanf("%d", &K);
	} while (K > 99 || K < -99);

	a = fopen("f4.txt", "r");
	while (x < YSIZE && (c = fgetc(a)) != EOF)
	{
		if (isdigit(c) || c == '-')tmp[y++] = c;
		else
		{
			if (y > 0)
			{
				tmp[y] = '\0';
				y = 0;
				data[x] = atoi(tmp);
				x++;
			}
		}
	}
	fclose(a);

	/*#define test1*/
#ifdef test1
	for (int z = 0; z < x; z++)
		printf("%d ", data[z]);
	putchar('\n');
#endif

	b = fopen("g4.txt", "w");
	for (int z = 0; z < x; z++)
	{
		if (data[z] > K)
		{
			fprintf(b, "%d ", data[z]);
		}
	}
	fclose(b);
	//remove("f4.txt");
	return 0;
}