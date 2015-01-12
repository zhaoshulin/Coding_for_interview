#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p, t, g1, g2, g3, gj;
	float ans;
	int what;

	while(scanf("%d %d %d %d %d %d", &p, &t, &g1, &g2, &g3, &gj) != EOF){
//	printf("%d %d %d %d %d %d\n", p, t, g1, g2, g3, gj);

	if(abs(g1-g2) <= t)
		what = 1;
	else if(abs(g1-g3) <= t && abs(g2-g3) > t)
		what = 2;
	else if(abs(g2-g3) <= t && abs(g1-g3) > t)
		what = 3;
	else if(abs(g1-g3) <= t && abs(g2-g3) <= t)
		what = 4;
	else if(abs(g1-g3) > t && abs(g2-g3) > t)
		what = 5;
	else 
		what = -1;

	switch (what){
		case 1:
			ans = (g1+g2) / 2.0;
			break;
		case 2:
			ans = (g1+g3) / 2.0;
			break;
		case 3:
			ans = (g2+g3) / 2.0;
			break;
		case 4:
			ans =1.0 * ((( (g1>g2)?g1:g2) > g3)? ((g1>g2)?g1:g2) : g3);
			break;
		case 5:
			ans = 1.0 * gj;
			break;
		case -1:
		default:
			return -1;
	}

	printf("%.1f\n", ans);
 }
	return 0;
}