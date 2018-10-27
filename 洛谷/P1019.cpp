#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, vis[105][105]={0}, ans[105][105]={0};
char stand[] = "yizhong", a[105][105];
void dfs(int nx, int ny, int now,int p, int q){
	if(stand[now] == 'g'){
		vis[nx][ny] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(vis[i][j] == 1)
					ans[i][j] = 1;
		// memset(vis,0,sizeof(int));
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < n; j++){
		// 		if(vis[i][j] == 1)
		// 			printf("%c",a[i][j]);
		// 		else
		// 			printf("*");
		// 	}
		// 	printf("\n");
		// }
		return;
	}
	int next_x = nx+p, next_y = ny+q; 
	if(0<=next_x && next_x<n && 0<=next_y && next_y<n && a[next_x][next_y] == stand[now+1]){
		vis[nx][ny] = 1;
		dfs(next_x,next_y,now+1,p,q);
		vis[nx][ny] = 0;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n ; j++)
			cin>>a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] == 'y'){
				for(int m = -1; m <= 1; m++)
					for(int n = -1; n <= 1; n++)
						if(a[i+m][j+n] == 'i')
							dfs(i,j,0,m,n);
			}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ans[i][j] == 1)
				printf("%c",a[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}