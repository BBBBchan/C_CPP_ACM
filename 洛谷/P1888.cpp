#include <cstdio>
#include <iostream>
using namespace std;
int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}
int main(int argc, char const *argv[])
{
	int a, b, c;
	scanf("%d %d %d", &a, &b ,&c);
	int m = max(max(a,b),c);
	int n = min(min(a,b),c);
	printf("%d/%d\n",n/GCD(m,n),m/GCD(m,n) );
	return 0;
}