#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int visited[30][50];
int dfs(int i, int j, int n){
	if(n == 0)
		return 1;
	visited[i][j] = 1;
	int num = 0;
	if(!visited[i][j-1])
		num+=dfs(i,j-1,n-1);
	if(!visited[i][j+1])
		num+=dfs(i,j+1,n-1);
	if(!visited[i+1][j])
		num+=dfs(i+1,j,n-1);
	visited[i][j] = 0;
	return num;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << dfs(0,30,n) << endl;
	return 0;
}