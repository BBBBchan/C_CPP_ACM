#include <cstdio>
#include <algorithm>
using namespace std;
struct l
{
	int a;
	int b;
	int s;
	int p[25];
}line[25];
int cmp(l &x, l &y){
	return x.s < y.s;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &line[i].a, &line[i].b, &line[i].s);
		for(int j = 0; j < line[i].s; j++)
			scanf("%d", &line[i].p[j]);
	}
	sort(line,line+n,cmp);
	for(int i = 0; i < n; i++)
		printf("%d %d %d\n", line[i].a, line[i].b, line[i].s);
	return 0;
}