#include <stdio.h>
#include <string.h>
int CompactIntegers(int *a,int n){
	int j = 0;
	for(int i=0;i < n; i++){
		if(a[i] != 0){
			a[j++] = a[i];
		}
	}
	return j;
}
int main(){
	int a[1000];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	int k;
	k = CompactIntegers(a,n);
	for(int i = 0; i < k; i++)
		printf("%d",a[i]);
	return 0;
}