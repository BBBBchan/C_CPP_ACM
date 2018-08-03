#include <stdio.h>
int main(){
	int c;
	scanf("%d", &c);
	while(c--){
		int n, m;
		scanf("%d %d", &n, &m);
		if(n%(m+1) == 0)
			printf("Rabbit\n");
		else
			printf("Grass\n");
	}
	return 0;
}