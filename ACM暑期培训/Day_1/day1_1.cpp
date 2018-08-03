#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[m]={0};
	for(int i = 0; i < n; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		for(int j = start-1; j <= end-1; j++){
			a[j] = 1;
		}
	}
	int b[m], count = 0;
	for(int i = 0; i < m; i++){
		if(a[i] == 0){
			b[count] = i+1;
			count++;
		}
	}
	if(count != 0){
		printf("%d\n", count);
		for(int i = 0; i < count; i++){
			printf("%d ", b[i]);
		}
	}
	else
		printf("0\n");

	return 0;
}