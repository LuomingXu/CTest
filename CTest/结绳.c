#include<stdio.h>
#include<time.h>
#include<malloc.h>

void quick_sort(double* s, int left, int right);

clock_t start, finish;
int duration;

int main(int argc, const char* argv[])
{
	

	int i = 0;
	int N = 0;
	double* array;
	double temp;

	//输入
	scanf_s("%d",&N);
	array = (double*)malloc(sizeof(double)*N);
	for ( i = 0; i < N; i++)
	{
		scanf_s("%lf", &array[i]);
	}

	start = clock();

	//从小到大排序
	quick_sort(array,0,N-1);

	//计算及输出
	temp = array[0] / 2 + array[1] / 2;
	for ( i = 2; i < N; i++)
	{
		
		temp = temp / 2 + array[i] / 2;
	}
	printf("%d\n",(int)temp);

	finish = clock();
	duration = (int)(finish - start) / CLOCKS_PER_SEC;
	printf("Time:%.8fms",duration*10000);


	return 0;
}

void quick_sort(double* s, int left, int right)
{
	if (left < right)
	{
		//Swap(s[left], s[(left + right) / 2]); //将中间的这个数和第一个数交换 参见注1  
		int i = left;
		int j = right;
		double x = *(s + left);
		while (i < j)
		{
			while (i < j && *(s + j) >= x) // 从右向左找第一个小于x的数 
				j--;
			if (i < j)
				*(s + (i++)) = *(s + j);
			while (i < j && *(s + i) < x)// 从左向右找第一个大于等于x的数 
				i++;
			if (i < j)
				*(s + (j--)) = *(s + i);
		}
		*(s + i) = x;
		quick_sort(s, left, i - 1); // 递归调用   
		quick_sort(s, i + 1, right);
	}
}
