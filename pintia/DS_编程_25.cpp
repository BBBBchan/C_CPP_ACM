#include <cstdio>
int a[100005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int p, q, j = 0;
	scanf("%d %d", &p, &q);
	for(int i = 0; i < n; i++){
		if(a[i] < p || a[i] > q){
			a[j] = a[i];
			j++;
		}
	}
	for(int i = 0; i < j-1; i++)
		printf("%d ", a[i]);
	printf("%d", a[j-1]);
	return 0;
}