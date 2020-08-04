#include <cstdio>
int f[10000005] = {0};
int visited[10000005] = {0};
int find(int x)
{
    
    if (f[x]==x) 
        return x;
    else{
        f[x]=find(f[x]);
        return f[x];
    }
}
int main(int argc, char const *argv[])
{	
	int t;
	scanf("%d", &t);
	while(t--){
		int n, ans = 0, x, y, a, a_len, b, b_len;
		scanf("%d", &n);
		for(int i  = 0; i < 10000005; i++){
			f[i] = i;
			visited[i] = 0;
		}
		for(int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			a = find(x);
			b = find(y);
			if(a != b){
				f[a] = b;
			}
		}
		for(int i = 0; i < 7; i++){
			int temp = find(i);
			visited[temp]++;
			if(visited[temp] > ans){
				ans = temp;
			}
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}