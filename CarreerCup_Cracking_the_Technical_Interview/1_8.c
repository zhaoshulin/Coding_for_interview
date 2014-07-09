/* 题目描述：假设你有一个isSubstring函数，可以检测一个字符串是否是另一个
 *           字符串的子串。 给出字符串s1和s2，只使用一次isSubstring就能
 *           判断s2是否 * 是s1的旋转字符串， 请写出代码。 
 *           旋转字符串："waterbottle"是"erbottlewat" * 的旋转字符串。
 *           注意：旋转字符串类似于LED霓虹灯
 * Author：赵庶林
 * Date: 2014/07/09
 */

/*
 * 思路：（1）对于s1="abcd",那么LED循环霓虹灯的全集是s1+s1="abcdabcd",
 *            s1的旋转字符串就是从s1+s1截取的某一段长度是strlen(s1)的子集。
 *       （2）strstr：查找子串函数
 *            strcat：链接两个字符串函数
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

//return: 0 => no    1 => yes
int isSubstring(char *s1, char *s2)
{
	if(strstr(s1, s2) == NULL)
		return 0;
	else
		return 1;

}

// return: 0 => no    1 => yes
int is_Rotate_string(char *s1, char *s2)
{
	int len1, len2;

	len1 = strlen(s1);
	len2 = strlen(s2);
	
	if(len1 != len2)
	{
		return 0; // no!
	}
	
	strcat(s1, s1);

	if(isSubstring(s1, s2))
	{
		return 1; // yes
	}
	return 0; // no
}

int main(void)
{
	printf("Testing isSubsting...\n");
	char s1[MAX_SIZE] = "abcd";
	char s2[] = "ab";
	char s3[] = "ac";
	char s4[] = "";

	printf("%d %d %d\n", isSubstring(s1, s2), isSubstring(s1, s3), isSubstring(s1, s4));

	printf("Testing is_Rotate_string()...\n");
	char s5[] = "abc";
	char s6[] = "bcdc";
	char s7[] = "bcda";
	char s8[] = "";
	printf("%d %d %d %d\n", is_Rotate_string(s1, s5), is_Rotate_string(s1, s6), is_Rotate_string(s1, s7), is_Rotate_string(s1, s8));
	return 0;
}
