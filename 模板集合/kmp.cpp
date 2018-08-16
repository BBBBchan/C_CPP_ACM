#include <stdio.h>
#include <string.h>
int next[10005],a[1000010],b[10005];
int m, n,temp;
void get_next(int *b){
	int b_len = n;
	int i = 0, j = -1;
	next[0] = -1;
	while(i < b_len){
		if(j == -1 || b[i] == b[j]){
			i++;
			j++;
			if(b[i] != b[j])
				next[i] = j;
			else
				next[i] = next[j];
		}
		else
			j = next[j];
	}
}
int kmp(int *a, int *b){
	get_next(b);
	int a_len = m;
	int b_len = n;
	int i = 0;
	int j = 0;
	while(i < a_len && j < b_len){
		if(j == -1 || a[i] == b[j]){
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j == b_len)
		return i - j;
	else
		return -1;
}
int main(int argc, char const *argv[])
{	
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d\n", &m, &n);
		for(int i = 0; i < m; i++){
			scanf("%d", &a[i]);
		}
		for(int j = 0; j < n; j++){
			scanf("%d", &b[j]);
		}
		int ans = kmp(a,b);
		if(ans != -1)
			printf("%d\n", ans+1);
		else
			printf("%d\n", ans);
	}
	return 0;
}