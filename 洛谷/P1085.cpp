#include <cstdio>
int main(int argc, char const *argv[])
{
	int a, b,kase,max = 0;
	for(int i = 1; i <= 7; i++){
		scanf("%d %d", &a, &b);
		if(b+a > max){
			max = b+a;
			kase = i;
		}
	}
	if(max > 8)
		printf("%d\n", kase);
	else
		printf("0\n");
	return 0;
}