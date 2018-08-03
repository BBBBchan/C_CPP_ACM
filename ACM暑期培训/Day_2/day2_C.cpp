#include <stdio.h>
int main(int argc, char const *argv[])
{
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF){
		int t = m%(n+1);
		int a[n],kase = 0;
		if(t == 0)
			printf("none\n");
		else{
			for(int i = 1; i <= n; i++){
				if(m-i<=0 || (m-i)%(n+1)==0){
					a[kase] = i;
					kase++;
				}
			}
			for(int i = 0; i < kase-1; i++)
				printf("%d ", a[i]);
			printf("%d\n",a[kase-1]);
		}
	}
	return 0;
}