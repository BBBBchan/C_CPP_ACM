#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	long long int acount=0, count2=0, count1=0;
	scanf("%d", &n);
	char a[100050],b[100050];
	scanf("%s", a);
	scanf("%s", b);
	for(int i = 0; i < n; i++){
		if(a[i] == '1')
			acount++;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == b[i] && a[i] == '1')
			count1++;
		else if(a[i] == '0' && b[i] == '1')
			count2++;
	}
	long long int ans = acount*(n-acount) - count1*count2;
	printf("%I64d", ans);
	return 0;
}