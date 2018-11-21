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
int totalcost;				//当前已花路费
int visited[110];			//标记是否走过该城市
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
int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &K, &N, &R);
	for(int i = 0; i < R; i++){
		int s;
		Road r;
		scanf("%d %d %d %d", &s, &r.d, &r.L, &r.t);
		if(s != r.d)
			G[s].push_back(r);
	}
	memset(visited,0,sizeof(visited));
	minlen = 1e9;
	dfs(1);
	if(minlen != 1e9)
		printf("%d\n", minlen);
	else
		printf("-1\n");
	return 0;
}