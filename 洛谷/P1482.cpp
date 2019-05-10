#include <cstdio>
int GCD(int a,int b){
return b==0?a:GCD(b,a%b);
}
int main(int argc, char const *argv[])
{
	int a1,b1,a2,b2;
	scanf("%d/%d", &a1, &b1);
	scanf("%d/%d", &a2, &b2);
	int a3 = a1*a2, b3 = b1*b2;
	printf("%d %d\n", b3/GCD(a3,b3), a3/GCD(a3,b3));
	return 0;
}