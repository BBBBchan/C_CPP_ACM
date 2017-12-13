#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i=0;
		scanf("%d",&n);
		while(n > 0)
		{
			n -= pow(2,i);
			i++;
			}
		int p = (pow(2,i-1) + n);		
		int q = pow(2,i-2);
		if(p > q)
			printf("%d %d\n",i,p);	
		else
			printf("%d %d\n",i-1,q);
}
	return 0;
}