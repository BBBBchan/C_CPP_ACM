#include <stdio.h>
int main(){
	int r, g, b;
	char m,n,k;
	while(scanf("%c%d, %d, %d%c%c",&m,&r, &g, &b,&n,&k) != EOF){
		printf("#%02X%02X%02X\n",r,g,b);
	}
	return 0;
}