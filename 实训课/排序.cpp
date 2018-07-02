#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int times =0;
void BubbleSort(int a[], int n){
	int i,j,swaptag = 1;
	int temp;
	for(i = 0; swaptag && i < n-1; i++ ){
		swaptag = 0;
		for(j = 0; j < n-1-i; j++){
			times++;
			if(a[j] > a[j+1]){
				swaptag = 1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
void SelectSort(int a[], int n){
	int i,j,t;
	int temp;
	for(i = 0; i < n-1; i++){
		t = i;
		for(j = i+1; j<n;j++){
			times++;	
			if(a[j] < a[t]){
			t = j;}
	}
		if(t!=j){
			temp = a[i];
			a[i] = a[t];
			a[t] = temp;			
		}
	}
}
int main(){
	int a[1005];
	srand(time(NULL));
	for(int i = 0; i < 1000; i++){
		a[i] = rand();
	}
	BubbleSort(a,1000);
	for(int i = 0; i < 1000; i++)
		printf("%d ",a[i]);
		printf("\n%d",times);
	return 0;
}
