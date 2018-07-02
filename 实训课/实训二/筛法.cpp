#include <stdio.h>
int main(){
	int N;
	scanf("%d", &N);
	int a[100] = {2,3,5};
	for(int i = 2 ; i < N; i++){
		int kase = 1,temp = 0;
		for(int j = 0; j < N; j++){
			if(a[j] == 0)
				break;
			if(i%a[j] == 0){
				kase = 0;
				break;
			}
		temp = j;
		}
		if(kase){
			a[temp+1] = i;
		}
		}
		int j = 0;
		while(a[j] != 0){
			printf("%d\n",a[j]);
			j++;
		}
	return 0;
} 
