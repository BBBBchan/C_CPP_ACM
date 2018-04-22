#include <stdio.h>
int main(int argc, char const *argv[])
{
	long int n, m, p;
	while(scanf("%ld %ld %ld", &n, &m, &p) != EOF){
		long int ans = 1;
		for(int i = 0; i <= m; i++){
			ans = (ans%p*n%p)%p;
			n--; 
		}
		ans = (ans%p/m%p)%p;
		printf("%ld\n", ans);
	}
	return 0;
}