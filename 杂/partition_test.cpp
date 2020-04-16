#include <cstdio>
int n;
int partition(int a[], int p, int r){
	int x = a[r];
	int i = p-1;
	for(int j = p; j <= r-1; j++){
		if(a[j] <= x){
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		for(int k = 1; k <= n; k++)
			printf("%d ", a[k]);
		printf("\n");
		}
		
	}
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	for(int k = 1; k <= n; k++)
			printf("%d ", a[k]);
	return i+1;
}
int main(int argc, char const *argv[])
{
	
	scanf("%d", &n);
	int a[1000];
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int ans = partition(a, 1, 12);
	return 0;
}