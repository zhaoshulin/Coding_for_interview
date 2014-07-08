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

int find_and_reset_0(int (*matrix)[3], int M, int N)
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
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}	

	//traverse this matrix and flag row[]&column[] if matrix[i] == 0
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			if(matrix[i][j] == 0)
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
				matrix[i][j] = 0;
		}
	}	

	// No matter what, print it anyway...
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < N; j ++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main(void)
{
	printf("Testing find_and_reset_0()...\n");
	
	int matrix[][3] = {1, 2, 3, 4, 0, 6};
	find_and_reset_0(matrix, 2, 3);
	return 0;
}
