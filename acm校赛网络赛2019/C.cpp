#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char a[205][205];
int dis_x[205][205]={0};
int dis_y[205][205]={0};
int visited[205][205] = {0};
int n, m;
void bfs(int x, int y, int dis[][205]){
	dis[x][y] = 0;
	queue <pair<int, int>> q;
	pair <int, int> now;
	now.first = x;
	now.second = y;
	q.push(now);
	while(!q.empty()){
		pair <int, int> cur = q.front();
		pair <int, int> temp;
		q.pop();
		if(visited[cur.first][cur.second] == 0 && a[cur.first][cur.second] != '#'){
			visited[cur.first][cur.second] = 1;
			if(cur.first+1 <= n-1 && visited[cur.first+1][cur.second] == 0 && a[cur.first+1][cur.second] != '#'){
				temp.first = cur.first+1;
				temp.second = cur.second;
				q.push(temp);
				dis[temp.first][temp.second] = dis[cur.first][cur.second]+1;
			}
			if(cur.first-1 >= 0 && visited[cur.first-1][cur.second] == 0 && a[cur.first-1][cur.second] != '#'){
				temp.first = cur.first-1;
				temp.second = cur.second;
				q.push(temp);
				dis[temp.first][temp.second] = dis[cur.first][cur.second]+1;
			}
			if(cur.second+1 <= m-1 && visited[cur.first][cur.second+1] == 0 && a[cur.first][cur.second+1] != '#'){
				temp.first = cur.first;
				temp.second = cur.second+1;
				q.push(temp);
				dis[temp.first][temp.second] = dis[cur.first][cur.second]+1;
			}
			if(cur.second-1 >= 0 && visited[cur.first][cur.second-1] == 0 && a[cur.first][cur.second-1] != '#'){
				temp.first = cur.first;
				temp.second = cur.second-1;
				q.push(temp);
				dis[temp.first][temp.second] = dis[cur.first][cur.second]+1;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d %d", &n, &m) != EOF){
		memset(visited,0,sizeof(visited));
		memset(dis_x,-1,sizeof(dis_x));
		memset(dis_y,-1,sizeof(dis_y));
		int ans = 1000000;
		pair <int, int> pos_x;
		pair <int, int> pos_y;
		vector <pair<int ,int>> P;
		pair <int, int> final;
		for (int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
				if(a[i][j] == 'X'){
					pos_x.first = i;
					pos_x.second = j; 
				}
				else if(a[i][j] == 'Y'){
					pos_y.first = i;
					pos_y.second = j;
				}
				else if(a[i][j] == 'P'){
					pair <int, int> temp;
					temp.first = i;
					temp.second = j;
					P.push_back(temp);
				}
			}
		}
		bfs(pos_x.first,pos_x.second,dis_x);
		memset(visited,0,sizeof(visited));
		bfs(pos_y.first,pos_y.second,dis_y);
		for(int i = 0; i < P.size(); i++){
			if(dis_y[P[i].first][P[i].second] < 0 || dis_x[P[i].first][P[i].second] < 0)
				continue;
			if(ans > max(dis_y[P[i].first][P[i].second], dis_x[P[i].first][P[i].second])){
				ans = max(dis_y[P[i].first][P[i].second], dis_x[P[i].first][P[i].second]);
				final.first = P[i].first;
				final.second = P[i].second;
			}
		}
		printf("%d %d\n", final.first+1, final.second+1);
	}
	return 0;
}