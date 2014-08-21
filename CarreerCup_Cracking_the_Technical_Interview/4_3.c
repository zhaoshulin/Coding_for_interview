/*
 * 题目描述：给定一个有序数组(递增)，写程序构建一棵具有最小高度的二叉树。
 * Author：赵庶林
 * Date：2014/08/21
 */

/*
 * 思路：使用递归，对半分。
 *       首先定义递归函数create(root, parent, a[start, end])的功能是：
 *          根据数组a[start, end]来构建树，树根是root，root的父亲是parent。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
 
typedef struct TreeNode_tag
{
	int data;
	struct TreeNode_tag *lchild, *rchild, *parent;
}TreeNode, *p_TreeNode;

TreeNode* create(TreeNode *root, TreeNode *parent, int a[], int start, int end)
{
	int middle;
	TreeNode * tmp;

	if(start <= end)
	{
		middle = (start + end) / 2;
		TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
		new -> data = a[middle];
		new -> parent = parent;
		root = new;

		create(root->lchild, root, a, start, middle - 1);
		create(root->rchild, root, a, middle + 1, end);	
	}
	else
	{
		tmp = root;
		while(tmp -> parent != NULL)
			tmp = tmp -> parent;
		return tmp;
	}
}

int height(TreeNode *root)
{
	int l,r;

	if(root == NULL)
		return 0;

	l = height(root -> lchild);
	r = height(root -> rchild);
	return (l > r) ? (l + 1) : (r + 1);
}


int main(void)
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
	TreeNode *root = NULL;
	TreeNode * tmp;

	printf("create testing...\n");
	tmp = create(root, NULL, a, 0, 7);
	printf("Tree height is %d.\n", height(tmp));

	return 0;
}
