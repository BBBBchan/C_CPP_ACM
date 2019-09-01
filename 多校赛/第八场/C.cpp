#include <cstdio>
int a[12][1025][1025];
int main(int argc, char const *argv[])
{
	a[1][1][1] = 1;
	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= (1 << i); j++ ){
			for(int k = 1; k <= (1 << i); k++){
				int now = (1<<(i-1));
				if(k > now && j > now){
					a[i+1][j][k] = -1*a[i][j-now][k-now];
				}
				else if(j > now && k <= now){
					a[i+1][j][k] = a[i][j-now][k];
				}
				else if(j <= now && k > now){
					a[i+1][j][k] = a[i][j][k-now];
				}
				else{
					a[i+1][j][k] = a[i][j][k];
				}
			}
		}
	}

	int m, i = 0;
	scanf("%d", &m);
	int temp  = m;
	while(temp > 0){
		temp/=2;
		i++;
	}
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <=m; k++){
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
	return 0;
}