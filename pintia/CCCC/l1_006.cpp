#include <cstdio>
#include <cmath>
int ans = 0, fcount = 0;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= sqrt(n); i++){
		int count = 0, temp = i, q = i;
		while(n % temp == 0){
			count++;
			q++;
			temp *= q;
		}
		if(count > fcount){
			fcount = count;
			ans = q - count;
		}
	}
	if(fcount != 0){
		printf("%d\n", fcount);
		for(int i = ans; i < fcount+ans-1; i++)
			printf("%d*", i);
		printf("%d", fcount+ans-1);
	}
	else{
		printf("1\n%d",n);
	}
	return 0;
}