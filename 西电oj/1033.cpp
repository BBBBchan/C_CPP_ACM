#include <stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d",&n);
		if(n > 540)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}