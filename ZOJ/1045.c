#include <stdio.h>



int main(void)

{

	int x, y, z, n;



	while(scanf("%d", &n) != EOF){

		for(x = 0; x < n; x ++){

			for(y = 0; y < n; y ++){

				if(14*x + 8*y <= 3*n - 100){

					printf("x=%d,y=%d,z=%d\n", x, y, (100-x-y));

					continue;

				}

				else

					break;

			}

		}

	}



	return 0;

}