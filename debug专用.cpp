#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define N 100010
 
char s[N * 10], p[N];
int nextval[N];
int lens, lenp;
 
void getnext()
{
	int i = 0, j = -1;
	nextval[0] = -1;
	while(i != lenp)
	{
		if(j == -1 || s[i] == s[j])
			nextval[++i] = ++j;
		else
			j = nextval[j];
	}
	for(int i = 0; i < lenp; i ++)
		printf("%d ", nextval[i]);
	printf("\n"); 
}
 
int KMP()
{
	int i = 0, j = 0, count = 0;
	while(i != lens && j != lenp)
	{
		if(s[i] == p[j] || j == -1)
			++i, ++j;
		else
			j = nextval[j];
		if(j == lenp)
		{
			count++;
			j = nextval[j];
		}
	}
	return count;
}
 
int main()
{
	int ncase;
	int len;
	int ans;
	scanf("%d", &ncase);
	while(ncase--)
	{
		scanf("%s%s", p, s);
		lens = strlen(s);
		lenp = strlen(p);
		getnext();
		ans = KMP();
		printf("%d\n", ans);
	}
	return 0;
}

