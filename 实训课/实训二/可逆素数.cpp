#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int n;
	for(n = 1001; n < 9997; n++){
		int kase = 1;
		for (int i = 2; i < sqrt(n)+1; i++)
		{
			if(n%i == 0){
				kase = 0;
				break;
			}
		}
		if(kase == 1){
			int a[4],temp = n;
			for(int i = 0; i < 4; i++){
				a[i] = temp%10;
				temp /=10;
			}
			int n1 = 1000*a[0]+100*a[1]+10*a[2]+a[3],kase1 = 1;
			for (int i = 2; i < sqrt(n1)+1; i++)
			 {
			 	if(n1%i == 0){
			 		kase1 = 0;
			 		break;
			 	}	
			} 
			if(kase1 == 1){
				printf("%d\n", n1);
			}
		}
	}
	return 0;
}