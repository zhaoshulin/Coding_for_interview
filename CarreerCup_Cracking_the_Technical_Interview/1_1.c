/*
 * 题目要求：给定一个字符串，判断该字符串中是否有重复的字符。只能使用最基本的数据结构。
 * Date: 2014/6/30
 * Author: 赵庶林
*/

/* 
 * 思路：在面试的算法题中，一般都是用空间换取时间，而且如果你的算法出现了O(N^2)
 * 的时间复杂度，一般就说明你的算法很差劲。你可以想想，一共就只有26个英文字母，
 * 那我就分配26个char型的数组，这样所花费的内存才只有26Byte不是吗？现在开始找规律
 * 字符'a'对应于arr[0]；'b'对应于arr[1]...所以字符'x'对应于arr[('x')-('a')]
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h> //如果有了这个头文件，就不用自定义bool类型啦

//typedef enum __bool {false = 0, true = 1} bool;
#define MAXSIZE 26

bool is_unique(char * string)
{
	int length = strlen(string);
	int i = 0, index = 0;
	int arr[MAXSIZE];
	
	memset(arr, 0x00, sizeof(arr));

	for(i = 0; i < length; i++)
	{
		index = string[i] - 'a'; //找到该字母的位置
		if(arr[index] == 0) //0代表还未出现该字母呢
			arr[index] = 1; 
		else
			return false; // 代表不是独一无二的！
	}
	return true; //代表是独一无二滴！
}

int main(void)
{
	printf("Testing is_unique()...\n");
	char * s1 = "abcdefghijk";
	char * s2 = "aa";
	char * s3 = "cdefaaadd";

	if(is_unique(s1) == false)
		printf("s1: false\n");
	else
		printf("s1: true\n");

	if(is_unique(s2) != true)
		printf("s2: false\n");
	else
		printf("s2: true\n");
	
	if(is_unique(s3) == false)
		printf("s3: false\n");
	else
		printf("s3: true\n");
	return 0;
}
