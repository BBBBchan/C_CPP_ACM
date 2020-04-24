#include <cstdio>
int a[100005], b[1000005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		if(b[i] == 2)
			continue;
		for(int j = i; j <n; j++){
			if((a[i]&a[j]) == 0){
				b[i] = 2;
				b[j] = 2;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", b[i]-1);
	}
	return 0;
}