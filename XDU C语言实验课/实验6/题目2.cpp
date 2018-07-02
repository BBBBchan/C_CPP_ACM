#include <stdio.h>
void sum(int **a, int **b,int m,int n,int **c){
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j++)
			*((int *)c + i * n + j) = *((int *)a + i * n + j) + *((int *)b + i * n + j);
}
void zhuanzhi(int **a, int **d, int m, int n){
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			*((int *)d +j * m + i) = *((int *)a + i * n + j);
}
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int a[m][n],b[m][n],c[m][n],d[n][m];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&b[i][j]);
	sum((int **)a,(int **)b,m,n,(int **)c);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%d ",c[i][j] );
		printf("\n");
	}
	zhuanzhi((int **)a,(int **)d,m,n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	return 0;
}