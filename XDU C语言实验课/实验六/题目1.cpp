#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int m,n,kase = 0;
	scanf("%d %d",&m,&n);
	int a[m][n],p;
	srand(time(NULL));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = rand()%100;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
			printf("%d ",a[i][j] );
		printf("\n");
	}
	int min = a[0][0];
	for(int i = 0; i < m; i++){
		for(int j =0; j < n; j++){
			if(min > a[i][j+1]){
				min = a[i][j+1];
				p = j+1;
			}
		}
		int k;
		for(k  = 0; k < m; k++ )
			if(min < a[k][p]){
				kase = 1;
				break;
			}
		if(kase == 0)
			printf("a[%d][%d]\n", k,p);
	}
	return 0;
		
}