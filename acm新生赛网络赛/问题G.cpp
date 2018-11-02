#include <cstdio>
int parent[200050];
void init(int n){
	for(int i = 0; i <= 2*n+2; i++)
		parent[i] = i;
}

int find(int x){
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void union_(int x, int y){
	x = find(x);
	y = find(y);
	parent[x] = y;
}
bool check(int x, int y)
{
    x = find(x);
    y = find(y);
    return x == y;
}
int main(int argc, char const *argv[]){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		init(n);
		int a, b, c;
		while(m--){
			scanf("%d %d %d", &a, &b, &c);
			if(a == 0){
				if(b == c)
					continue;
				else if(check(b,c) || check(b+n,c+n) || check(b,c+n) || check(b+n,c))
					continue;
				union_(b,c+n);
				union_(b+n,c);
			}
			else if(a == 1){
				if(check(b,c) || check(b+n,c+n))
					printf("In the same category.\n");
				else if(check(b,c+n) || check(b+n,c))
					printf("In different category.\n");
				else
					printf("Not sure yet.\n");
			}
		}
	}
	return 0;
}