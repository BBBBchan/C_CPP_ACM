#include <cstdio>
int f[100005], b[100005]={0};
int find(int x)//并查集
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
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		f[i] = i;
	char kase;
	while(scanf("%c", &kase) != EOF && kase != 'S'){
		int a, b;
		scanf("%d %d", &a, &b);
		if(kase == 'I'){
			int u = find(a);
			int v = find(b);
			if(u == v)
				continue;
			else
				f[u] = v;
		}
		else if(kase == 'C'){
			int u = find(a);
			int v = find(b);
			if(u == v){
				printf("yes\n");
			}
			else
				printf("no\n");
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		int u = find(i);
		if(b[u] == 0){
			count++;
			b[u] = 1;
		}
	}
	if(count != 1)
		printf("There are %d components.\n", count);
	else
		printf("The network is connected.\n");
	return 0;
}