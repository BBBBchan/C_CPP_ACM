#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
struct room{
	int gx;
	int gy;
}point[6];
char maze[105][105];
int N,M;
int sx,sy;
int gx,gy;
int d[105][105];

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int bfs(){
	queue<P> que;
	memset(d,-1,sizeof(d));
	que.push(P(sx,sy));
	d[sx][sy]=0;

	while(que.size()){
		P p = que.front(); que.pop();
		if(p.first == gx && p.second == gy)	break;

		for(int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second+dy[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]!='#' && d[nx][ny] == -1){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}
int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &N, &M) != EOF){
		int ans = 100000000;
		if(N == M && N == 0)
			break;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++){
				cin >> maze[i][j];
				if(maze[i][j] == '@'){
					sx = i;
					sy = j;
				}
			}
		int num;
		scanf("%d", &num);
		int a[5] = {1,2,3,4,5};
		for(int i = 0; i < num; i++){
			scanf("%d %d", &point[i].gx, &point[i].gy);
		}
		int kase = 0,temp = 0,sx_0 = sx, sy_0 = sy;
		do{
			for(int i = 0; i < num; i++){
				gx = point[a[i]-1].gx-1;
				gy = point[a[i]-1].gy-1;
				int res = bfs();
				if(res == -1){
					kase = 1;
					break;
				}
				temp+= res;
				sx = gx;
				sy = gy;
			}
			if(kase == 1)
				break;
			if(ans > temp)
				ans = temp;
			temp = 0;
			sx = sx_0;
			sy = sy_0;
		}while(next_permutation(a,a+num));
		if(kase == 1)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}