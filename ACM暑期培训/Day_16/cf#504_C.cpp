#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, k, p = 0, q = 0,count = 0;
	scanf("%d %d", &n, &k);
	char a[n+5],b[n+5];
	scanf("%s", a);
	for(int i = 0; i < n; i++){
		if(a[i] == '('){
			if(p<k/2){
				b[count++] = a[i];
				p++;
			}
		}
		else{
			if(q<p){
				b[count++] = a[i];
				q++;
			}
			if(q == k/2)
				break;
		}
	}
	for(int i = 0; i < k; i++)
		printf("%c", b[i]);
	return 0;
}