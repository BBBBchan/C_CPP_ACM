#include <stdio.h>
#include <math.h>
int main(){
	float n;
	int kase = 0;
	scanf("%f", &n);
	while(n != 0){
		for(int i = 0;i < 50; i++){
			float a = (1/sqrt(5))*(pow((1+sqrt(5))/2,i)-pow((1-sqrt(5))/2,i));
			if(n == a){
				printf("Second win\n");
				kase = 1;
				break;
			}
		}
		if(!kase)
			printf("First win\n");
		kase = 0;
		scanf("%f", &n);
	}
	return 0;
}