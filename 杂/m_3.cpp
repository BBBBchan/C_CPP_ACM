#include <stdio.h>
int main(int argc, char const *argv[])
{
	double i;
	scanf("%lf", &i);
	if(i <= 50)
		printf("%.2lf\n", i*0.53);
	else
		printf("%.2lf\n", 50*0.53+(i-50)*(0.53+0.05));
	return 0;
}