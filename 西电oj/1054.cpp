#include <stdio.h>
#include <string.h>
int main(){
	char n[1000000];
	while(scanf("%s", &n) != EOF){
		int sum = 0;
		for(int i = 0; i < strlen(n); i++){
			if(n[i] == 8)
				sum += 2;
			else if(n[i] == 0 || n[i] == 9 || n[i] == 6)
				sum++;
		}
		printf("%d\n", sum);
		memset(n,0,sizeof(n));
	}
	return 0;
}