#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;


int main() {
	FILE* f1;
	FILE* f2;
	FILE* f3;
	FILE* f4;
	errno_t err = fopen_s(&f1, "NameA.txt", "r");
	if (err != NULL) {
		perror("Open error!\n");
		exit(EXIT_FAILURE);
	}
	err = fopen_s(&f2, "NameB.txt", "r");
	if (err != NULL) {
		perror("Open error!\n");
		exit(EXIT_FAILURE);
	}
	err = fopen_s(&f3, "NameC.txt", "r");
	if (err != NULL) {
		perror("Open error!\n");
		exit(EXIT_FAILURE);
	}
	err = fopen_s(&f4, "D.txt", "w");
	if (err != NULL) {
		perror("Open error!\n");
		exit(EXIT_FAILURE);
	}

	int* A = new int[5] {};
	int* B = new int[5] {};
	int* C = new int[5] {};
	int counter = 0;
	while (!feof(f1))
	{
		fscanf_s(f1, "%d ", &A[counter]);
		counter++;
	}
	fclose(f1);
	counter = 0;
	while (!feof(f2))
	{
		fscanf_s(f2, "%d ", &B[counter]);
		counter++;
	}
	fclose(f2);
	counter = 0;
	while (!feof(f3))
	{
		fscanf_s(f3, "%d ", &C[counter]);
		counter++;
	}
	fclose(f3);


	for (int i = 0; i < 5; i++)
	{
		fprintf(f4, "%d ", A[i]);
		fprintf(f4, "%d ", B[i]);
		fprintf(f4, "%d ", C[i]);
	}


}