#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000];
int main(int argc, char const *argv[])
{
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n);
	int ansl = -1, ansr = -1, kase = 0;
	for(int i = 0; i < n; i++){
		int left = i+1, right = n-1;
		// printf("%d %d %d\n", i, left,right);
		if(kase){break;}
		while(right >= left){
			int mid = left + (right-left)/2;
			if(a[i] + a[mid] > x){
				right = mid-1;
			}
			else if(a[i] + a[mid] < x){
				left = mid+1;
			}
			else{
				ansl = i;
				ansr = mid;
				kase = 1;
				break;
			}
			
		}
		// printf("%d %d\n", ansl, ansr);
	}
	printf("%d %d\n", ansl, ansr);
	return 0;
}