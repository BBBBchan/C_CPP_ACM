#include <stdio.h>
#define pi 3.1415926
int main(){
	int n, m;
	scanf("%d %d",&n, &m);
	float v1, v2;
	v1 = (4.0/3.0)*pi*(n/20.0)*(n/20.0)*(n/20.0)*7.86;
	v2 = (4.0/3.0)*pi*(m/20.0)*(m/20.0)*(m/20.0)*19.3;
	printf("%.3f %.3f",v1,v2);
	return 0;
}
