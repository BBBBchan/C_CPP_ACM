#include <cstdio>
#include <algorithm>
using namespace std;
int n,a,b,c,d,i;
int cmp(int a, int b){
	return a > b;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	int sum[n];
	for(i = 0; i < n; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		sum[i] = a+b+c+d;
	}
	int ans = sum[0];
	sort(sum,sum+n,cmp);
	for(i = 0; i < n; i++){
		if(sum[i] == ans)
			break;
	}
	printf("%d", i+1);
	return 0;
}