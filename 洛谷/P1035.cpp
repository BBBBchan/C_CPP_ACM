#include <cstdio>
int main(int argc, char const *argv[])
{
	double ans=0,k,count = 0;
	scanf("%lf", &k);
	while(ans<=k){
		count+=1;
		ans+=1/count;
	}
	printf("%.0lf", count);
	return 0;
}