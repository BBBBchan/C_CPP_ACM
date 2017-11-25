#include <stdio.h>
int main()
{	int n;
	while(scanf("%d",&n) == 1){
		int answer[10],kase = 0,p=n,q=0;
		while(p/10 != 0){
			p/=10;
			q++;
		}
		for( int i = n-(p+10*q);i<n;i++){
			int temp = i,sum = i;
			while(temp != 0){
				sum += temp%10;
				temp /= 10;
			}
			if(sum == n){
				answer[kase] = i;
				kase++;
			}
		}
		if(kase == 0)	printf("0\n");
		else {
				printf("%d\n",kase);
				int m = kase;
				for(m = 0;m < kase;m++)
					printf("%d\n",answer[m]);}

	}
	return 0;
}