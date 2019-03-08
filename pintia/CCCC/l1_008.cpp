#include <cstdio>
int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	for(int i = 0; i < b-a+1; i+=5){
		for(int j = i; j < i+5 && j < b-a+1; j++){
			printf("%5d", a+j);
		}
		printf("\n");
	}
	printf("Sum = %d", (b-a+1)*(b+a)/2);
	return 0;
}