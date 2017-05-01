#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<string.h>

clock_t start, finish;
double duration;

int judgePrime(int number);
void prizeFct(int* arrayMembers, int* arraySearch, int N);
void award(char* prize, int memberTemp);

int main(int argc,const char argv[])
{
	int i = 0;
	int N = 0;
	int K = 0;
	int *arrayMembers;
	int *arraySearch;
	char prize[20] = "\0";
	int memberTemp = 0;

	//参赛人员排名输入
	scanf_s("%d", &N);
	arrayMembers = (int*)malloc(sizeof(int)*N);
	for ( i = 0; i < N; i++)
	{
		scanf_s("%d", &arrayMembers[i]);
	}

	//需查询人员输入
	scanf_s("%d", &K);
	arraySearch = (int*)malloc(sizeof(int)*K);
	for (i = 0; i < K; i++)
	{
		scanf_s("%d", &arraySearch[i]);
	}

	start = clock();

	printf("前\n");
	for (i = 0; i < N; i++)
	{
		printf("%d\t", arrayMembers[i]);
		printf("%d\n", arraySearch[i]);

	}
	printf("\n");

	prizeFct(arrayMembers, arraySearch, N);

	printf("后\n");
	for (i = 0; i < N; i++)
	{
		printf("%d\t", arrayMembers[i]);
		printf("%d\n", arraySearch[i]);

	}
	printf("\n");

	for ( i = 0; i < N; i++)
	{
		memberTemp = arraySearch[i];
		award(prize, memberTemp);
		printf("%04d: %s\n", *(arraySearch+i)/10000,prize);
		//虽然对arraySearch的数值精细行了修改，但是只让他打印4位，对读者而言，依旧是真值
	}

	free(arrayMembers);
	free(arraySearch);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf(__FUNCTION__":Time:%fms\n", duration * 10000);

	return 0;
}

void prizeFct(int* arrayMembers, int* arraySearch, int N)
{
	int i = 0;
	int j = 0;
	int l = 0;
	int rank = 0;

	for (i = 0; i < N; i++)
	{
		if (*(arraySearch + i)>9999)
		{
			continue;
		}

		rank = 0;

		for ( j = 0; j < N; j++)
		{
			if (*(arraySearch+i) == *(arrayMembers+j))
			{
				rank = j + 1;
				for ( l = i + 1; l < N; l++)
				{
					if (*(arraySearch + i)==*(arraySearch + l))
					{
						*(arraySearch + l) = *(arraySearch + l) * 10000 + 4;//检查过了
					}
				}
				break;
			}
		}

		if (rank==0)
		{
			*(arraySearch + i) = (*(arraySearch + i)) * 10000 + 5;//不存在的
			continue;
		}

		if (rank == 1)
		{
			*(arraySearch+i) = (*(arraySearch+i)) * 10000 + 1;//第一名
			continue;
		}

		if (judgePrime(rank, N) == 1)
		{
			*(arraySearch+i) = (*(arraySearch+i)) * 10000 + 2;//素数
			continue;
		}
		else
		{
			*(arraySearch+i) = (*(arraySearch+i)) * 10000 + 3;//巧克力
			continue;
		}
	}//for--i
}

void award(char* prize, int memberTemp)
{
	if (memberTemp%10==1)
	{
		strcpy_s(prize, 20, "Mystry Award");
		return;
	}
	else if (memberTemp%10==2)
	{
		strcpy_s(prize, 20, "Minion");
		return;
	}
	else if (memberTemp % 10 == 3)
	{
		strcpy_s(prize, 20, "Chocolate");
		return;
	}
	else if (memberTemp % 10 == 4)
	{
		strcpy_s(prize, 20, "Checked");
		return;
	}
	else if (memberTemp % 10 == 5)
	{
		strcpy_s(prize, 20, "Are you kidding?");
		return;
	}
	return;
}

int judgePrime(int number)
{
	if (number == 2)
	{
		return 1;
	}
	int flag = 1;

	for (int a = 2; a < number; a++)
	{
		if (number%a == 0)
		{
			flag = 0;
			break;
		}
	}

	return flag;
}