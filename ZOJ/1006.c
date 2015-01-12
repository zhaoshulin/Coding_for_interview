#include <stdio.h>
#include <string.h>

#define MAX 1000

/*
* 思路：
* 我们给定：z前面的o数目是a；z和j之间的o数目是b；j后面的o数目是c。
*      因为：j前面去掉一个o，就要在j后面去掉一个a
*      所以：直到去到什么程度呢，到了出现 zoj 这种程度，此时 z和j之间的o数目 从b->1,
*            而在j后面划掉了 (b-1)个a 还剩下 (c-(b-1)a) 个o
*      又因为：必须是 ajoza 的形式才行
*      所以：a = c - (b-1)a
*      得到： c = ab
*/

int main()
{
    char input[MAX];
    int a, b, c;
    char *walker;

    while(scanf("%s", input) != EOF){
        if(strcmp(input, "zoj") == 0){ //condition 1
            printf("Accepted\n");
            continue;
        }

        a = b = c = 0;
        walker = input;
        while(*walker == 'o'){
            a ++;
            walker ++;
        }
        if(*walker == 'z'){
            walker ++;
            while(*walker == 'o'){
                b ++;
                walker ++;
            }

            if(*walker == 'j'){
                walker ++;
                while(*walker == 'o'){
                    walker ++;
                    c ++;
                }
                if(!(*walker) && b>0 && c==a*b){
                       printf("Accepted\n");
                       continue;
                }
            }
        }
        printf("Wrong Answer\n");
    }
    return 0;
}
