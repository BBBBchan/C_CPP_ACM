#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int stamps[30], need, pkind, pnum, pval,type;
int pre[4], cur[4];
int ans;
void dfs(int k, int lkind, int ckind, int cnum, int cval, int cost){
	if(cnum>4 || (cnum == 4 && cost != need))
		return;
	if(cost == need){
		if(pkind == 0 || ckind > pkind || (ckind == pkind && cnum<pnum) || (ckind == pkind && cnum == pnum && cval > pval)){
			pkind = ckind;
			pnum = cnum;
			pval = cval;
			for(int i = 0; i < cnum; i++)
				pre[i] = cur[i];
			ans = 1;
		}
		else if(ckind == pkind && cnum == pnum && cval == pval)
			ans++;
		return;
	}
	for(int i = k; i < type; i++){
		if(cost+stamps[i] > need)
			break;
		int tkind = ckind, tval = cval;
		if(lkind != i)
			tkind++;
		if(cval < stamps[i])
			tval = stamps[i];
		cur[cnum] = stamps[i];
		dfs(i,i,tkind,cnum+1,tval,cost+stamps[i]);
	}
}
int main(int argc, char const *argv[])
{
	while(scanf("%d", &stamps[0]) != EOF){
		type = 0;
		while(stamps[type] != 0){
			scanf("%d", &stamps[++type]);
		}
//		sort(stamps, stamps+type);					//题目给的数据是排好序的，不需要自己排序
		while(scanf("%d", &need) && need){
			pkind = pnum = pval = 0;
			ans = 1;
			dfs(0,-1,0,0,0,0);
			if(pkind == 0)
				printf("%d ---- none\n", need);
			else if(ans > 1)
				printf("%d (%d): tie\n", need, pkind);
			else{
				printf("%d (%d): ", need, pkind);
				for(int i = 0; i < pnum-1; i++)
					printf("%d ", pre[i]);
				printf("%d\n", pre[pnum-1]);
			}
		}
	}
	return 0;
}