/*
 * 题目：栈就像叠盘子，当盘子叠得太高时，就会倾斜倒下。因此，在真实的世界中，当一叠盘子 (栈)超过了一定的高度时，我们就会另起一堆，再从头叠起。
 * 	 实现数据结构SetOfStacks 来模拟这种情况。SetOfStacks由几个栈组成，当前一栈超出容量时，需要创建一个新的栈 来存放数据。
 * 	 SetOfStacks.push()和SetOfStacks.pop()的行为应当和只有一个栈时 表现的一样。
 * 	 进一步地，实现函数popAt(int index)在指定的子栈上进行pop操作。
 *
 * Author：赵庶林
 * Date：2014/08/18
 */


/*
 * 约定：栈顶指针top指向的是有数据的那一栏！
 *       last指针指向的是最右边的那个栈。
 * 思路： (1) push: if(top == MAX-1)说明已经满了，new stack; last ++; top = 0; stack[top] = push_data;
 *                  else: 说明还没满，top ++; stack[top] = push_data;
 *       （2）pop: if(top == 0) 说明要空了，tmp = stack[top]; last --; top = MAX-1; return tmp;
 *                 else: 说明还没空呢，tmp = stack[top]; top --; return tmp;
 *       （3）popAt(index): 
 *                        1，入参检查；
 *                        2，if(index == last)  return pop();
 *                        3，tmp = stacks[index][MAX-1];
 *                        4，重新赋值：stacks[index][MAX-1] = stacks[index+1][0];
 *                        5，判断是否右边那个已空：if((last == index + 1) && (top == 0))   last --; top = MAX - 1; return tmp;
 *                        6，左移;
 *                        7，return tmp;
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define MAX_SIZE 1024

//int (*stacks)[MAX] = (int ((*)[MAX]))malloc(MAX_SIZE * MAX * sizeof(int));
int stacks[][MAX];
int last = 0;
int top = -1;
int tmp;

int push(int push_data)
{
	if(top == MAX - 1)
	{
		last ++;
		top = 0;
		stacks[last][top] = push_data;
	}
	else
	{
		top ++;
		stacks[last][top] = push_data;
	}

	return 0;
}

int pop(void)
{
	if(top == 0)
	{
		tmp = stacks[last][top];
		last --;
		top = MAX - 1;
		return tmp;	
	}

	else
	{
		tmp = stacks[last][top];
		top --;
		return tmp;
	}
}

int popAt(int index)
{
	int i, j;

	if(index < 0 || index > last)
	{
		printf("Usage: 0 <= index <= last!\n");
		exit(EXIT_FAILURE);
	}

	if(index == last)
		return pop();

	tmp = stacks[index][MAX - 1];

	stacks[index][MAX-1] = stacks[index+1][0];

	if((last == index + 1) && (top == 0))
	{
		last --;
		top = MAX - 1;
	}

	//left moving
	for(i = index + 1; i < last; i ++)
	{
		for(j = 1; j <= MAX - 1; j ++)
		{	
			stacks[i][j-1] = stacks[i][j];
		}
	}

	for(j = 1; j <= top; j ++)
	{
		stacks[last][j-1] = stacks[last][j];
		top --;
	}

	return tmp;
}

int main(void)
{
	printf("push testing...\n");
	push(0);
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	printf("last = %d.\n", last);
	push(10);
	printf("last = %d.\n", last);

	printf("pop testing...\n");
	printf("pop = %d.\n", pop());
	printf("last = %d.\n", last);


	printf("popAt testing...\n");
	push(10);
	push(11);
	printf("popAt(0) = %d.\n", popAt(0));
	printf("popAt(1) = %d.\n", popAt(1));

	return 0;
}
