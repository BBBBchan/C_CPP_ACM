#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
char maze[105][105];
int N, M;
int sx, sy;
int gx, gy;
int d[105][105], d_ox[105][105];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int ox;
int bfs_ox(int sx, int sy){
	queue<P> que;
	memset(d_ox,-1,sizeof(d));
	que.push(P(sx,sy));
	d_ox[sx][sy]=0;
	int kase = 0,i,j;
	while(que.size()){
		P p = que.front(); que.pop();
		for(i = 0; i < N; i++){
			for(j = 0; j < M; j++){
				if(maze[i][j] == 'B' && p.first == i && p.second == j){
					kase = 1;
					break;
				}
			}
			if(kase)
				break;		
		}
		if(kase)
			break;
		for(int i = 0; i < 4; i++){
			int nx = p.first + dx[i], ny = p.second+dy[i];
			if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='.' && d_ox[nx][ny] == -1){
				que.push(P(nx,ny));
				d_ox[nx][ny] = d_ox[p.first][p.second] + 1;
			}
			else if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='P' && d_ox[nx][ny] == -1){
				que.push(P(nx,ny));
				d_ox[nx][ny] = d_ox[p.first][p.second];
			}
		}
	}
	return d_ox[i][j];
}

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
			if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='.' && d[nx][ny] == -1){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
			else if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='#' && d[nx][ny] == -1 && ox>0 && ox < 6){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 2;
				ox--;
			}
			else if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='P'&& d[nx][ny] == -1){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second];
			}
			else if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='B'&& d[nx][ny] == -1){
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
				ox++;
			}
			else if(0<=nx && nx<N && 0<=ny && ny<M && maze[nx][ny]=='#' && d[nx][ny] == -1 && ox==0){
				que.push(P(nx,ny));
				int temp = bfs_ox(nx,ny);
				printf("%d 	", temp);
				d[nx][ny] = d[p.first][p.second] + 2*temp;
			}
		}
	}
	return d[gx][gy];
}

int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &N, &M) != EOF){
		if(N==0 && M == 0)
			break;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++){
				cin>>maze[i][j];
				if(maze[i][j] == 'S'){
					sx = i;
					sy = j;
				}
				else if(maze[i][j] == 'T'){
					gx = i;
					gy = j;
				}
			}
		ox = 0;
		int res = bfs();
		printf("%d\n", res);
	}
	return 0;
}