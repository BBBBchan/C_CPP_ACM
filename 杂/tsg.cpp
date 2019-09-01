#include <cstdio>
int main(int argc, char const *argv[])
{
	double ans = 0;
	for(int i = 0; i <= 730; i++){
		ans+=1;
		if(i%7 == 0){
			ans *= 0.9;
			printf("%lf ", ans);
		}
//		printf("%d ", ans);
	}
	printf("%lf\n", ans);
	return 0;
}