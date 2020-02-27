#include <cstdio>
int x1, y1, z1, x2, y2, z2;
int a[25][25][25];
int main(int argc, char const *argv[])
{
	int w, x, h, q;
	scanf("%d %d %d %d", &w, &x, &h, &q);
	for(int i = 0; i < q; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
		for(int j = x1; j<=x2; j++){
			for(int k = y1; k <=y2; k++){
				for(int t = z1; t <= z2; t++){
					a[j][k][t] = 1;
				}
			}
		}
	}
	int count1 = 0;
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= x; j++){
			for(int k = 1; k <= h; k++){
				if(a[i][j][k] == 0)
					count1++;
			}
		}
	}
	printf("%d\n",count1);
	return 0;
}