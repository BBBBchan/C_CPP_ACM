#include <cstdio>
#include <algorithm>

using namespace std;
int degrees_l[200005], degrees_r[200005];
int main(int argc, char const *argv[])
{
	int n, m, k, l, r;
	while(scanf("%d %d %d", &n, &m, &k) != EOF){
		int kase = 1;
		scanf("%d %d", &l, &r);
		for(int i = 0; i < k; i++){
			scanf("%d %d", &u, &v);
			degrees_l[u]++;
			degrees_r[v]++;
		}
		for(int i = 0; i < l; i++){
			if(degrees_l[i] < l){
				kase = 0;
				break;
			}
		}
		for(int j = 0; j < r; j++){
			if(degrees_r[j] < l){
				kase = 0;
				break;
			}
		}
		if(kase)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}