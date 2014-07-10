/*
 * 题目描述：判断两个字符串是否互为变位词(Anagrams)
 * 变位词：（1）字符相同 （2）字符出现的次数相同 如：abcda 和 aadcb
 * Date: 2014/7/1
 * Author：赵庶林
 * 思路：我又一次可以用到26个bool型的数组：我可以给它命名为alpha[26]，
 *      （1）遍历字符串1，相应位置++
 *       (2) 遍历字符串2，相应位置--
 *      （3）遍历alpha[]，按理说应该是全零滴
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 26

// Return: 1 => true; 0 => false; -1 => error
int is_anagrams(char * str1, char * str2)
{
	int i, index;
	int len = strlen(str1);
	if(len != strlen(str2))
		return 0;

	int alpha[MAX_SIZE];
	memset(alpha, 0x00, sizeof(alpha));

	for(i = 0; i < len; i ++)
	{
		index = str1[i] - 'a';
		alpha[index] ++;
	}
	
	for(i = 0; i < len; i ++)
	{
		index = str2[i] - 'a';
		alpha[index] --;
	}	
	

	for(i = 0; i < MAX_SIZE; i ++)
	{
		if(alpha[i] != 0)
			return 0;
	}
	return 1;

}

int main(void)
{
	char str1[] = "abcda";
	char str2[] = "aacdb";
	printf("return is %d.\n", is_anagrams(str1, str2));

	char str3[] = "aaa";
	char str4[] = "aac";
	printf("return is %d.\n", is_anagrams(str3, str4));
	return 0;
}
