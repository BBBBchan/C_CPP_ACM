#include <stdio.h>
int gcd(int a, int b){
	return b ? gcd(b,a%b) : a;
}

int ans[1000001];
int main(int argc, char const *argv[])
{
	int m, k;
	while(scanf("%d %d", &m, &k) != EOF){
		int count = 0,res;
		for(int i = 1; i <= m; i++){
			if(gcd(i,m) == 1){
				count++;
				ans[count] = i;
			}
		}
		if(k%count == 0)
			res = m*(k/count-1)+ans[count];
		else
			res = k/count*m + ans[k%count];
		printf("%d\n", res);
	}
	return 0;
}