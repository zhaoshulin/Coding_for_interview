#include <stdio.h>

int main(void)
{
 int n;
 int ans;

 while(1){
 ans = 0;
  scanf("%d", &n);
  if(n == 0){
     return 0;
 }

  while(n != 1){
    if(n % 2 == 0){
       n /= 2;
       ans ++;
    }else if(n %2 == 1){
       n = 3*n + 1;
       n /= 2;
        ans ++;
     }

  }
     printf("%d\n", ans);
}
 return 0;
}