#include <stdio.h>

#include <string.h>



int main(void)

{

	int n, m, i, j;

	struct country_tag{

		int need_flag;

		int gold;

		int total;

		int people;

		double gp;

		double tp;

		int rank[4];

		int which_way;

		int best_rank;

	};



	while(scanf("%d %d", &n, &m) != EOF){

		struct country_tag country[n];

		int need[m];

		memset(country, 0, sizeof(struct country_tag)*n);

		memset(need, 0, sizeof(int)*m);



		for(i = 0; i < n; i ++){

			scanf("%d %d %d", &(country[i].gold), &(country[i].total), &(country[i].people));

		}



		for(i = 0; i < m; i ++){

			scanf("%d", &(need[i]));

		}

		

		for(i = 0; i < m; i ++){

			country[need[i]].need_flag = 1;

		}



		for(i = 0; i < n; i ++){

			country[i].which_way = 1;

			country[i].best_rank = n;

			country[i].gp = (double)country[i].gold / country[i].people;

			country[i].tp = (double)country[i].total / country[i].people;

			for(j = 0; j < 4; j ++)

				country[i].rank[j] = m;

		}



		//确定rank[]：思路是：初始化的排名是m；每次循环确定一个国家的rank，只要这个国家找到一个比他差的，这个国家的排名就前进一位

		for(i = 0; i < n; i ++){



//			printf("%d ", country[i].need_flag);

			if(country[i].need_flag != 1)

				continue;



			for(j = 0; j < n; j ++){

				if(country[j].need_flag != 1)

					continue;



				if(country[i].gold >= country[j].gold)

					country[i].rank[0] --;

				if(country[i].total >= country[j].total)

					country[i].rank[1] --;

				if(country[i].gp >= country[j].gp)

					country[i].rank[2] --;

				if(country[i].tp >= country[j].tp)

					country[i].rank[3] --;

			}



			

			//rank[]已经填充完毕

			//下面，开始填充 best_rank 和 which_way

			for(j = 0; j < 4; j ++){

				if(country[i].best_rank > country[i].rank[j]){

					country[i].best_rank = country[i].rank[j];

					country[i].which_way = j + 1;

				}

			}

		}



		//output now

		for(i = 0; i < n; i ++){

			if(country[i].need_flag != 1)

				continue;



			printf("%d:%d\n", country[i].best_rank+1, country[i].which_way);

		}



		

		printf("\n");	



	}



	return 0;

}