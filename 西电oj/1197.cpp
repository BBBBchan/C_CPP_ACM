#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char a[10];
	while(scanf("%s", a) != EOF){
		if(strstr(a,"v8"))
			printf("SingleDog&YangRouHuoGuo\n");
		else if(strstr(a,"qsqx"))
			printf("Couple&Program\n");
		else if(strstr(a,"lbz007"))
			printf("SingleDog&GoodGoodStud\n");
		memset(a,0,sizeof(a));
	}	
	return 0;
}