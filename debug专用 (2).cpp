#include <stdio.h>
#include <math.h>
int main(){
	int t;
	scanf("%d",&t);
	whiel(t--){
		int n,i=1;
		scanf("%d",&n);
		while(n > 0)
		{
			n -= (pow(2,i) -1);
			i++;		
		if(pow(2,i) + n > pow(2,i-1))
			printf("%d\n",i );	
		else
			printf("%d\n",i-1 );
	}
}
	return 0;
}
