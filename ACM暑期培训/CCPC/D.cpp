#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,a,n,b,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &a);
		if(n>2 || n == 0){
			printf("-1 -1\n");
			continue;
		}
		else if(n == 1){
			printf("1 %d\n", a+1);
			continue;
		}
		else{
			if(a%2==0){
				b = (a*a-4)/4;
				c = b+2;
			}
			else{
				b = (a*a-1)/2;
				c = b+1;
			}
			printf("%d %d\n",b, c);
		}
	}
	return 0;
}