#include <cstdio>
int n, m, t, sx, sy, fx, fy, ans = 0,temp1, temp2;
int stop[10][10], vis[10][10]={0};
int dx[4] = {1,0,0,-1}, dy[4]={0,1,-1,0};
void dfs(int x, int y){
	if(x==fx && y==fy){
		ans++;
		return;
	}
	for(int i = 0; i<4 ; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(1<=nx && nx<=n && 1<=y && ny<=m){
				if(stop[nx][ny] == 0 && vis[nx][ny] == 0){
					vis[nx][ny] = 1;
					dfs(nx,ny);
					vis[nx][ny] = 0;
				}
			}
		}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d %d %d %d %d %d", &n, &m, &t, &sx, &sy, &fx, &fy);
	for(int i = 0; i < t; i++){
		scanf("%d %d", &temp1, &temp2);
		stop[temp1][temp2] = 1;
	}
	vis[sx][sy] = 1; 
	dfs(sx,sy);
	printf("%d\n", ans);
	return 0;
}