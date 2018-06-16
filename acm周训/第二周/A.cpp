#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF && m*n != 0){
		int a[n][m];
		int max = -400000,x,y;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++){
				int temp = 0;
				if(i-1 >= 0){
					if(a[i-1][j]*a[i][j] < 0)
						temp += abs(a[i-1][j]);
					else
						temp -= abs(a[i-1][j]);
					}
				if(i+1 < n){
					if(a[i+1][j] * a[i][j] < 0)
						temp += abs(a[i+1][j]);
					else
						temp -= abs(a[i+1][j]);
				}
				if(j-1 >= 0){
					if(a[i][j-1]*a[i][j] < 0)
						temp += abs(a[i][j-1]);
					else 
						temp -= abs(a[i][j-1]);
				}
				if(j+1 < m){
					if(a[i][j+1]*a[i][j] < 0)
						temp += abs(a[i][j+1]);
					else
						temp -= abs(a[i][j+1]);
				}
				if(temp > max){
				x = i;
				y = j;
				max = temp;
				}
		}
		printf("%d %d %d\n", x+1, y+1, max);	
	}
	return 0;
}