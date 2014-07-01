/*
 * 题目描述：删除一个字符串中的重复字符；要求最多使用一个到两个变量，不能使用额外的缓冲区，不能复制数组。
 * Author:赵庶林
 * Date：2014/6/30
 * 思路：此题目的要求就是用时间换取空间。
		（1）把重复字符置为'\0'
		 (2) 如果当前字符为'\0'，则用后面的字符替换它
*/

#include <stdio.h>
#include <string.h>

int remove_duplicates(char * str)
{
	int len = strlen(str);
	if(len < 2)
		return 0;
	
	int i, j;
	int pos = 0;// pos滞留在'\0'处，等待被后面的字符替换
	
	for(i = 0; i < len; i++)
	{
		if(str[i])
		{
			str[pos++] = str[i];//用正常字符替换'\0'
			
			for(j = i + 1; j < len; j++)
			{
				if(str[i] == str[j])
					str[j] = '\0';//把重复字符置为'\0'
			}
		}
	
	}
	
	str[pos] = '\0';
	return 0;
}



/*另一个思路：如果可以用一个表示26个英文字母的bool型数组的话，可以省去内层循环，
* 如果字母a已经出现过了，则在bool数组里面标记为1
*/
#define MAX_SIZE 26
int remove_duplicates_with_array(char * str)
{
	int len = strlen(str);
	if(len < 2)
		return -1;

	int i, index;
	int pos = 0;
	int flag[MAX_SIZE];
	memset(flag, 0x00, sizeof(flag));

	for(i = 0; i < len; i ++)
	{
		index = str[i] - 'a';
		if(flag[index] == 0)
		{
			str[pos++] = str[i];
			flag[index] = 1;
		}
	}

	str[pos] = '\0';
	return 0;
}


int main(void)
{
	char str1[] = "abcd"; // string does not contain any duplicates
	puts(str1);
	remove_duplicates(str1);
	puts(str1);

	char str2[] = "aaaa"; // string contains all duplicates
	puts(str2);
	remove_duplicates(str2);
	puts(str2);

	char str3[] = ""; // Null string
	puts(str3);
	remove_duplicates(str3);
	puts(str3);

	char str4[] = "aaabbb"; // string with all continuous duplicates
	puts(str4);
	remove_duplicates_with_array(str4);
	puts(str4);

	char str5[] = "abababa"; // string with non-continuous duplicates
	puts(str5);
	remove_duplicates(str5);
	puts(str5); 
	

	return 0;
}
