#include <cstdio>
int main(int argc, char const *argv[])
{
	for(int i = 192; i <= 327; i++){
		int a[10]={0},kase = 1,j=2*i,k=3*i;
		a[i/100]++, a[j/100]++, a[k/100]++;
		a[i%10]++, a[j%10]++, a[k%10]++;
		a[(i/10)%10]++, a[(j/10)%10]++,a[(k/10)%10]++;
		for(int m = 1; m <=9; m++){
			if(a[m]>=2 || a[m] == 0){
				kase = 0;
				break;
			}
		}
		if(kase == 1)
			printf("%d %d %d\n", i,j,k);		
	}
	return 0;
}