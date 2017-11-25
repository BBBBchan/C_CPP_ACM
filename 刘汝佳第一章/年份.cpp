#include <stdio.h>
int main()
{
	int year ;
	scanf("%d", &year);
	if((year % 400) == 0)
		printf("yes");
	else if(((year % 100) == 0) ||((year % 4) != 0))
		printf("no");
	else
		printf("yes");
	return 0 ;

}