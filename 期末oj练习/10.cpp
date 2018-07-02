#include <stdio.h>
int main(){
	int a,b;
	int k = 0;
	scanf("%d %d",&a,&b);
	for(int i = a; i <= b; i++){
		k = 0;
		for(int j = 1;j < i; j++){
			if(i%j == 0)
				k += j;
		}
		if(k == i)
			printf("%d\n",i);
	}
	return 0;
}
