#include <stdio.h>
int main(){
	int r, g, b;
	char m,n,k;
	while(scanf("(%d, %d, %d)\n",&r, &g, &b) != EOF){
		printf("#%02X%02X%02X\n",r,g,b);
	}
	return 0;
}