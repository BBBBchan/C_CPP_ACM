#include <stdio.h>
int max = 0;
void compare(int *a, int start, int endl, int n){
	int i;
	if(start+endl >= n){
		return;
	}
	for(i = start; i < start+endl; i++){
		if(a[i] == a[endl+start])
			break;
	}
	if(endl >= max){
		if(endl + start == n-1){
			max = endl+1;
		}
		else max = endl;
	}
	if(i == start+endl){
		return compare(a, start, endl+1, n);
	}
	return;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		max = 0;
		if(n == 1){
			printf("1\n");
			continue;
		}
		for(int i = 0; i < n; i++){
			compare(a, i, 1, n);
		}
		printf("%d\n", max);
	}
	return 0;
}