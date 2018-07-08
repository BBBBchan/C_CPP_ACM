#include <stdio.h>
int main(){
	long long int a;
	while(scanf("%lld", &a) != EOF){
		int temp = a%1000;
		a/=1000;
		printf("%lld\n", a);
		float temp2;
		temp2 = temp%10;
		if(temp2>=5)
			temp+=10;
		temp/=10;
		float m = (temp%10)*0.01; 
		float n = (temp/10)*0.1;
		double ans;
		ans = m+n;
		printf("%f\n",ans);
		ans += a;
		printf("%.2lf\n",ans);
	}
	return 0;
}