#include <stdio.h>



int main(void)

{

	int a, b, c, tmp;



	while(scanf("%d %d %d", &a, &b, &c) != EOF){

		if(a > c){

			tmp = a;

			a = c;

			c = tmp;

		}

		if(b > c){

			tmp = b;

			b = c;

			c = tmp;

		}



		if(a*a + b*b == c*c){

			printf("直角三角形\n");

			continue;

		}

		else if(a*a + b*b < c*c){

			printf("钝角三角形\n");

			continue;

		}

		else if(a*a + b*b > c*c){

			printf("锐角三角形\n");

			continue;

		}

	}



	return 0;

}