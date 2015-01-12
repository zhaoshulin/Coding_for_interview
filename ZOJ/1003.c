#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void)
{
	char str1[MAX], str2[MAX];
	char a[MAX], b[MAX];
//	char tmp[MAX];
	int i, j;
	long long x, y;
	
	//handle input
	while(scanf("%s %s", str1, str2) != EOF){
//		printf("%s\n", str1);
//		printf("%s\n", str2);

		for(i = 0, j = 0; i < strlen(str1); i ++){
			if(str1[i] != ','){
				a[j++] = str1[i];
			}
			a[j] = '\0';
		}

		for(i = 0, j = 0; i < strlen(str2); i ++){
			if(str2[i] != ','){
				b[j++] = str2[i];
			}
			b[j] = '\0';
		}

//		printf("%s\n", a);
//		printf("%s\n", b);

		sscanf(a, "%lld", &x);
		sscanf(b, "%lld", &y);
//		printf("%lld\n", x);
//		printf("%lld\n", y);
		printf("%lld\n", x+y);
	}

	return 0;
}