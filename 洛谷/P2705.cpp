#include <cstdio>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int r, b, c, d, e, ans;
	scanf("%d %d %d %d %d", &r, &b, &c, &d, &e);
	if(c + d < 2*e){
		ans = min(r,b)*e*2+(r-min(r,b))*c + (b-min(r,b))*d;
	}
	else
		ans = r*c + b*d;
	printf("%d\n", ans);
	return 0;
}