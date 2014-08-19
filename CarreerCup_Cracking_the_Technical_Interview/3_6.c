/*
 * 题目描述：写程序将一个栈按升序排序。对这个栈是如何实现的，你不应该做任何特殊的假设。 程序中能用到的栈操作有：push | pop | peek | isEmpty。
 * Author：赵庶林
 * Date：2014/08/19
 */

/*
 * 思路：使用递归。
 *                （1）自定义递归函数sort(stack),作用：升序排序stack；
 *                （2）递归终止条件：stack中只剩下一个元素未处理啦。
 *                步骤：
 *                     1, upper = pop();
 *                     2, if(stack.isEmpty)  push(upper); return;
 *                     3, else
 *                            lower = pop();
 *                            if(upper > lower)
 *                            {
 *					push(upper);
 *					sort(stack);
 *					push(lower);
 *                            }
 *                            else
 *                            {
 *					push(lower);
 *					sort(stack);
 *					push(upper);
 *                            }
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int stack[SIZE];
int top = -1; //约定： top指向的是有效数据的位置。

void push(int data)
{
	top ++;
	if(top >= SIZE)
	{
		printf("Out of memory, exit!\n");
		exit(EXIT_FAILURE);
	}

	stack[top] = data;
}

int pop(void)
{
	if(top < 0 || top >= SIZE)
	{
		printf("Error!\n");
		exit(EXIT_FAILURE);
	}

	top --;
	return stack[(top + 1)];
}

int peep(void)
{
	if(top < 0 || top >= SIZE)
	{
		printf("Error!\n");
		exit(EXIT_FAILURE);
	}
	return stack[top];
}

int isEmpty(void)
{
	if(top == -1)
		return 1;
	else
		return 0;
}

void print(void) //just for test...
{
	int i;
	for(i = 0; i <= top; i ++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void sort(int* stack)
{
	int upper, lower;

	if(isEmpty())
		return;

	upper = pop();
	sort(stack);
	if(isEmpty())
	{
		push(upper);
		return;
	}

	lower = pop();
	if(upper > lower)
	{
		push(upper);
		sort(stack);
		push(lower);
	}
	else
	{
		push(lower);
		sort(stack);
		push(upper);
	}
}

int main(void)
{
	printf("sort testing...\n");
	push(-2);
	push(9);
	push(10);
	push(6);
	push(7);
	push(4);
	push(34);
	push(1);
	printf("Before sorting...\n");
	print();
	sort(stack);
	printf("After sorting...\n");
	print();

	return 0;
}
