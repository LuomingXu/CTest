#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<stdlib.h>
#include"Judge.h"

int** askArray(int row, int column);
void freeArray(int** array, int row);

clock_t start, finish;
double duration;


//在数组中找出比周围的数都大tol个数值的数
int main(int argc, const char* agrv[])
{
	int i = 0;
	int j = 0;
	int M = 0;
	int N = 0;
	int tol = 0;
	int flame = 0;
	int iJudge = 0;
	int jJudge = 0;
	int** array;
	int** arrayAccompany;

	scanf_s("%d", &M);
	scanf_s("%d", &N);
	scanf_s("%d", &tol);
	//将数组扩大两个，便于边界的计算，减少代码的复杂性
	//P.S.大神就是聪明...
	N += 2;
	M += 2;

	array = askArray(N, M);
	arrayAccompany = askArray(N, M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			array[i][j] = -999999;
			arrayAccompany[i][j] = 0;
		}
	}

	for ( i = 1; i < N - 1; i++)
	{
		for ( j = 1; j < M - 1; j++)
		{

			scanf_s("%d", &array[i][j]);
		}
	}

	start = clock();

	Accompany(arrayAccompany, array, N, M);

	flame = judge(array, arrayAccompany, M, N, tol, &iJudge, &jJudge);

	switch (flame)
	{
		case 0:
			printf("Not Exist\n");
			break;
		case 1:
			printf("(%d, %d): %d\n", jJudge, iJudge, array[iJudge][jJudge]);
			break;
		default:
			printf("Not Unique\n");
			break;
	}

	freeArray(array, N);
	freeArray(arrayAccompany, N);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf(__FUNCTION__":Time:%fms\n", duration * 10000);

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

void freeArray(int** array, int row)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		free(array[i]);
	}
	free(array);

}