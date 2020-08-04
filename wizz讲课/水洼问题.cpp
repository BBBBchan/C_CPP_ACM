#include <iostream>
using namespace std;
char field[100][100];
int n, m, ans = 0;
void dfs(int i, int j){
	field[i][j] = '.';
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			int nx = i+dx, ny = j+dy;
			if(nx >= 0 && nx < n && ny >= 0 
				&& ny<m && field[nx][ny] == 'W')
				dfs(nx,ny);
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> field[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(field[i][j] == 'W'){
				dfs(i,j);
				ans++;
			}
	cout << ans<< endl;
	return 0;
}