#include <cstdio>
int main(int argc, char const *argv[])
{
	float n,ans;
	scanf("%f", &n);
	if(n<0)
		printf("Invalid Value!\n");
	else if(n<=50){
		ans = n*0.53;
		printf("cost = %.2f\n", ans);
	}
	else{
		ans = 50*0.53+(n-50)*0.58;
		printf("cost = %.2f\n", ans);
	}
	
	return 0;
}