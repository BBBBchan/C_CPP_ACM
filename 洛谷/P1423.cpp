#include <cstdio>
int main(int argc, char const *argv[]){
	double a=2,n,count=0,ans=0;
	scanf("%lf", &n);
	while(ans<n){
		ans+=a;
		a*=0.98;
		count+=1;
	}
	printf("%.0lf\n", count);
	return 0;
}