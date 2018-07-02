#include <stdio.h>
int main(){
	struct a{
		int p;
		int b;
	}a[100];
	int n;
	int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d %d",&a[i].p,&a[i].b);
	for(int i = 0; i < n; i++){
		if(a[i].b != 2){
			printf("%d\n",month[a[i].b-1]);
		}
		else if(( (a[i].p % 4 == 0) && (a[i].p % 100 != 0) ) || (a[i].p %400 == 0))
			printf("29\n");
		else 
			printf("28\n");
	}
	return 0;
}
