#include <stdio.h>
#include <stdlib.h>

//#define MAX 100

int main(void)
{
 int i, j, M, N, zero;
 //int a[MAX], b[MAX];
 int *a = NULL, *b = NULL; 

 while(1){
  zero = 0;
  scanf("%d", &M);
  if(M == 0)
   return 0;

  scanf(" %d", &N);

  if((a = malloc(sizeof(int)*M*N)) == NULL)
     return -1;
  if((b = malloc(sizeof(int)*M*N)) == NULL)
     return -1;

  for(i = 0; i < M*N; i ++){
   scanf("%d", &(a[i]));
  }
  for(i = 0; i < M*N; i ++){
   scanf("%d", &(b[i]));
  }

  for(i = 0; i < M*N; i ++)
     a[i] += b[i];

   for(i = 0; i < M; i ++){
     for(j = 0; j < N; j ++){
        if(a[i*N+j] != 0)
            break;
     }
     if(j == N)
        zero ++;
  }

   for(j = 0; j < N; j ++){
     for(i = 0; i < M; i ++){
         if(a[i*N+j] != 0)
            break;
     }
     if(i == M)
        zero ++;
  }
  
   printf("%d\n", zero);
  }
 return 0;
}