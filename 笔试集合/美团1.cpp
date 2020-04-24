#include <cstdio>
#include <algorithm>
using namespace std;

struct pos
{
	int x;
	int y;
	int num;
}starsx[2005], starsy[2005];
bool cmp1(pos a, pos b){
	if(a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}
bool cmp2(pos a, pos b){
	if(a.y != b.y)
		return a.y < b.y;
	else
		return a.x < b.x;
}
int bookx[2005] = {0}, booky[2005] = {0}, ans = 0;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d %d", &starsx[i].x, &starsx[i].y);
		starsx[i].num = i;
		starsy[i].x = starsx[i].x;
		starsy[i].y = starsx[i].y;
		starsy[i].num = i;
	}
	sort(starsx, starsx+n, cmp1);
	sort(starsy, starsy+n, cmp2);
	for(int i = 1; i < n-1; i++){
		if(starsx[i-1].x == starsx[i].x && starsx[i].x == starsx[i+1].x){
			if(starsx[i-1].y < starsx[i].y && starsx[i].y < starsx[i+1].y ){
				bookx[starsx[i].num] = 1;
				// printf("%d\n", starsx[i].num);
			}
		}
	}
	for(int i = 1; i < n-1; i++){
		if(starsy[i-1].y == starsy[i].y && starsy[i].y == starsy[i+1].y){
			if(starsy[i-1].x < starsy[i].x && starsy[i].x < starsy[i+1].x ){
				booky[starsy[i].num] = 1;
				// printf("%d\n", starsy[i].num);
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(booky[i] == 1 && bookx[i] == 1){
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}