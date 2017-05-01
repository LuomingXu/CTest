#pragma once
#ifndef __JUDGE_H__
#define __JUDGE_H__

void Accompany(int** arrayAccompany, int** array, int N, int M);

int judge(int** array, int** arrayAccompany, int M, int N, int tol, int* iJudge, int* jJudge)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int flame = 0;
	int choice = 0;

	//内部，周围全是有八个
	for (i = 1; i < N - 1; i++)
	{
		for (j = 1; j < M - 1; j++)
		{
			if (arrayAccompany[i][j] == -1)
				continue;

			if (array[i][j] - array[i - 1][j - 1] < tol)//1
				continue;
			if (array[i][j] - array[i - 1][j] < tol)//2
				continue;
			if (array[i][j] - array[i - 1][j + 1] < tol)//3
				continue;
			if (array[i][j] - array[i][j - 1] < tol)//4
				continue;
			if (array[i][j] - array[i][j + 1] < tol)//5
				continue;
			if (array[i][j] - array[i + 1][j - 1] < tol)//6
				continue;
			if (array[i][j] - array[i + 1][j] < tol)//7
				continue;
			if (array[i][j] - array[i + 1][j + 1] < tol)//8
				continue;

			flame++;
			if (flame > 1)
				return flame;

			*iJudge = i;
			*jJudge = j;
		}
	}

	return flame;
}

void Accompany(int** arrayAccompany, int** array, int N, int M)
{
	//将有出现次数大于一的数字，将其伴随判断数组变成-1
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int flame = 0;
	int temp = 0;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (*(*(arrayAccompany + i) + j) == -1)
				continue;

			temp = *(*(array + i) + j);

			flame = 0;
			for (k = 0; k < N; k++)
			{
				for (l = 0; l < M; l++)
				{
					if (*(*(arrayAccompany + i) + j) == -1)
						continue;

					if (temp == *(*(array + k) + l))
					{
						flame++;
						if (flame > 1)
						{
							*(*(arrayAccompany + i) + j) = -1;
							*(*(arrayAccompany + k) + l) = -1;
						}
					}

				}
			}

		}
	}
}

#endif // __JUDGE_H__