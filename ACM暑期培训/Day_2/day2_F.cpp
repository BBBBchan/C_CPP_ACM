#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,count = 0;
	scanf("%d", &t);
	while(t--){
		count++;
		int n, k;
		scanf("%d %d", &n, &k);
		if(k == 1){
			if(n%2==1)
				printf("Case %d: first\n",count);
			else
				printf("Case %d: second\n", count);
		}
		else if(k>=n)
			printf("Case %d: first\n", count);
		else
			printf("Case %d: second\n", count);
	}
	return 0;
}