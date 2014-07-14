/*
 * 题目描述：有一个单链表，但是你不知道它的head，只给你一个结点的指针，而且
 *           这个结点肯定在链表里面粗线。要求你做的是要删除这个结点。无返回值。
 *           比如：原来是a->b->c->d，我给你一个node *b,你捣鼓一通之后要给我
 *           把这个链表变成a->c->d。
 * Author: 赵庶林
 * Date: 2014/07/14
 */

/* 
 * 思路：考虑一个node包含的内容有两个：（1）int data;
 *                                     （2）node * next;
 *       所以，我先把next结点的数据覆盖掉本结点的数据，狸猫换太子之后，我就
 *       可以删除next结点啦！
 *       步骤：（1）根据数组创建单链表；
 *             （2）狸猫换太子+杀人灭口；
 *             （3）销毁单链表。
 *
 * 注意：给定的node *b有可能是：（1）头结点/中间结点 => 正常
 *                              （2）尾结点 => 不可能完成的任务！！！
 *                              （3）NULL => 不用删除，直接返回啦
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node, *node_p;

node * single_list_create(int *a, int n)
{
	node *head, *tail, *new;
	int i;

	head = (node *)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("malloc head error.\n");
		exit(EXIT_FAILURE);
	}

	head -> next = NULL;
	tail = head;

	if(n <= 0)
		return NULL;

	for(i = 0; i < n; i ++)
	{
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
		{
			printf("malloc new error.\n");
			exit(EXIT_FAILURE);
		}

		memset(new, 0x00, sizeof(new));
		new -> next = NULL;

		new -> data = a[i];
		tail -> next = new;
		tail = tail -> next;
		tail -> next = NULL;
	}
	return head;
}

void remove_node(node *b)
{
	node *c;

	if(b == NULL)
		return;

	if(b -> next == NULL)
	{
		printf("I cannot handle tail node, sorry...\n");
		return;
	}

	c = b -> next;
	b -> data = c -> data;
	b -> next = c -> next;
	free(c);

}

int single_list_destory(node *head)
{
	node *pos;
	
	if(head == NULL)
		return 0;

	pos = head -> next;
	while(pos != NULL)
	{
		head -> next = pos -> next;
		free(pos);
		pos = head -> next;
	}
	free(head);
	
	return 0;
}

int main(void)
{
	node *b, *head;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	head = single_list_create(a, 10);
	
	b = (node *)malloc(sizeof(node));
	b -> data = 3;
	b -> next = head -> next -> next -> next;
	
	remove_node(b);
	single_list_destory(head);
	return 0;
}
