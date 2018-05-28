#include<stdio.h>
int main(void)
{
	char aa[10000];
	char bb[5000];
	int c = 0;

	scanf("%s",aa);
	for (int i = 0;i < 10000;i++)
	{
	if (aa[i] == 'm')
	{
	bb[c] = '0';
	c++;
	}
	if (aa[i] == 'n')
	{
	bb[c] = '1';
	c++;
	}
	}
	for(int i = 0; i < 5000; i++)
	printf("%c",bb[i]);
	return 0;

}



