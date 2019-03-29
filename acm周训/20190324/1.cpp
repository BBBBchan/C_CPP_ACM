#include <cstdio>
#include <cstring>
#include <cmath>
int a[10005],b[10005], c[10005], ans[10005];
int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);}
	for(int i = 0; i < n; i++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		int temp = a[i],j = 0;
		c[0] = 0;
		while(temp!= 0){
			if(temp%2 == 1){
				b[j] = 1;
			}
			else{
				b[j] = 0;
			}
			temp/=2;
			j++;
		}
		ans[0] = b[0];
		for(int k = 0; k < j-1; k++){
			if(ans[k] == b[k+1])
				ans[k+1] = 0;
			else
				ans[k+1] = 1;
		}

		int m = 0,fin = 0;
		for(int k = 0; k<j; k++){
			fin += ans[k]<<m;
			m++;
		}
		if(i != n-1)
			printf("%d ", fin);
		else
			printf("%d", fin);
	}
	return 0;
}