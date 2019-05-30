#include <cstdio>
using namespace std;
int ans[5003] = {0};
int max=0, max_n;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ans[a]++;
	}
	for(int i = 0; i < n; i++){
		if(ans[i] > max){
			max = ans[i];
			max_n = i;
		}
	}
	int fin = max;
	max =0;
	ans[max_n] = 0;
	for(int i = 0; i < n; i++){
		if(ans[i] > max){
			max = ans[i];
		}
	}
	fin+=max;
	printf("%d", fin);
	return 0;
}