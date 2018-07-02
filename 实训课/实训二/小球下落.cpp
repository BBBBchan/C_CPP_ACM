#include <stdio.h>
int main(int argc, char const *argv[])
{
	double h = 100, t = 50;
	for(int i = 1; i < 10; i++){
		h += 2*t;
		t /= 2;
	}
	printf("%f\n%f\n", h, t);
	int n = 10;
	while(t > 0.000001){
		h+= 2*t;
		t /= 2;
		n++;
	}
	h+= 2*t;
	printf("%d\n%f\n", n, h);
	return 0;
}