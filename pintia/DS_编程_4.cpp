#include <cstdio>
int main(int argc, char const *argv[])
{
	char a[10000],c;
	int n = 0;
	while(scanf("%c", &c)!=EOF && c != '#'){
		a[n] = c;
		n++;
	}
	int kase = 1, mark = 1;
	long long int ans = 0;
	for(int i = 0; i < n;i++){
		if(a[i] == '-' && kase == 1)
			mark = 0;
		else if(a[i] >= '0' && a[i]<='9'){
			kase = 0;
			ans = ans*16 + a[i]-'0';
		}
		else if(a[i] >= 'a' && a[i] <='f'){
			kase = 0;
			ans = ans*16 + a[i]-'a'+10;
		}
		else if(a[i] >= 'A' && a[i] <= 'F'){
			kase = 0;
			ans = ans*16 + a[i]-'A'+10;
		}
	}
	if(mark == 1)
		printf("%lld\n", ans);
	else
		printf("%lld\n", -ans);
	return 0;
}