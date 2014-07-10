/* 题目描述：从一个未排序的链表中删除重复项
 *           使用两种方法：（1）空间换时间
 *                         （2）时间换空间
 * Author：赵庶林
 * Date：2014/07/10
*/

/* 思路：（1）给出一个泛泛的构造链表的方法（此题暂定为单链表）
 *       （2）因为c语言没有hash的接口，我就使用数组吧，浪费就浪费吧
 *       （3）用数组模拟哈希：hash[index] = value, index = data, value = TRUE/FALSE
 *       （4）但是显而易见有个缺点就是用数组模拟哈希，则index必须是int型啊！
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int hash[MAX_SIZE];

typedef struct node
{
	int data; 
	struct node *next;
}node, *node_p;

//给定一个data数组,构建单链表
//Input: array[], n
//Return: head
node* single_list_init(int *a, int n)
{
	node *head, *tail, *new;
	int i;
	
	//初始化head结点，注意：必须给人家分配内存！但是head不存数据
	head = (node *)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("Error when malloc memory for head! exit...\n");
		exit(EXIT_FAILURE);
	}

	head -> next = NULL; // close this list.
	tail = head;

	if(n <= 0)
	{
		return NULL;
	}
	
	for(i = 0; i < n; i ++)
	{
		new = (node *)malloc(sizeof(new));
		if(new == NULL)
		{
			printf("Error when malloc memory for new node! exit...\n");
			exit(EXIT_FAILURE);
		}
		memset(new, 0x00, sizeof(new)); 
		new -> next = NULL; //初始化清除

		new -> data = a[i];
		tail -> next = new;
		tail = tail -> next; // 尾插法
		tail -> next = NULL;

	}
	return head;
}

// 遍历单链表，打印所有的data
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
		printf("%d ", pos -> data);
		pos = pos -> next;
	}
	printf("\n");
	return 0;
}

//销毁单链表
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

int remove_duplicate(node *head)
{
	node *p, *q;

	p = head;
	q = p -> next;

	if(head == NULL)
		return 0;

	while(q != NULL)
	{
		if(hash[q->data] == 0)//没有重复
		{
				hash[q->data] = 1;
				p = q;
				q = q -> next;
		}
		else //有重复啦！删除！
		{
			if(q -> next != NULL)
			{
				p -> next = q -> next;
				free(q);
				q = p -> next;
			}
			else //只需要删除q就可以返回啦
			{
				free(q);
				p -> next = NULL;
				return 0;
			}

		}
	}	
	return 0;
}


int main(void)
{
	node * list;
	printf("Testing single_list_init and single_list_destory...\n");
	int a[] = {1, 2 ,3 ,4, 5, 6, 7, 8, 9, 1};
	list = single_list_init(a, 10);
	print_single_list(list);
	
	printf("Testing remove_duplicate...\n");
	remove_duplicate(list);
	print_single_list(list);
	single_list_destory(list);
	print_single_list(list);
	return 0;
}
