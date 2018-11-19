#include <cstdio>
int a[105],b[105];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		b[i] = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		for(int j = 0; j < i; j++){
			if(a[j] < a[i]){
				b[i]++;
			}
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
	return 0;
}