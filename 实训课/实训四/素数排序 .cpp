#include <stdio.h>
#include <math.h>
void BubbleSort(int a[], int n){
	int i,j,swaptag = 1;
	int temp;
	for(i = 0;i < n-1; i++ ){
		for(j = 0; j < n-1-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i =0; i < n; i++){
		scanf("%d",&a[i]);
	}
	int m = 0,j;
	for(j = 0; j < n; j++){
		int kase = 1;  
		for (int i = 2; i < sqrt(a[j])+1; i++)
		{
			if(a[j]%i == 0){
				kase = 0;
				break;
			}
		}
		if(kase == 1){
			b[m] =a[j];
			m++;}
	}
	BubbleSort(b,m);
	for(int i = 0; i < m; i++)
		printf("%d ",b[i]);
	return 0;
} 
