#include <cstdio>
#include <algorithm>
#include <cmath>
#define inf 1e9+7
using namespace std;
int a[50000], cnt = 0;
void init()
{
    for(int i = 0;i<=32;i++)
	{
		if(pow(2.0,i)>=inf)
			break;
		for(int j = 0;j<=32;j++)
	    {
			if(pow(2.0,i)*pow(3.0,j)>=inf)
				break;
			for(int k = 0;k<=32;k++)
			{
				if(pow(2.0,i)*pow(3.0,j)*pow(5.0,k)>=inf)
					break;
				for(int l = 0;l<=32;l++)
				{
					if(pow(2.0,i)*pow(3.0,j)*pow(5.0,k)*pow(7.0,l)>=inf)
						break;
					a[cnt++]=pow(2.0,i)*pow(3.0,j)*pow(5.0,k)*pow(7.0,l);
				}
			}
		}
	}
	sort(a,a+cnt);
}
int main(int argc, char const *argv[])
{
	int t;
	init();
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int ans = a[lower_bound(a,a+cnt,n)-a];
		printf("%d\n", ans);
	}
	return 0;
}