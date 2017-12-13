#include <stdio.h>
#include <string.h>
int main(){
 	int m,n;
 	scanf("%d %d",&m,&n);
 	int a[m],k[n];
 	memset(a,0,sizeof(a));
 	memset(k,0,sizeof(k));
 	int q =n;
	while(n>0){
 		scanf("%d",&k[n-1]);
		n--;
	 }	
	 a[0] = q;
	for(int x = 0;x<q;x++)
		for(int i = k[x]-1;i >0 ;i--)
			a[i]++;
	for(int i = 0; i<m;i++)
	 	printf("%d\n",a[i]);
		 
    return 0;
}
