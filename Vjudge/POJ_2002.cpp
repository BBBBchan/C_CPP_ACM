#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
struct location
{
	int x;
	int y;
}a[1000],temp1,temp2;
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF && n!=0){
		for(int i = 0; i < n; i++)
			scanf("%d %d", &a[i].x, &a[i].y);
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n && i != j; j++){
				temp1.x = a[i].x + a[i].y - a[j].y;
				temp1.y = a[i].y + a[j].x - a[i].x;
				temp2.x = a[j].x + a[i].y - a[j].y;
				temp2.y = a[j].y + a[j].x - a[i].x;
 				for(int k = 0; k < n; k++)
					if(temp1.x == a[k].x && temp1.y == a[k].y)
						for(int m = 0; m < n; m++)
							if(temp2.x == a[m].x && temp2.y == a[m].y)
								ans++;
			}
		printf("%d\n", ans/2);
	}
	return 0;
}