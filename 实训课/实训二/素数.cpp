#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int n,kase = 1;
	while(scanf("%d", &n) != EOF){
	for (int i = 2; i < sqrt(n)+1; i++)
	{
		if(n%i == 0){
			kase = 0;
			break;
		}
	}
	if(kase == 1)
		printf("yes\n");
	else
		printf("no\n");
}
	return 0;
}