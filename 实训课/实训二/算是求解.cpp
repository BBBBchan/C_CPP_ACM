#include <stdio.h>
int main(){
	int i;
	for(i = 1000; i <= 1111; i++){
	char a[4], b[4];
	int temp1 = i;
	for(int j = 3; j >= 0; j--){
		a[j] = temp1%10;
		temp1/=10;
		}
	int temp;
	temp = 9*i;
	for(int j = 0; j < 4; j++){
		b[j] = temp%10;
		temp/=10;
	}
	int kase = 1;
	for(int j =0; j < 4; j++){
		if(a[j] != b[j]){
			kase = 0;
			break;
		}
	}
	if(kase)
		printf("%d\n",i);
	}
	return 0;
}

