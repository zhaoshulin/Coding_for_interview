/*
 * 题目描述：一个图像是NxN矩阵，每个像素4B，原地旋转90度。
 * Author: 赵庶林
 * Date：2014/7/2
 * 思路：分为两步：（1）求转置矩阵
 *                 （2）逆排列 => 逆时针旋转； 逆排行 => 顺时针旋转
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//因为c语言中没有多维数组的概念，所以我决定用一维数组表示二维数组，一劳永逸。

int get_value(int matrix[], int i, int j)//此函数的功能是返回matrix[i][j]的值
{
	int len;
	int N;

	if(i < 0 || j < 0)
	{
		printf("Error input!\n");
		exit(EXIT_FAILURE);
	}

	for(len = 0; matrix[len] != '\0'; len ++);
	len -- ;

	for(N = 0; N*N < len; N ++);

	if(N*N > len)
	{
		printf("Error in get_value()! Exit!\n");
		exit(EXIT_FAILURE);
	}

	if (N*N == len)
		return *(matrix + i*N + j);	
//	printf("addr is: %p.\n", matrix + i*N + j);
//	printf("value is: %d.\n", *(matrix + i*N + j));
	exit(EXIT_FAILURE); // should never goto this line!
}

int print_matrix(int *matrix)
{
	int len, N, i, j;
	for(len = 0; matrix[len] != '\0'; len ++);
	len --;
	
	for(N = 0; N*N < len; N ++);

	for(i = 0; i < N; i ++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%d ", get_value(matrix, i, j));
		}
		printf("\n");
	}	
	
	return 0;
}

int rotate_90(int * matrix)
{
	int len, N, t, i, j, m, n;
	
	for(len = 0; matrix[len] != '\0'; len ++);
	len --;
	
	for(N = 0; N*N < len; N ++);
	printf("len is %d, N is %d.\n", len, N);

	//求转置开始
	for(t = 0; t < len; t ++)
	{
		i = t / N;
		j = t % N;
		if(i < j)
		{
			m = get_value(matrix, i, j);
			n = get_value(matrix, j, i);
			matrix[j*N+i] = m;
			matrix[i*N+j] = n;
		}
	}//求转置结束

	//逆排列开始
	for(j = 0; j < N/2; j ++)
	{
		for(i = 0; i < N; i ++)
		{
			m = get_value(matrix, i, j);
			n = get_value(matrix, i, N-1-j);
			matrix[i*N+N-1-j] = m;
			matrix[i*N+j] = n;
		}
	
	}//逆排列结束
	

		
	return 0;
} 

int main(void)
{
	printf("Testing matrix...\n");
	int matrix[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_matrix(matrix);
	printf("\n");
	rotate_90(matrix);
	print_matrix(matrix);
	
//	printf("\n");
//	int matrix_2[4] = {1, 2, 3, 4};
//	print_matrix(matrix_2);
//	printf("\n");
//	rotate_90(matrix_2);
//	print_matrix(matrix_2);
	
	return 0;
}
