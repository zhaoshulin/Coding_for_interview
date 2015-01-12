#include <stdio.h>

 

int main(void)

{

   int n, i;

 

  while(scanf("%d", &n) != EOF){

    if(n == 0 || n == 1 || n < 0 || n == 2 || n == 5){

       printf("no\n");

      continue; 

    }



    if(n == 4){

    	printf("yes\n");

	continue;

    }

 

    for(i = 2; i < n/2; i ++){

      if(n % i == 0){

        printf("no\n");

        break;

     }

   }

    if(i == n/2)

    	printf("yes\n");

  }

   return 0;

}