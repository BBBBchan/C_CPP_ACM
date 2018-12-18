#include <cstdio>
#include <ctime>
#include<cstdlib>
int a[10000];
int ans=0;
void BuluBulu(int *a, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(a[i] > a[j]){
				ans++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void select(int *a, int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

void insert(int *a, int n){
	int key;
	for(int i = 1; i < n; i++){
		key = a[i];
		int j = i-1;
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
int main(int argc, char const *argv[])
{
	int n;
//	srand((unsigned)time(NULL));
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);9
//		a[i] = rand();
	BuluBulu(a,n);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n%d",ans);
	return 0;
}