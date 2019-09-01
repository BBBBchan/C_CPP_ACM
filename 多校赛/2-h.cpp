#include<cstdio>
#include<cstring>
#include <iostream>
#include <map>
#define N 10000
using namespace std;
int x[N], y[N];
int n;
void find()
{
	int p, q;
	for(int a = 0; a < n ; a++)
	{
		for(int b = n-1; b >= 0; b--)
		{	p = 0;
			q = 0;
 			if(x[a] == x[b] && y[a] == y[b])
 				continue;
 			int A = (y[b]-y[a]), B = (x[a]- x[b]);
			int  ans1x = x[a]+400000*B+1, ans1y = y[a]-400000*A;
			int  ans2x = x[b]-400000*B-1, ans2y = y[b]+400000*A;
			if(A == 0){
				ans1y -= 1;
				ans2y += 1;
			}
			for(int i = 0; i < n; i++)
			{
				long long k = (ans2y - ans1y) * x[i] + (ans1x - ans2x) * y[i] + (ans2x*ans1y - ans1x*ans2y );
				if(k > 0)		p++;
				else if(k < 0)	q++;
				else break;
				if(p > n/2) break;
				if(q > n/2) break;
				if(i == n - 1 && p == q)	
				{
					printf("%d %d %d %d\n",ans1x, ans1y, ans2x, ans2y);
					return;
				}
			}
		}
	}
}
 
int main( )
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		for(int i = 0; i < n; i++){
			scanf("%d%d", &x[i], &y[i]);
		}
		find();
	}
	return 0;}