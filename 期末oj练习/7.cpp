#include <stdio.h>
int main(){
	int m;
	float a[100];
	scanf("%d",&m);
	for(int i = 0; i < m; i++)
		scanf("%f",&a[i]);
	for(int i = 0; i < m ; i++){
		if(a[i] <= 110)
			printf("%.2f\n",a[i]*0.5);
		else if(a[i] <= 210)
			printf("%.2f\n",110.0*0.5+(a[i]-110.0)*0.55);
		else 
			printf("%.2f\n",110.0*0.5+100*0.55+(a[i]-210.0)*0.70);
	}
	return 0;
}
