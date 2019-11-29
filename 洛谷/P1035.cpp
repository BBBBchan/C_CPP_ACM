// #include <cstdio>
// int main(int argc, char const *argv[])
// {
// 	double ans=0,k,count = 0;
// 	scanf("%lf", &k);
// 	while(ans<=k){
// 		count+=1;
// 		ans+=1/count;
// 	}
// 	printf("%.0lf", count);
// 	return 0;
// }
#include <cstdio>
int main(int argc, char const *argv[])
{
	double ans=0,k;
	int i = 0;
	scanf("%lf", &k);
	for(i = 1; ans <= k; i++){
		ans+=1.0/i;
		//printf("%lf\n", ans);
	}
	printf("%d", i-1);
	return 0;
}
