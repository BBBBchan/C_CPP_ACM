#include <cstdio>
struct item
{
	int v[10];
}items[100005];
int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
			scanf("%d", &items[i].v[j]);
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int now = items[i].v[k-1]+items[j].v[k-1], kase = 1;
			for(int x = 0; x < k; x++){
				if(items[i].v[x] + items[j].v[x] != now){
					kase = 0;
					break;
				}
			}
			if(kase)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}