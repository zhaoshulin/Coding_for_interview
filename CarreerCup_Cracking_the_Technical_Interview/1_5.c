/*
 * 题目描述：把一个字符串中的所有的空格换成'%20'
 * Author: 赵庶林
 * Date: 2014/7/2
 * 思路：' '替换为'%20'，所有假设有n个空格的话，新串的长度比旧串长2n
 *        （1）算出新串的长度
 *        （2）i从后到前遍历旧串；p从后到前遍历新串。如果遇到空格，则i--，p - 3
*/

#include <stdio.h>
#include <string.h>

int replace_space(char * str)
{
	int i, p;
	int cnt = 0; 

	int len = strlen(str);
	
	if(len <= 0)
		return -1;

	for(i = 0; i < len; i ++)
	{
		if(str[i] == ' ')
			cnt ++;
	}

	p = len + 2 * cnt;
	str[p] = '\0';//最末尾是结束标志！
	p --;
	
	for(i = len - 1; i >= 0; i --)
	{
		if(str[i] == ' ')
		{
			str[p] = '0';
			str[p - 1] = '2';
			str[p - 2] = '%';
			p = p - 3;
		}
		else
		{
			str[p] = str[i];
			p --;
		}
	}

	return 0;
}

int main(void)
{
	char str1[] = "I am zsl";
	puts(str1);
	replace_space(str1);
	puts(str1);


	return 0;
}
