/* 题目描述：给定一个M*N的矩阵，如果某个元素是0，则把该元素对应的行和列全置为0.
 * Date: 2014/7/8
 * Author:赵庶林
 * 思路：
 *    			      （1）开辟2个bool型数组：row[M] column[N]
 *			      （2）用2维数组表示二维矩阵matrix吧呜呜
 *                            （3）遍历矩阵matrix，做标记
 * 			      （4）根据标记，重置矩阵matrix
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_and_reset_0(int **matrix, int M, int N)
//不使用int matrix[][3]这样的形式，是为了保证该函数的可移植性。
//这样做有两个代价，第一个是不能直接使用matrix[i][j]，因为编译器不知道步长是3了。
//每次使用matrix[i][j]，应该人工模拟编译器：*((int*)matrix + i*N + j)
//第二个代价是在main函数往该函数里面传参数时，需要把int matrix[][3]类型强制转换为 （int**）matrix型。 
{
	int i, j, t;
	int row[M], column[N];
	
	if(M <= 0 || N <= 0)
	{
		printf("Error: M <= 0 or N <= 0! Exit...\n");
		exit(EXIT_FAILURE);
	}
	memset(row, 0x00, sizeof(row[0]) * M);
	memset(column, 0x00, sizeof(column[0]) * N);

	//print the origin matrix, only for test. We can ignore these codes.
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			printf("%d ", *((int*)matrix + i*N + j));
		}
		printf("\n");
	}	

	//traverse this matrix and flag row[]&column[] if matrix[i] == 0
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			if(*((int*)matrix + i*N + j) == 0)
			{
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	// according to flags, reset matrix[]
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			if(row[i] || column[j])
				*((int*)matrix + i*N + j) = 0;
		}
	}	

	// No matter what, print it anyway...
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			printf("%d ", *((int*)matrix + i*N + j));
		}
		printf("\n");
	}
	return 0;
}

int main(void)
{
	printf("Testing find_and_reset_0()...\n");
	
	int matrix[][3] = {1, 2, 3, 4, 0, 6};
	find_and_reset_0((int **)matrix, 2, 3);

	int matrix_2[][4] = {1, 0, 3, 0, 5, 6, 7, 8, 9, 0, 10, 11, 12};
	find_and_reset_0((int **)matrix_2, 3, 4);
	return 0;
}
