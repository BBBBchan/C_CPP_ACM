#include <iostream>
#include <cstdio>
using namespace std;
int a[9][9],p,q;
bool flag;
char ch;
bool check(int x, int y,int m){
	for(p = 0; p < 9; p++){
		if(a[x][p] == m){
			return false;
			}
		}
	for(q = 0; q < 9; q++){
		if(a[q][y] == m)
			return false;
		}
	int grid_x = x-x%3;
	int grid_y = y-y%3;
	for(int i = grid_x; i < grid_x+3; i++)
		for(int j = grid_y; j < grid_y+3; j++){
			if(a[i][j] == m)
				return false;
		}
	return true;

}
void dfs(int i, int j){
	if(i==9 || flag){
		flag = true;
		return;
	}
	while(a[i][j] != 0){
		if(j == 8){
			i++;
			j = 0;
		}
		else
			j++;
		if(i == 9){
			flag = true;
			return;
		}
	}

	for(int m = 1; m <=9; m++){
		if(check(i,j,m)){
			a[i][j] = m;
			if(j == 8)
				dfs(i+1,0);
			else
				dfs(i,j+1);
			if(flag)
				return;
			a[i][j] = 0;
		}
	}
}
int main(int argc, char const *argv[])
{	int n;
	scanf("%d", &n);
	while(n--){
		flag = false;
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++){
				cin >> ch;
				a[i][j] = ch-'0';
			}
		dfs(0,0);
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}