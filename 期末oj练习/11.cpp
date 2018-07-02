#include <stdio.h>
int main(){
	int a,b;
	while((scanf("%d %d",&a,&b) == 2) && !(a == 0 && b == 0)){
		while(b != 0){
			int n = a % b;
			a = b;
			b = n;
		}
		printf("%d\n",a);
	}
	return 0;
}
