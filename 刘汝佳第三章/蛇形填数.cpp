#include <stdio.h>
#include <string.h>
#define maxn 20
int a[maxn] [maxn];
int main()
{
	int n,x = 0, y= 0, tot = 1;
	scanf("%d",&n);
	a[0][0] = 1;
	while(tot < n*n){
		while(y+1<n && !a[x][y+1])  {a[x][++y] = ++tot;} //一直向右
		while(x+1<n && !a[x+1][y])  {a[++x][y] = ++tot;} //一直向下 
		while(y-1>=0 && !a[x][y-1]) {a[x][--y] = ++tot;} //一直向左 
		while(x-1>=0 && !a[x-1][y]) {a[--x][y] = ++tot;} //一直向上 
	}
	for(x = 0; x < n; x++){
		for(y = 0; y < n; y++)
			printf("%3d",a[x][y]);
		if(x != n-1)
			printf("\n");
	}
	return 0;
}
