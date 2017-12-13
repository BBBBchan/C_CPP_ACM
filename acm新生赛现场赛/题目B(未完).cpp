#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void * p1,const void * p2){
	const int * a1 =(const int *)p1;
	const int * a2 =(const int *)p2;
	if(*a1 < *a2)
		return -1;
	else if(*a1 == *a2)
		return 0;
	else return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n],count = 0;
	for(int i = 0; i<n;i++)
		scanf("%d",&a[i]);
	for(int i = n-1;i>=0;i--){
		int x;
		for(x = i-1;x>=0;x--)
		if(a[i] == a[x])
			break;
		if(x == -1)
			{
				b[count] = a[i];
				count++;
			}
	}
	qsort(a,n,sizeof(int),comp);
	for(int i = 0; i<n; i++)
		printf("%d ",a[i]);
	printf("\n");
	for(int i  = count-1; i >= 0; i--)
		printf("%d ",b[i]);
	int p = 0,cout[n];
	printf("%d",cout[0]);
	for(int i = 0;i < n;i++){
		if(a[i] == a[i+1]){	
			cout[p]++;
			continue;}
		else	p++;
	}
	int max = cout[0];
	for(int i = 0 ; i<p; i++){
		if(cout[i] > max)
			max = cout[i];
	}
	for(int i = 0; i<p; i++){
		if(cout[i] == max)
			printf("%d",a[])
	}
		
	
	return 0;
}
