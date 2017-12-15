#include <stdio.h>
int main(){
	double oneyear = 0.0387, twoyear = 0.0450, threeyear = 0.0522,fiveyear = 0.0576;
	double n;
	scanf("%lf",&n);
	double p1=n, p2=n , p3=n , p5=n;
	for(int i1 = 0;i1 < 30;i1++){	
		int i2 = 2*i1;
		int i3 = 3*i1;
		int i5 = 5*i1;
		p1 *= (1+oneyear);
		if(i2 < 30)
			p2 *= (1+2*twoyear);
		if(i3 <30)
			p3 *= (1+3*threeyear);
		if(i5 <30)
			p5 *= (1+5*fiveyear);
		}
		printf("一年期：%lf 两年期： %lf 三年期：%lf 五年期：%lf",p1,p2,p3,p5);
	return 0;
	}

