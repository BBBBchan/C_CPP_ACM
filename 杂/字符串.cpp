#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int i = 5;
	int *p = &i, *q = &i;
	p = q;
	printf("%f  %f\n", *p,*q);	
	// char s[4];
	// scanf("%c, %c, %c",&s[0], &s[1], &s[2]);
	// printf("%s\n", s);
	// char a[] = "abc";
	// char b[10] = "defgh";
	// strcpy(b,a);
	// printf("%c\n",b[4]);
	// printf("%s\n",b );	
	return 0;
}