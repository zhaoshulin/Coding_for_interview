/* 题目描述：给定一个单链表，返回倒数第n个元素。
 * Author: 赵庶林
 * Date: 2014/07/14
 */

/*
 * 思路：使用两个指针，它俩之间相隔的距离是（n-1），那么当后指针到达tail的
 *       时候，此时前一个指针正好指向倒数第n个。
 *       步骤如下：
 *                 （1）给定一个数组，尾插法构建一个单链表；
 *                 （2）遍历一遍单链表，时间复杂度O(n)；
 *                 （3）返回元素内容。
 *                 （4）销毁该链表。
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
		printf("Error when malloc memory for head! Exit...\n");
		exit(EXIT_FAILURE);
	}
	head->next = NULL;
	tail = head;

	if(n <= 0)
		return NULL;

	for(i = 0; i < n; i ++)
	{
		new = (node *)malloc(sizeof(node));
		if(new == NULL)
		{
			printf("Error when malloc memory for new node! Exit...\n");
			exit(EXIT_FAILURE);
		}
		memset(new, 0x00, sizeof(new));
		new->next = NULL;

		new->data = a[i];
		tail->next = new;
	        tail = tail->next;
 		tail->next = NULL;		
	}
	return head;
}

int print_last_nth_data(node *head, int n)
{
	int i;
	node *pos, *pre;

	if(head == NULL || n <= 0)
	{
		printf("Error input in print_last_nth_data...\n");
		exit(EXIT_FAILURE);
	}

	i = 0;
	pos = head -> next;
	pre = head -> next;
	while(pos != NULL)
	{
		i ++;
		pos = pos -> next;
		if(i > n)
			pre = pre -> next;	
	}
	return(pre -> data);
}

int single_list_destroy(node *head)
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
	node *list;

	printf("testing single_list_create...\n");
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list = single_list_create(a, 10);

	printf("testing print_last_nth_data...\n");
	printf("The last 4th data is %d.\n", print_last_nth_data(list, 4));
	printf("The last 1th data is %d.\n", print_last_nth_data(list, 1));
	printf("The last 10th data is %d.\n", print_last_nth_data(list, 10));
	
	single_list_destroy(list);
	return 0;
}
