#include <cstdio>
int check(int x){
	for(int i = 2; i*i<=x; i++)
		if(x%i==0){
			return 0;
		}
	return 1;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("4=2+2\n");
	for(int i = 6; i <= n; i+=2){
		for(int j = 3; j<= i; j+=2){
			if(check(j)&&check(i-j)){
				printf("%d=%d+%d\n", i, j, i-j);
				break;
			}
		}
	}
	return 0;
}