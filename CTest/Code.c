#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

int** askArray(int row, int column);
void freeArray(int** array, int row, int column);
void outputTransposition(int** array, int row, int column);
void inputArray(int** array, int row, int column);

int main(int argc, const char* argv[])
{
	clock_t start, finish;
	double duration;

	int i = 0;
	int j = 0;
	int** array;
	int row = 0;
	int column = 0;

	printf("Please input row and column,use \",\" to differ them\n");
	scanf_s("%d,%d", &row, &column);
	
	array = askArray(row, column);

	inputArray(array, row, column);
	
	start = clock();

	outputTransposition(array, row, column);

	freeArray(array, row, column);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time:%fms\n", duration * 1000);

	system("pause");
	return 0;
}

int** askArray(int row, int column)
{
	int i = 0;
	int** array;

	array = (int**)malloc(sizeof(int*)*row);
	for (i = 0; i < row; i++)
	{
		array[i] = (int*)malloc(sizeof(int)*column);
	}
	return array;
}

void freeArray(int** array, int row, int column)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		free(array[i]);
	}
	free(array);

}

void inputArray(int** array, int row, int column)
{
	int i = 0;
	int j = 0;

	printf("input array\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			scanf_s("%d", &array[i][j]);
		}
	}
}

void outputTransposition(int** array,int row,int column)
{
	int i = 0;
	int j = 0;

	printf("output transposition\n");
	for (i = 0; i < column; i++)
	{
		for (j = 0; j < row; j++)
		{
			printf("%2d", array[j][i]);
		}
		printf("\n");
	}
}