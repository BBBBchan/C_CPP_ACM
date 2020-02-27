#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int num;
	int index;
}a[1000];
bool cmp(node a, node b){
	return a.num < b.num;
}
int main(int argc, char const *argv[])
{
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].num);
		a[i].index = i;
	}
	sort(a,a+n,cmp);
	int ansl = -1, ansr = -1, kase = 0;
	for(int i = 0; i < n; i++){
		int left = i+1, right = n-1;
		// printf("%d %d %d\n", i, left,right);
		if(kase){break;}
		while(right >= left){
			int mid = left + (right-left)/2;
			if(a[i].num + a[mid].num > x){
				right = mid-1;
			}
			else if(a[i].num + a[mid].num < x){
				left = mid+1;
			}
			else{
				ansl = a[i].index;
				ansr = a[mid].index;
				kase = 1;
				break;
			}
			
		}
		// printf("%d %d\n", ansl, ansr);
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}