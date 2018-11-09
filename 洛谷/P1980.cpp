#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, x,count=0;
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; i++){
		int temp = i;
		while(temp){
			int p = temp%10;
			if(p == x)
				count++;
			temp/=10;
		}
	}
	printf("%d\n", count);
	return 0;
}