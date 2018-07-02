#include <stdio.h>
#include <math.h>
int main(){
	int m,a,b;
	scanf("%d",&m);
	for(int i = 0; i < m; i++){	
		scanf("%d %d",&a,&b);
		int kase = 0;
		if(a < 100)
			a = 100;
		for(int i = a; i < b; i++){
			int k = i,count = 0,sum=0;
			while(k!=0){
				k/=10;
				count++;
			}
			k = i;
			while(k!=0){
				sum += pow((k%10),count);
				k/=10;
			}
		if(sum == i)
			kase++;
		}
		printf("%d\n",kase);
}
return 0;
}
