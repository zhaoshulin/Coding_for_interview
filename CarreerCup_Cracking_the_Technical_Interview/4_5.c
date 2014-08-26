/*
 * 题目描述：给定二叉查找树的一个结点， 写一个算法查找它的“下一个”结点(即中序遍历后它的后继结点)， 其中每个结点都有指向其父亲的链接。
 * Author：赵庶林
 * Date：2014/08/26
 */

/*
 * 思路：（1）插入：insert(root, int data);
 *       （2）创建：create(int[], int length);
 *       （3）销毁：destroy(root);
 *       （4）查找下一个：findNext(node)
 *                       1，该node是左孩子：找到node的右孩子的最左孩子；
 *                       2，该node是右孩子：找到node的祖先中第一个作为左孩子结点的父亲。
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct BTreeNode_tag
{
	int data;
	struct BTreeNode_tag *lchild, *rchild, *parent;
}BTreeNode, *p_BTreeNode;

/*
void insert(BTreeNode **root, int data)
{
	if(*root == NULL)
	{
		BTreeNode* tmp = (BTreeNode*)malloc(sizeof(BTreeNode));
		tmp -> data = data;
		tmp -> lchild = NULL;
		tmp -> rchild = NULL;
		tmp -> parent = NULL;
		*root = tmp;
		return;
	}

	else if(data < (*root)->data) //go left
	{
		insert(&((*root) -> lchild), data);
		(*root) -> lchild -> parent = (*root);
	}
	else //go right
	{
		insert(&((*root) -> rchild), data);
		(*root) -> rchild -> parent = (*root);
	}
}

BTreeNode* create(int a[], int length)
{
	BTreeNode* root = NULL;
	int i;

	for(i = 0; i < length; i ++)
	{
		insert(&root, a[i]);
	}
	return root;
}
*/
// create() is wrong!!!

BTreeNode node[MAX_SIZE];

void create(BTreeNode** root, BTreeNode* parent, int a[], int start, int end)
{
	int cnt = 0;

	if(start <= end)
	{
		int mid = (start + end) >> 1;
		node[cnt].data = a[mid];
		node[cnt].parent = parent;
		*root = &node[cnt++];
		create(&((*root)->lchild), *root, a, start, mid-1);
		create(&((*root)->rchild), *root, a, mid+1, end);
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

BTreeNode* findNext(BTreeNode* root, BTreeNode* node)
{
	if(root == NULL || node == NULL)
		return NULL;

	if(node == root || node -> parent == NULL || node->parent->lchild == node) // node is lchild.
	{
		BTreeNode* tmp = node -> rchild;
		while(tmp->lchild != NULL)
		{
			tmp = tmp -> lchild;
		}
		return tmp;
	}

	if(node->parent->rchild == node) // node is rchild.
	{
		BTreeNode* tmp = node;
		while(tmp->parent->rchild == tmp)
		{
			tmp = tmp -> parent;
		}
		return tmp->parent;
	}
}


int main(void)
{
	printf("create testing...\n");
	BTreeNode *root = NULL;
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int length = sizeof(a) / sizeof(a[0]);
	create(&root, NULL, a, 0, 9);
	printf("root is %d, lchild is %d, rchild is %d.\n", root->data, root->lchild->data, root->rchild->data);

	printf("findNext testing...\n");
	BTreeNode *node = root;
//	BTreeNode *node = root -> lchild;
	BTreeNode *ans;
	ans = findNext(root, node);
	if(ans == NULL)
		printf("Not found.\n");
	else
		printf("Find it! data is %d.\n", ans -> data);

	printf("destory testing...\n");
	destory(root);

	return 0;
}
