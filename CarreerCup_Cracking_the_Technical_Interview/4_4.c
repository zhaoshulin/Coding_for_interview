/*
 * 题目描述：给定一棵二叉查找树，设计算法，将每一层的所有结点构建为一个链表(也就是说， 如果树有D层，那么你将构建出D个链表)。
 * Author：赵庶林
 * Date：2014/08/25
 */

/*
 * 思路：
 *      首先，为了练手二叉查找树，我先完成以下方法：
 *              （1）创建：create(int[], int length);
 *              （2）插入：insert(root, int data);
 *              （3）查找：find(root, int data);返回地址或者NULL
 *              （4）删除一个结点：delete(root, int data);
 *              （5）销毁：destroy(root);
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct BTreeNode_tag
{
	int data;
	struct BTreeNode_tag *lchild;
	struct BTreeNode_tag *rchild;
}BTreeNode, *p_BTreeNode;

void insert(BTreeNode **root, int data)
{
	//入参检测
	if(*root == NULL)
	{
		BTreeNode *tmp = (BTreeNode *)malloc(sizeof(BTreeNode));
		tmp -> data = data;
		tmp -> lchild = NULL;
		tmp -> rchild = NULL;
		*root = tmp;  
	//	root = &tmp; this is wrong, can you see why?
		return;
	}
	
	else if(data < (*root) -> data)//go left
	{
		insert(&((*root) -> lchild), data);
	}
	else//go right
	{
		insert(&((*root) -> rchild), data);
	}
}

BTreeNode* find(BTreeNode* root, int data)
{
	while(root != NULL)
	{
		if(data == root -> data)
		{
			return root;
		}
		else if(data < root -> data)//go left
		{
			root = root -> lchild;
		}
		else //go right
		{
			root = root -> rchild;
		}
	}

	// cannot find it!
	return NULL;
}

BTreeNode* create(int a[], int length)
{
	BTreeNode *root = NULL;
	int i;

	for(i = 0; i < length; i ++)
		insert(&root, a[i]);

	return root;	
}

void delete(BTreeNode** root, int data)
{
	BTreeNode* tmp;
	BTreeNode *higher, *lower;

	if(find(*root, data) == NULL)
		return;

	if(data < (*root) -> data)
		delete(&((*root) -> lchild), data);
	else if(data > (*root) -> data)
		delete(&((*root) -> rchild), data);
	else
	{
		if((*root) -> lchild == NULL)
		{
			tmp = *root;
			*root = (*root) -> rchild;
			free(tmp);
			return;
		}
		else if((*root) -> rchild == NULL)
		{
			tmp = *root;
			*root = (*root) -> lchild;
			free(tmp);
			return;
		}
		else
		{
			if((*root) -> lchild -> rchild == NULL)
			{
				(*root) -> data = (*root) -> lchild -> data;
				delete(&((*root) -> lchild), (*root) -> lchild -> data);
			}
			else
			{
				higher = *root;
				lower = (*root) -> lchild;

				while(lower -> rchild != NULL)
				{
					higher = lower;
					lower = lower -> rchild;
				}

				(*root) -> data = lower -> data;
				delete(&lower, lower -> data);
			}
		}
	}
}

void destory(BTreeNode *root)
{
	if(root == NULL)
		return;

	if(root -> lchild)
		destory(root -> lchild);
	else if(root -> rchild)
		destory(root -> rchild);
	else
	{
		free(root);
		return;
	}
}

/*
 * 题目思路：
 *          （1）链表list中的数据结构是BTreeNode；
 *          （2）数组results中的数据结构是list；
 *          （3）    
 */




int main(void)
{
	printf("insert testing...\n");
	BTreeNode *root = NULL;
//	insert(&root, 1);
//	insert(&root, 2);
//	insert(&root, 0);

	printf("create testing...\n");
	int a[] = {0, 1, 2, 4, 3, 7, 5, 6, 8, 3, 10, 9};
	int length = sizeof(a) / sizeof(a[0]);
	root = create(a, length);
	
	printf("find testing...\n");
	BTreeNode* tmp = find(root, 9);
	printf("find? data = %d.\n", tmp -> data);
	tmp = find(root, 11);
	if(tmp == NULL)
		printf("I cannot find 11!\n");

	printf("delete testing...\n");
	tmp = find(root, 1);
	if(tmp)
		printf("find it! data = %d.\n", tmp -> data);
	else
		printf("Cannot find 1!\n");
	delete(&root, 1);
	tmp = find(root, 1);
	if(tmp)
		printf("find it! data = %d.\n", tmp -> data);
	else
		printf("Cannot find 1!\n");

	printf("destory testing...\n");
	destory(root);


	return 0;
}
