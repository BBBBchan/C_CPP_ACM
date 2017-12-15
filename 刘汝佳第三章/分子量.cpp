#include <stdio.h>
#include <string.h>
#include <math.h>
char a[100];
int b[100];
int main(){

	while(scanf("%s",&a) == 1){
		int n = strlen(a);	
		memset(b,10,sizeof(b));
		for(int i = 0; i < n ;i++){
			b[i] = a[i]-'0';
		} 
		double sum = 0.0;
		for(int i = 0; i<n;i++){
			int kase = 0,N = 0,temp;
			switch (b[i]){
				case 19:
					while(b[i+1] <10)
						{
							kase ++;
							i++;
						}
						if(kase == 0) N = 1;
						temp = kase;
					for(int n = i-kase+1;n<=i;n++)
					{
						N += b[n]*pow(10,temp-1);
						temp--;
						
					}
					sum += 12.01*N;
					break;
				case 24:
					while(b[i+1] <10)
						{
							kase ++;
							i++;
						}
						if(kase == 0) N = 1;
						temp = kase;
					for(int n = i-kase+1;n<=i;n++)
					{
						N += b[n]*pow(10,kase-1);
						temp--;
					}
					sum += 1.008*N;
					break;
				case 31:
					while(b[i+1] <10)
						{
							kase ++;
							i++;
						}
						if(kase == 0) N = 1;
						temp = kase;
					for(int n = i-kase+1;n<=i;n++)
					{
						N += b[n]*pow(10,kase-1);
						temp--;
					}
					sum += 16.00*N;
					break;
				case 30:
					while(b[i+1] <10)
						{
							kase ++;
							i++;
						}
						if(kase == 0) N = 1;
						temp = kase;
					for(int n = i;n<=i-kase+1;n--)
					{
						N += b[n]*pow(10,kase-1);
						temp--;
					}
					sum += 14.01*N;
					break;
			}
		}
		printf("%lf",sum);
	}
	return 0;
}
