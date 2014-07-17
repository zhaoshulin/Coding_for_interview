/*
 * 题目描述：用一个数组实现3个栈
 * Author: 赵庶林
 * Date: 2014/07/16
 */

/*
 * 思路：（1）对于push操作：我只需要下一个可用的位置：availabe_index
 *       （2）对于pop操作：我只需要对应的栈的栈顶位置：top_index[i]
 *       （3）为了可以实现多次pop，我只记录top_index不够啊，所以只能为每个结点记录其pre_index
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct node_tag
{
	int data;
	int flag; // 1-> used;  0 -> not used.
	int pre_index;
}node, *node_p;

int available_index;
int top_index[3];
node array[MAX_SIZE];

int stack_init(void)
{
	int i;

	available_index = 0;
	for(i = 0; i < 3; i ++)
	{
		top_index[i] = -1;
	}
	memset(array, 0, sizeof(array));

	return 0;
}

int push(int stack_num, int data)
{
	int i;

	if(stack_num >= 3 || stack_num < 0)
	{
		perror("Usage: 0<= stack_num <= 2.\n");
		exit(EXIT_FAILURE);
	}

	array[available_index].data = data;
	array[available_index].flag = 1;
	array[available_index].pre_index = top_index[stack_num];

	top_index[stack_num] = available_index;

	//find the first available_index from the top of the array
	for(i = 0; i < MAX_SIZE; i ++)
	{
		if(array[i].flag == 0)
		{
			available_index = i;
			break;
		}
	}

	if(i >= MAX_SIZE)
	{
		printf("Out of memory!\n");
		exit(1);
	}

	return 0;
}

int pop(int stack_num)
{
	int pop_data;

	if(stack_num >= 3 || stack_num < 0)
	{
		perror("Usage: 0 <= stack_num <= 2.\n");
		exit(EXIT_FAILURE);
	}
	
	pop_data = array[top_index[stack_num]].data;
	top_index[stack_num] = array[top_index[stack_num]].pre_index;

	return pop_data;
}

int main(void)
{
	printf("testing stack_init...\n");
	stack_init();

	printf("testing push...\n");
	push(0, 1);
	push(0, 2);
	printf("first pop data is %d.\n", pop(0));
	printf("second pop data is %d.\n", pop(0));

	return 0;
}
