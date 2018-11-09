#include <stdio.h>
#include <math.h>
int n,m,k;
int check(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= n)
		return 0;
	return 1;
}
int main(int argc, char const *argv[]){
	scanf("%d %d %d", &n, &m, &k);
	int a[300][300] = {0};
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int tempx=-2; tempx <= 2; tempx++)
			for(int tempy = -2; tempy <= 2; tempy++)
				if(check(x-1+tempx, y-1+tempy) && abs(tempx)+abs(tempy) <= 2){
					a[x-1+tempx][y-1+tempy] = 1;
				}
	}
	for(int j = 0; j < k; j++){
		int x, y;
		scanf("%d %d", &x, &y);
		for(int tempx = -2; tempx <= 2; tempx++)
			for(int tempy = -2; tempy <= 2; tempy++)
				if(check(x-1+tempx,y-1+tempy))
					a[x-1+tempx][y-1+tempy] = 1;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != 1)
				count++;
	printf("%d", count);
	return 0;
}