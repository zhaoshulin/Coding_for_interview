#include <stdio.h>

#include <string.h>



int main(void)

{

	int m, n, k, i, j, x;



	while(scanf("%d", &n) != EOF){

		scanf("%d %d", &m, &k);

		struct student_tag{

			int id;

			int ge;

			int gi;

			int final;

			int already_rank;

			int prefer[k];

		};



		struct school_tag{

			int max;

			int lowest_final;

			int lowest_ge;

			int admitted[n];

			int current_num;

			//int remain;

		};

		

		struct student_tag tmp;

		struct student_tag student[n+1];

		struct school_tag school[m+1];

		memset(student, 0, sizeof(struct student_tag)*(n+1));

		memset(school, 0, sizeof(struct school_tag)*(m+1));



		for(i = 0; i < m; i ++){

			scanf("%d", &(school[i].max));

		}



		for(i = 0; i < n; i ++){

			scanf("%d %d", &(student[i].ge), &(student[i].gi));

			for(j = 0; j < k; j ++){

				scanf("%d", &(student[i].prefer[j]));

			}

		}



		for(i = 0; i < n; i ++){

			student[i].final = (student[i].ge+student[i].gi) / 2;

			student[i].id = i;

		}

		for(i = 0; i < m; i ++){

			school[i].lowest_final = 101;

			school[i].lowest_ge = 101;

			school[i].current_num = 0;

		}



//		printf("input finished\n");



		//排序名次表： 分两步： 1，仅仅根据最终成绩进行快速排序 2，再根据ge成绩调整那些最终成绩一样的那几个

		for(i = 0; i < n; i ++){

			for(j = i+1; j < n; j ++){

				if(student[i].final < student[j].final){

			//		printf("swap 1\n");

					tmp = student[i];

					student[i] = student[j];

					student[j] = tmp;

				}



			}

		}

		for(i = 1; i < n; i ++){

			if(student[i-1].final == student[i].final && student[i-1].ge < student[i].ge){

			//	printf("swap 2\n");

				tmp = student[i];

				student[i] = student[i-1];

				student[i-1] = tmp;

			}

		}

/*		printf("adjust rank_table finished\n");

		for(i = 0; i < n; i ++){

			printf("%d: %d %d\n", student[i].id, student[i].final, student[i].ge);

		}

		printf("\n");

*/





		//遍历名次表，依次录取。

		//录取策略： if(school[student.prefer[x]].remain > 0) :录取；更新lowest_final 和  lowest_ge

		//           else if(.remain <= 0) : 判断是否满足 final == lowest_final && ge == lowest_ge 满足的话 就破格录取

		for(i = 0; i < n; i ++){

			for(j = 0; j < k; j ++){

				if(school[student[i].prefer[j]].max > 0){

					school[student[i].prefer[j]].admitted[school[student[i].prefer[j]].current_num++] = student[i].id;

					school[student[i].prefer[j]].max --;

					school[student[i].prefer[j]].lowest_final = student[i].final;

					school[student[i].prefer[j]].lowest_ge = student[i].ge;

					break;

				}

				else if(school[student[i].prefer[j]].max == 0){

					if(student[i].final == school[student[i].prefer[j]].lowest_final && student[i].ge == school[student[i].prefer[j]].lowest_ge){

						school[student[i].prefer[j]].admitted[school[student[i].prefer[j]].current_num++] = student[i].id;

						break;

					}



				}

			}

		}



	//	printf("admit finished\n");

	

		//按照升序，输出每所学校所录取的学生：

		for(x = 0; x < m; x ++){

			for(i = 0; i < school[x].current_num; i ++){

				for(j = i+1; j < school[x].current_num; j ++){

					if(school[x].admitted[i] > school[x].admitted[j]){

						int temp = school[x].admitted[i];

						school[x].admitted[i] = school[x].admitted[j];

						school[x].admitted[j] = temp;

					}

				}

			}

		}	



		for(i = 0; i < m; i ++){

			for(j = 0; j < school[i].current_num; j ++){

				if(j == school[i].current_num-1)

					printf("%d", school[i].admitted[j]);

				if(j < school[i].current_num-1)

					printf("%d ", school[i].admitted[j]);

			}

			printf("\n");

		}

	}

	return 0;

}