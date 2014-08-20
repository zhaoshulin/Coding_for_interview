/*
 * 题目描述：实现一个函数检查一棵树是否平衡。对于这个问题而言， 平衡指的是这棵树任意两个叶子结点到根结点的距离之差不大于1。
 * Author：赵庶林
 * Date：2014/08/20
 */

/*
 * 思路：求出叶子结点中的最小深度和最大深度。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode_tag
{
	int data;
	struct TreeNode_tag *lchild;
	struct TreeNode_tag *rchild;
}TreeNode, *pTreeNode;

int getMinDep(TreeNode* root)
{
	int min;
	int l, r;

	if(root == NULL)
	{
		return 0;
	}

	l = getMinDep(root -> lchild);
	r = getMinDep(root -> rchild);
	min = (l > r) ? r : l;
	return min;
}

int getMaxDep(TreeNode* root)
{
	int max;
	int l, r;

	if(root == NULL)
		return 0;

	l = getMaxDep(root -> lchild);
	r = getMaxDep(root -> rchild);
	max = (l > r) ? l :r;
	return max;
}

int isBalance(TreeNode* root)
{
	int min, max;

	if(root == NULL)
		return 1;

	min = getMinDep(root);
	max = getMaxDep(root);
	
	if(max - min > 1)
		return 0;
	else
		return 1;
}

int main(void)
{
	printf("isBalance testing...\n");
	TreeNode * root;
	printf("ans is %d.\n", isBalance(root));
	return 0;
}
