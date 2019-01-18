#include <cstdio>
int a[10000];
void quick_sort(int *a, int left, int right){
	if(left >= right)
		return;
	int i = left, j = right;
	int key = a[left];
	while(i < j){
		while(i < j && a[i] < key)
			i++;
		while(i < j && a[j] > key)
			j--;
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	quick_sort(a,left, i-1);
	quick_sort(a,i+1,right);
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quick_sort(a,0, n-1);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}