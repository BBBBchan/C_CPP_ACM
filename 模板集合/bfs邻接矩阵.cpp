/*BFS邻接矩阵*/
/*BFS邻接矩阵版，n*m的矩阵表示图，1表示有边，0表示无边，使用方法：bfs(i)，从第i个节点开始bfs，直到遍历整个联通区块*/
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
queue <int> qe;
int vis[120] = {0};
int a[120][120];
void bfs(int i){
	int cur;
	while(!qe.empty()){
		cur = qe.front();
		if(vis[cur] == 0){
			printf("%d ", cur+1);
			vis[cur] = 1;
			qe.pop();
			for(int j = 0; j < n; j++){
				if(a[cur][j] == 1)
					qe.push(j);
			}
		}
		else
			qe.pop();
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++){
		if(vis[i] == 0){
			qe.push(i);
			bfs(i);
		}
	}
	return 0;
}