#include <stdio.h>

#include <stdlib.h>



int main(void)

{

	int m, n, i, j, index, walker;

	int *a=NULL, *b=NULL;

	int ans;



	while(scanf("%d", &m) != EOF){

		a = malloc(sizeof(int) * m);

		if(a == NULL)

			return -1;



		for(i = 0; i < m; i ++)

			scanf("%d", &(a[i]));



		scanf("%d", &n);

		b = malloc(sizeof(int) * n);

		if(b == NULL)

			return -1;



		for(i = 0; i < n; i ++)

			scanf("%d", &(b[i]));



		index = (m+n+1)/2 - 1;

/*		

		for(i = 0; i < m; i ++)

			printf("%ld ", a[i]);

	

		printf("\n");

		for(i = 0; i < n; i ++)

			printf("%ld ", b[i]);

		printf("\n");

*/

		walker = i = j = 0;

		while(walker <= index){

			if(a[i] < b[j] && i < m && j < n){

				ans = a[i++];

			}

			else if(a[i] >= b[j] && i < m && j < n){

				ans = b[j++];

			}

			else if(i >= m){

				ans = b[j++];

			}

			else if(j >= n){

				ans = a[i++];

			}



			walker ++;

		}

		printf("%d\n", ans);

	}



	return 0;

}