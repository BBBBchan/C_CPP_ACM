#include <stdio.h>
double shulie(int n){
	if(n != 1)
		return 1.0/(1+shulie(n-1));
	else return 1.0;
}
int main(){
	int m;
	scanf("%d",&m);
	int a[100];
	for(int i = 0; i < m; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < m; i++){
		double k = shulie(a[i]);
		printf("%.6lf\n",k);
	}
	return 0;
}
