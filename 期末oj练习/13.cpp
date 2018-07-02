#include <stdio.h>
int main(){
	int m,count = 1;
	scanf("%d",&m);
	int a[100];
	for(int i = 0; i < m; i++)
		scanf("%d",&a[i]);
for(int i = 0; i < m;i++){
	count = 1;	
	while(a[i] != 1){
		if(a[i]%2 == 0){
			a[i]/=2;
			count++;
			continue;
		}
		if(a[i]%2 == 1){
			a[i] = (a[i]*3)+1;
			count++;
			continue;
		}
	}
	printf("%d\n",count);
}
}
