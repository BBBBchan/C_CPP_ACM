#include <stdio.h>
#include <string.h>
#define INF 170
char a[INF],b[INF];
int num1[INF+1],num2[INF+1];
int main()
{	int len1,len2,i,j;
	gets(a);
	gets(b);
	memset(a, 0, sizeof(b));
	memset(b, 0, sizeof(b));
	len1 = strlen(a);
	len2 = strlen(b);
	for(i = len1 - 1,j=0;i>=0;i--)
		num1[j++] = a[i]-'0';
	for(i = len2 - 1,j=0;i>=0;i--)
		num2[j++] = b[i]-'0';
	for(i = 0;i<INF;i++)
	{
		num1[i] += num2[i];
		if(num1[i] > 9){num1[i] -=10;num1[i+1]++;}

	}
	for(i<INF-1;i>=0&&num1[i]!=0;i--);
	if(i>0)
		for(;i>=0;i--)
			printf("%d",num1[i]);
		else
			printf("0");

	return 0;
}