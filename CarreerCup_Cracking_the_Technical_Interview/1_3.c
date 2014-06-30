/*
 * 题目描述：删除一个字符串中的重复字符；要求最多使用一个到两个变量，不能使用额外的缓冲区，不能复制数组。
 * Author:赵庶林
 * Date：2014/6/30
 * 思路：此题目的要求就是用时间换取空间。肯定会用到双重循环，外层从左到右；内层遍历其右边所有的字符，如果与之相同，则删除，否则下一跳。
*/

#include <stdio.h>
#include <string.h>

//此函数的作用：从字符数组str[]中删除从head到tail的部分。
int remove_from_to(char * str, int head, int tail)
{
	int len = strlen(str);
	int n = tail - head + 1; //n是步长

	if((head < 0)|(tail > len))
		return -1;
	if(tail == len)
	{
		str[head] = '\0';
	}

	tail ++;
	while(str[tail] != '\0')
	{
		str[tail - n] = str[tail];
		tail ++;
	}
	str[tail -n] = '\0';
	return 0;
}

int remove_duplicate(char * str)
{
	int i, j, n;
	int len = strlen(str);

	if(len < 2)
		return 0;
	
	for(i = 0; i < len; i ++)
	{
		if(str[i] == '\0')
			return 0;
		for(j = i + 1; j < len; j ++)
		{	
			if(str[i] == str[j])
			{
				n = 1;
				while(str[i] == str[++j])
					n ++;
				remove_from_to(str, j - 1, j - 1 + n - 1);
				puts(str);
			}	
			else
				j ++;
		}
	
	}










	
	return 0;
}

int main(void)
{
	printf("remove_from_to() testing...\n");
	char str[] = "abcdefghadbcdgg";
	puts(str);
	remove_from_to(str, 1, 1);
	puts(str);
	
	printf("remove_duplicate() testing...\n");
	char str1[] = "abcddefsagelj";
	char str2[] = "aaabbbcccddd";
	char str3[] = "aaaaaaaa";
	char str4[] = "";

	puts(str1);
	remove_duplicate(str1);
	puts(str1);

	puts(str2);
	remove_duplicate(str2);
	puts(str2);

	puts(str3);
	remove_duplicate(str3);
	puts(str3);

	puts(str4);
	remove_duplicate(str4);
	puts(str4);

	return 0;
}
