/*
 * 题目描述：使用递归和非递归（栈）来解决汉诺塔问题。
 * Author：赵庶林
 * Date：2014/08/19
 */

/*
 * 递归算法思路：整个的移动过程可以分为三步骤：
 *               ([1,n], 0, 0) --1--> (n, [1,n-1], 0) --2--> (0, [1,n-1], n) --3--> (0, 0, n)
 *               所以，可以自定义一个函数 hanoi(begin, end, src, bridge, dst)，该函数作用：将标号是[begin,end]的盘子从src柱子上，途经bridge柱子，移动到dst柱子上。
 *               所以，步骤1：hanoi(1, n-1, src, dst, bridge);
 *                     步骤2：printf("Move item %d: %c ----> %c", n, src, dst);
 *                     步骤3：hanoi(1, n-1, bridge, src, dst);
 *               终止条件：if(end == begin) 说明此时就剩下1还在src柱子上，只要移动一步即可：printf("Move item 1: %c ----> %c", src, dst);
 */

/*
 * 因为c语言栈没有接口，我就暂时没有加入非递归算法。
 * 但是整体思路：每次循环pop一次，如果满足终止条件，则直接continue；不满足则逆序push，直到循环栈为空。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hanoi(int begin, int end, char src, char bridge, char dst)
{
	if(end == begin)
	{
		printf("Move item %d: %c ----> %c.\n", end, src, dst);
		return;
	}

	else
	{
		hanoi(begin, end - 1, src, dst, bridge);
		printf("Move item %d: %c ----> %c.\n", end, src, dst);
		hanoi(begin, end - 1, bridge, src, dst);
	}
}

int main(void)
{
	printf("hanoi testing...\n");
	int n = 10;
	hanoi(1, n, 'A', 'B', 'C');

	return 0;
}

