#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int K, N, R;
struct  Road{
	int d, L, t;
};
vector< vector< Road> > G(110); //G[i]表示从i出发能够直接到达的所有城市
int minlen;					//最短路径
int totallen;				//当前已走路径
int totalcost;				//当前已花费金额
int visited[110];			//标记是否走过该城市
int minL[110][10005];		// minL[k][m]表示走到城市k时，在总过路费为m的条件下，最优路径的长度
void dfs(int s){
	if(s == N){
		minlen = min(minlen, totallen);
		return;
	}
	for(int i = 0; i < G[s].size(); i++){
		Road r = G[s][i];
		if(totalcost + r.t > K)	//判断走到下一个城市的钱是否够用
			continue;
		if(totallen + r.L >= minlen)		//剪枝：如果当前已经找到的最优路径为L，那么在继续搜索的过程中，若总长度大于等于L，则直接放弃
			continue;
		if(!visited[r.d]){
			if(totallen + r.L >= minL[r.d][totalcost + r.t]) // 记忆化： 在花费相同的钱走到相同的位置的时候，如果此时的路径长度超过当前记录的最小值的时候，直接放弃
				continue;
			minL[r.d][totalcost+r.t] = totallen + r.L;		// 	记录花费当前钱数走到的当前城市所需的最小路径的长度。
			visited[r.d] = 1;
			totalcost += r.t;
			totallen += r.L;
			dfs(r.d);
			visited[r.d] = 0;
			totallen -= r.L;
			totalcost -= r.t;
		}
	}
}
int main(int argc, char const *argv[]){
	scanf("%d %d %d", &K, &N, &R);
	for(int i = 0; i < R; i++){
		int s;
		Road r;
		scanf("%d %d %d %d", &s, &r.d, &r.L, &r.t);
		if(s != r.d)
			G[s].push_back(r);
	}
	for(int i = 0;i < 110; i++)
		for(int j = 0; j < 10005; j++)
			minL[i][j] = 1e9;
	memset(visited,0,sizeof(visited));
	minlen = 1e9;
	dfs(1);
	if(minlen != 1e9)
		printf("%d\n", minlen);
	else
		printf("-1\n");
	return 0;
}