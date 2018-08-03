#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d %d", &a, &b)!=EOF){
		if(a>b){
			int temp = a;
			a = b;
			b = temp;
		}
		int k = b - a;
		double a_k= k*(1+sqrt(5.0))/2.0;
		if(a ==  int(a_k)){
			printf("0\n");}
		else
			printf("1\n");
	}
	return 0;
}