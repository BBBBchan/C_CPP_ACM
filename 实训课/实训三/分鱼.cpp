#include <stdio.h>
int main(){
	int n;
	while(true){
		int temp = n,i = 0;
		for(i = 0; i < 5; i++){
			if(temp%5 == 1){
				temp -=1;
				temp = temp*0.8;
			}
			else break;
		}
		if(i == 5){
			printf("%d\n", n);
			break;
	}
		n++;
	}
}
