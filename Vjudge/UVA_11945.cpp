#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int k;
	scanf("%d", &k);
	for(int m = 0; m < k; m++){
		double sum = 0.0, mon;
		for(int i = 0; i < 12; i++){
			scanf("%lf",&mon);
			sum = sum+ mon;
		}
		sum /= 12.0;
		int a = (int)(sum/1000);
		sum-=a*1000;
		if(a>0)
			printf("%d $%d,%.2f\n",m+1, a, sum);
		else
			printf("%d $%.2f\n", m+1, sum);

	}
	return 0;
}