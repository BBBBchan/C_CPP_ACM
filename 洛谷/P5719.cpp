#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, k, count1=0, count2 = 0;
	scanf("%d %d", &n, &k);
	int sum1 =0 , sum2 = 0;
	for(int i = 1; i <= n; i++){
		if(i % k == 0){
			sum1+=i;
			count1++;
		}
		else{
			sum2 += i;
			count2++;
		}
	}
	double ans1 = (double)((double)sum1/(double)count1);
	double ans2 = (double)((double)sum2/(double)count2);
	if(count1 == 0 && count2 != 0){
		printf("0.0 %.1lf", ans2);
	}
	else if(count1 != 0 && count2 == 0){
		printf("%.1lf 0.0", ans1);
	}
	else if(count1 == 0 && count2 == 0){
		printf("0.0 0.0");
	}
	else{
		printf("%.1lf %.1lf", ans1, ans2);
	}
	return 0;
}