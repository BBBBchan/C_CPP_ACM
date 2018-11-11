#include <cstdio>
#include <algorithm>
using namespace std;
struct info{
	int num;
	int score;
}a[5005];
bool cmp(info a, info b){
	if(a.score != b.score)
		return a.score > b.score;
	else
		return a.num < b.num;
}
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a[i].num, &a[i].score);
	}
	sort(a,a+n,cmp);
	int x = (m*3)/2;
	while(a[x-1].score == a[x].score)
		x++;
	printf("%d %d\n",a[x-1].score, x);
	for(int i = 0; i < x; i++)
		printf("%d %d\n", a[i].num, a[i].score);
	return 0;
}