/*
 * 题目描述：翻转一个C-Style的字符串
 * Author: 赵庶林
 * Date：2014/6/30
 * 思路：分为两步：1，找到末尾处；2，相向运动
*/

#include <stdio.h>

int reverse_string(char * string)
{
	char * left = string;
	char * right =  string;
	//找到末尾处
	while(*right != '\0')
		right ++;
	right --;
	printf("left is %p, right is %p.\n", left, right);

	//相向运动
	while(left < right)
	{
		*left = *left + *right;
		*right = *left - *right;
		*left = *left - *right;
		
		left ++;
		right --;
	}
	return 0;
}

int main(void)
{
	printf("rever_string testing ...\n");	
//      char * string = "abcdefg"; //错误！因为这样定义的字符串是READ_ONLY的！
	char string1[] = "abcdefg";
	puts(string1);
	reverse_string(string1);
	puts(string1);

	printf("rever_string testing ... \n");
	char string2[] = "abcd";
	puts(string2);
	reverse_string(string2);
	puts(string2);
	return 0;
}
