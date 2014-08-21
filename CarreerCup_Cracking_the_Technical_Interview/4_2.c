/*
 * 题目描述：给定一个有向图，设计算法判断两结点间是否存在路径。
 * Author：赵庶林
 * Date：2014/08/21
 */

/*
 * 思路：（1）新建一个有向图：就是一个为邻接矩阵赋值的过程。
 *       （2）打印出该邻接矩阵；
 *       （3）DFS搜索。（因为简单哈哈）
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int visited[MAX];

typedef struct Graph_tag
{
	unsigned int g[MAX][MAX];//邻接矩阵
	int n;//顶点数
	int e;//边数
}Graph, *p_Graph;

struct Graph_tag* createGraph(void)
{
	int n, e;
	int i, j;
	int src, dst;
	unsigned int value;

	struct Graph_tag* G = (struct Graph_tag*)malloc(sizeof(Graph));

	for(i = 0; i < MAX; i ++)
		visited[i] == 0;

	printf("Input number of vertex: n = ");
	scanf("%d", &n);
	G -> n = n;
	printf("\nInput number of edges: e = ");
	scanf("%d", &e);
	G -> e = e;
	printf("\n");
	
	
	for(i = 0; i < MAX; i ++)
	{
		for(j = 0; j < MAX; j ++)
		{
			G -> g[i][j] = 0;
		}
	}

	for(i = 0; i < e; i ++)
	{
		printf("Input edeg_%d: src dst value.\n", i);
		scanf("%d %d %u", &src, &dst, &value);
		G -> g[src][dst] = value;
	}		

	return G;

}

void printG(Graph* G)
{
	int i, j;

	for(i = 0; i < G->n; i ++)
	{
		for(j = 0; j < G->n; j ++)
		{
			printf("%u ", G->g[i][j]);
		}
		printf("\n");
	}

	return;
}

int DFS(Graph* G, int src, int dst)
{
	printf("Now check %d -> %d...\n", src, dst);
	int i;

	visited[src] = 1;

	if(G->g[src][dst] > 0)
	{
		return 1;
	}

	for(i = 0; i < G->n; i++)
	{
		if(G->g[src][i] > 0 && visited[i] == 0)
		{
			if(DFS(G, i, dst) == 1)
				return 1;
		}
	}
	return 0;	
}

int main(void)
{
	Graph* G;

	printf("createGraph testing...\n");
	G = createGraph();
	
	printf("printG testing...\n");
	printG(G);

	printf("DFS testing...\n");
	printf("Ans = %d.\n", DFS(G, 0, 3));
	printf("Ans = %d.\n", DFS(G, 0, 2));
	return 0;
}
