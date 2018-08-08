#include <stdio.h>
int main(int argc, char const *argv[])
{
	float sum = 0.0, mon;
	for(int i = 0; i < 12; i++){
		scanf("%f",&mon);
		sum = sum+ mon/12.0;
	}
	printf("$%.2f", sum);
	return 0;
}