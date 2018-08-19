#include <stdio.h>
int main(int argc, char const *argv[])
{
	int t,i;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		char a[n+10];
		scanf("%s",a);
		for(i = 0; i <= n/2; i++){
			if(a[i] == a[n-1-i])
				continue;
			int temp1 = a[i] - 'a';
			int temp2 = a[n-1-i] - 'a';
			if(temp1-temp2 == 2 || temp2-temp1 == 2)
				continue;
			printf("NO\n");
			break;
		}
		if(i == (n/2 + 1))
			printf("YES\n");
	}
	return 0;
}