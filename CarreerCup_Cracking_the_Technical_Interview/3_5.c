/*
 * 问题描述：用两个栈实现队列。
 * Author：赵庶林
 * Date：2014/08/19
 */

/*
 * 思路：栈可以看为普通的水杯。
 *       左右两个水杯，进队是倒水操作；出队是喝水操作。
 *       （1）只能向右边杯子倒水；
 *       （2）只能从左边杯子喝水；
 *       （3）如果倒水倒得很多，右边杯子都满了，则需要把右边杯子中的水倒入左边杯子中。
 *
 *
 * 所以：(1) enqueue: 1, push right_stack;
 *                    2, if(right_stack is full)
 *                       {
 *				pop right_stack   ---->   left_stack;
 *                       }
 *       (2) dequeue: 1, if(left_stack is empty)
 *           		 {
 *				pop right_stack  ----->  left_stack;
 *           		 }               
 *           	      2, pop left_stack;
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int left_stack[SIZE];
int right_stack[SIZE];

//约定：top指向的是存有有效数据的那一栏。
int ltop = -1;
int rtop = -1;

void enqueue(int data)
{
	int tmp, i;

	if(rtop == SIZE - 1)//full!
	{
		for(i = SIZE - 1; i >= 0; i --)
		{
			tmp = right_stack[i];
			left_stack[++ltop] = tmp;
			if(ltop >= SIZE)
			{
				printf("Out of memory, exit!\n");
				exit(EXIT_FAILURE);
			}
		}
		rtop = 0;
		right_stack[rtop] = data;
		return;
	}

	rtop ++;
	right_stack[rtop] = data;
	return;
}

int dequeue(void)
{
	int i, tmp;

	if(ltop == -1)//empty!
	{
		while(rtop >= 0)
		{
			ltop ++;
			left_stack[ltop] = right_stack[rtop];
			rtop --;
		}
	}	
	
	tmp = left_stack[ltop];
	ltop --;
	return tmp;
}

int main(void)
{
	printf("enqueue testing...\n");
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	enqueue(10);
	printf("rtop = %d; ltop = %d.\n", rtop, ltop);
	enqueue(11);
	printf("rtop = %d; ltop = %d.\n", rtop, ltop);

	printf("dequeue testing...\n");
	printf("dequeue 1st is %d; dequeue 2nd is %d, dequeue 3th is %d.\n", dequeue(), dequeue(), dequeue());
		
	return 0;
}
