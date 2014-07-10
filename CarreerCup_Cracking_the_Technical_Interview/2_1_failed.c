/* 题目描述：从一个未排序的链表中删除重复项
 *           使用两种方法：（1）空间换时间
 *                         （2）时间换空间
 * Author：赵庶林
 * Date：2014/07/10
*/

/* 思路：（1）给出一个泛泛的构造链表的方法（此题暂定为单链表）
 *        (2)空间换取时间：
 *
 *
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"//在c语言里，专注于该接口来使用哈希

// 方便修改不同的数据类型，比较优雅
typedef int Key;
typedef int Value;

//自定义结构体
typedef struct bucket
{
	Key key;
	Value value;
	UT_hash_handle hh;
}bucket, *pbucket;

typedef struct node
{
	Key data; //注意：如果我决定了要使用hash，要牢记于心的一点是：hash只能通过key来查找！不能通过value来查找。
	struct node *next;
}node, *pNode;

//给定一个data数组,构建单链表
//Input: array[], n
//Return: head
node* single_list_init(Value *a, int n)
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
		memset(new, 0x00, sizeof(struct node)); 
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
	pNode pos;
	
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

	node *pos, *pre;
	bucket *new;
	bucket *user = NULL;//初始化

	pre = head;
	pos = pre -> next;
	if(head == NULL)
		return 0;

	while(pos != NULL)
	{
		
		HASH_FIND_INT(user, pos -> data, new);
		if(new == NULL)
		{
			new = (bucket *)malloc(sizeof(bucket));
			new -> key = pos -> data;
			new -> value = 0;//whatever!
			HASH_ADD_INT(user, &pos -> data, new);

			pos = pos -> next;
			pre = pre -> next;
		}
		else
		{
			if(pos -> next != NULL)
			{
				pre -> next = pos -> next;
				free(pos);
				pos = pre -> next; 
			}
			else
			{
				pre -> next = NULL;
				free(pos);
				return 0;
			}
		}
	}

	return 0;
}

int main(void)
{
	node * list1;
	printf("Testing single_list_init and single_list_destory...\n");
	Value a[] = {1, 2 ,3 ,4, 5, 6, 7, 8, 9, 1};
	list1 = single_list_init(a, 10);
	print_single_list(list1);
	
	printf("Testing remove_duplicate...\n");
	remove_duplicate(list1);
	print_single_list(list1);
	single_list_destory(list1);
	return 0;
}
