#include <cstdio>
#include <iostream>
using namespace std;
char ma[55][55];
int n, m;
int book[55][55] = {0};
void dfs(int x, int y){
	book[x][y] = 1;
	if(x-1 >= 0 && ma[x-1][y] != 'W' && book[x-1][y] == 0)
		dfs(x-1,y);
	if(x+1 < n && ma[x+1][y] != 'W' && book[x+1][y] == 0)
		dfs(x+1, y);
	if(y-1 >= 0 && ma[x][y-1] != 'W' && book[x][y-1] == 0)
		dfs(x,y-1);
	if(y+1 < m && ma[x][y+1] != 'W' && book[x][y+1] == 0)
		dfs(x,y+1);
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ma[i][j];
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j  < m; j++){
			if(ma[i][j] == 'L' && book[i][j] != 1){
				dfs(i,j);
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}