#include <cstdio>
#include <cstring>
long long int a[45];
int visited[45] = {0};
long long int n, k;
bool dfs(int i, long long int sum){
	if(sum > k)
		return false;
	if(i == n)
		return sum == k;
	if(dfs(i+1, sum)){
		visited[i] = 0;
		return true;
	}
	if(dfs(i+1, sum + a[i])){
		visited[i] = 1;
		return true;
	}
	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long int sum = 0;
		memset(visited,0,sizeof(visited));
		scanf("%lld %lld", &n, &k);
		for(int i =0; i < n; i++){ 
			scanf("%lld", &a[i]);
			if(a[i] > k){
				i--;
				n--;
			}
		}
		if(a[n-1]*2 < k)
			printf("-1\n");
		else if(dfs(0,0)){
			for(int i = 0; i < n; i++){
				if(visited[i] == 1){
					sum += (2<<(i));
				}
			}
			printf("%lld\n", sum);
		}
		else 
			printf("-1\n");
		
	}
	return 0;

}