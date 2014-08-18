/*
 * 题目描述：实现一个栈，包含三个方法：push pop min，其中min函数返回栈中的最小值，三个方法的时间复杂度必须是O(1).
 * Author：赵庶林
 * Date：2014/08/14
 */

/*
 * 思路：开辟两个数组：一个用于实现栈，一个用于记录最小值。
 *       最小值数组里面存放的是一个结构体：最小值+引用计数。
 *       每次push新数据，判断：
 *                             if(new < min) then push (new, 1) into min[]
 *                             if(new >= min) then ref ++
 *       每次pop，ref --; 判断ref是否=0了。
 */

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024
#define MAX_DATA 65536

typedef struct minData_tag
{
	int min_data;
	int ref;
}minData, *minData_p;

int data[MAX_SIZE];
minData mindata[MAX_SIZE];
int top = 0;
int data_top = 0;
int current_min = MAX_DATA;

int push(int new)
{
	if(new < current_min || top == 0)
	{
		mindata[top].min_data = new;
		current_min = mindata[top].min_data;
		mindata[top].ref = 1;
		top ++;
	}
	else
	{
		mindata[top].ref ++;
		current_min = mindata[top].min_data;
	}

	data[data_top] = new;
	data_top ++;

	return 0;
}

int pop(void)
{
	mindata[top].ref --;
	if(mindata[top].ref == 0)
	{
		top --;
		current_min = mindata[top].min_data;
	}

	return data[-- data_top];
}

int min(void)
{
	return mindata[top].min_data;
}

int main(void)
{
	printf("push testing...\n");
	push(4);
	push(2);
	push(1);
	push(3);
	push(0);
	push(0);
	int tmp_top = top;
	for(; tmp_top >= 0; tmp_top --)
	{
		printf("min[%d] = %d.\n", tmp_top, mindata[tmp_top].min_data);
	}

	printf("pop testing...\n");
	int pop1 = pop();
	int pop2 = pop();
	int pop3 = pop();
	printf("pop => %d; pop => %d; pop => %d.\n", pop1, pop2, pop3);
	tmp_top = top;
	for(; tmp_top >= 0; tmp_top --)
	{
		printf("min[%d] = %d.\n", tmp_top, mindata[tmp_top].min_data);
	}

	printf("min testing...\n");
	tmp_top = top;
	for(; tmp_top >= 0; tmp_top --)
	{
		printf("min => %d.\n", min());
	}
	return 0;
}
