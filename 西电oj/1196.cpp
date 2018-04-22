#include <stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n < 1000)
			printf("XiaoZhen\n");
		else if(n < 10000)
			printf("Zh0ngshen\n");
		else
			printf("DaNuo\n");
		
	}
	return 0;
}