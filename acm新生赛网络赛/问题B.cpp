#include <stdio.h>
#include <string.h>
int main(){
	int n,i=0;
	scanf("%d",&n);
	char a[150][30];
	double b[150],sum=0,sum1=0,sum2=0,average,average2,d[150];
	int c[150];
	while(n--){	
	double x;	
	int y;		
	scanf("%s %lf %d",&a[i],&b[i],&c[i]);
	sum += c[i]*b[i];
	sum1 += b[i];
	if(c[i] >= 90){
		d[i] = 4.0;
	}
	else if(c[i] >= 85){
		d[i] = 3.7;
	}
	else if(c[i] >= 82){
		d[i] = 3.3;
	}
	else if(c[i] >= 78){
		d[i] = 3.0;
	}
	else if(c[i] >= 75){
		d[i] = 2.7;
	}
	else if(c[i] >= 72){
		d[i] = 2.3;
	}
	else if(c[i] >= 69){
		d[i] = 2.0;
	}
	else if(c[i] >= 66){
		d[i] = 1.7;
	}
	else if(c[i] >= 63){
		d[i] = 1.5;
	}
	else if(c[i] >= 60){
		d[i] = 1.0;
	}
	else if(c[i] < 60){
		d[i] = 0;
	}
	sum2 +=d[i]*b[i];
	for(int k = i;k>0;k--){
		x = strcmp(a[i],a[k-1]);
		if(x == 0){
			if(c[i] > c[k-1]){
				sum -= c[k-1]*b[k-1];
				sum2 -= d[k-1]*b[k-1];
				sum1 -= b[k-1];
				
				break;
			}
		else{
			sum -= c[i]*b[i];
			sum2 -= d[i]*b[i];
			sum1 -= b[i];
			break;
		}
		}
	}
	i++;
	}
	average = sum/sum1;
	average2 = sum2/sum1;
		printf("%.1f\n%.2f",average,average2);
		return 0;

}