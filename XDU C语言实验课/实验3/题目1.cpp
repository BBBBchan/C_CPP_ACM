#include <stdio.h>
int main()
{
	int m, n;
	scanf("%d %d",&m,&n);
	for(int i = m+1;i<n;i++){
		int kase = 1;
		for(int x = 2;x*x<=i;x++){
			if(i%x == 0){
				kase = 0;
				break;
			}
		}
		if(kase)
			printf("%d",i);
	}
	return 0;
}
