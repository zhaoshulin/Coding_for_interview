/*
 * 题目描述：给定两个链表：3->1->5和5->9->2，相加得到8->0->8.实现这个算法。
 * Author: 赵庶林
 * Date: 2014/07/14
 */

/*
 * 思路：同步遍历a和b，根据a和b的数据得到新链表c的数据。
 * 步骤：（1）根据数组构造链表；
 *       （2）同步遍历a和b，如果a和b都是NULL，返回NULL；
 *                          如果a是NULL，b不是，返回b；
 *                          如果a不是NULL，b是，返回a；
 *                          如果遍历过程中a->next是NULL了，把b剩余的部分复制到c中。
 *        （3）打印出链表；
 *        （4）销毁链表。
 */

#include <stdlib.h>
#include <stdio.h>
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
		printf("malloc head error\n");
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
			printf("malloc new node error");
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

int print_single_list(node *head)
{
	node *pos;

	if(head == NULL)
	{
		printf("\n");
		return 0;
	}

	pos = head -> next;
	while(pos != NULL)
	{
		printf("%d ", pos->data);
		pos = pos -> next;
	}
	printf("\n");
	return 0;
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

node *add_two_list(node *head1, node *head2)
{
	node *a, *b, *new, *head, *tail;
	int carry;

	if(head1 == NULL && head2 == NULL)
		return NULL;

	if(head1 == NULL && head2 != NULL)
		return head2;

	if(head1 != NULL && head2 == NULL)
		return head1;


	head = (node *)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("malloc head error.\n");
		exit(EXIT_FAILURE);
	}
	memset(head, 0x00, sizeof(head));
	head -> next = NULL;

	carry = 0;
	a = head1 -> next;
	b = head2 -> next;
	tail = head;
	while(a != NULL && b != NULL)
	{
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
		{
			printf("malloc new node error\n");
			exit(EXIT_FAILURE);
		}
		memset(new, 0x00, sizeof(new));
		new -> next = NULL;

		new -> data = (a->data + b->data + carry) % 10;
		tail -> next = new;
		tail = new;
		tail -> next = NULL;

		carry = (a->data + b->data) / 10;

		a = a -> next;
		b = b -> next;
	}

	if(a == NULL && b == NULL && carry > 0)
	{
		new = (node *)malloc(sizeof(node));
		memset(new, 0x00, sizeof(new));
		new -> next = NULL;
		
		new -> data = carry;
		tail -> next = new;
		tail = new;
		tail -> next = NULL;

	}

	if(a != NULL && b == NULL)
	{
		while(a != NULL)
		{
			new = (node *)malloc(sizeof(node));
			memset(new, 0x00, sizeof(new));
			new -> next = NULL;

			if(carry > 0)
			{
				new -> data = a -> data + carry;
				carry = 0;
			}

			else
			{
				new -> data = a -> data;
			}

			tail -> next = new;
			tail =  new;
			tail -> next = NULL;

			a = a -> next;

		}
	}

	if(a == NULL && b != NULL)
	{
		while(b != NULL)
		{
			new = (node *)malloc(sizeof(node));
			memset(new, 0x00, sizeof(new));
			new -> next = NULL;

			if(carry > 0)
			{
				new -> data = b -> data + carry;
				carry = 0;
			}
			else
			{
				new -> data = b -> data;
			}
			tail -> next = new;
			tail = new;
			tail -> next = NULL;

			b = b -> next;
		}

	}
	
	return head;	
}

int main(void)
{	
	node *add1, *add2, *sum;

	int a[] = {8, 2, 7};
	add1 = single_list_create(a, 3);
	print_single_list(add1);

	int b[] = {2, 2, 3};
	add2 = single_list_create(b, 3);
	print_single_list(add2);

	sum = add_two_list(add1, add2);
	print_single_list(sum);
	single_list_destory(add1);
	single_list_destory(add2);
	single_list_destory(sum);


	return 0;
}
