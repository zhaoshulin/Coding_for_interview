#include <stdio.h>



int main(void)

{

	int max, i;

	int a[11];



	while(1){

		for(i = 0; i < 10; i ++){

			if(scanf("%d", &(a[i])) == EOF){

				return 0;

			}			

		}



		max = a[0];

		for(i = 0; i < 10; i ++){

			if(a[i] > max)

				max = a[i];

		}



		printf("max=%d\n", max);

	}



	return 0;

}