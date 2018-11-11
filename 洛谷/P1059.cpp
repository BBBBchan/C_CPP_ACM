#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, a[120];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int temp,kase = 1;
		scanf("%d",&temp);
		for(int j = 0; j < i; j++){
			if(temp == a[j]){
				kase = 0;
				n--;
				i--;
				break;
			}
		}
		if(kase){
			a[i] = temp;
		}
	}
	sort(a,a+n);
	printf("%d\n", n);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}