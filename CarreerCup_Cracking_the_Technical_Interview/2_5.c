/*
 * 题目描述：给你一个链表的head，比如a->b->c->d->e->c，这里面有环吧，让你写一个
 *           算法给出这个环的开始结点（上例是node *c）。
 * Author: 赵庶林
 * Date:/2014/07/15
 */

/*
 * 思路：（1）两个指针，fast和slow，slow的步长是1，fast的步长是2，都从head
 *            处开始起跑，当两者相遇时，环的元素个数N = slow目前走过的步数；
 *       （2）然后，定义第三个指针slow2从head开始，步长是1，slow与slow2同时走，
 *            它们两个相遇的结点位置就是所求。           
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node, *node_p;

node * list_create(int *a, int n, int k)//前0到(k-1)个是非环，后面开始是环
{
	node *head, *new, *tail,  *pos;// pos用于记录环开始的地方，使得tail指向它即可
	int i;

	head = (node *)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("malloc head error\n");
		exit(EXIT_FAILURE);
	}
	memset(head, 0x00, sizeof(head));
	head -> next = NULL;
	
	tail = head;

	if(n <= 0)
	{
		return NULL;
	}

	if(k > n)
	{
		printf("error: k > n.\n");
		exit(EXIT_FAILURE);
	}

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

		if(i == k)
		{
			pos = new;//记录下该位置！
		}

		tail -> next = new;
		tail = new;
		tail -> next = NULL;

		if(i == (n-1))
		{
			tail -> next = pos;
		}
	}
	return head;
}

int print_list(node* head)//just for test, you can ignore this func.
{
	int i;
	node * pos;
	pos = head -> next;
	i = 0;

	while(pos != NULL && i < 100)
	{
		printf("%d ", pos -> data);
		pos = pos -> next;
		i ++; // for count
	}
	printf("\n\n");
	return 0;
}

node *find_first_loop_node(node *head)
{
	node *fast, *slow, *slow2;

	if(head == NULL)
		return NULL;

	fast = head -> next;
	slow = head -> next;
	slow2 = head -> next;

	fast = fast -> next -> next;
	slow = slow -> next;
	if(fast == NULL || slow == NULL)
		return NULL;

	while(fast != slow)
	{
		fast = fast -> next -> next;
		slow = slow -> next;	
	}

	while(slow != slow2)
	{
		slow = slow -> next;
		slow2 = slow2 -> next;
	}
	
	return slow;

}

int main(void)
{
	node *head;
	
	printf("testing list_create...\n");
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	head = list_create(a, 11, 3);
	print_list(head);
	
	printf("found node -> data is %d.\n", find_first_loop_node(head) -> data);
	return 0;
}
