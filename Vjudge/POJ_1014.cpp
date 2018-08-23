#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a[6],cnt = 0;
	while(true){
		cnt++;
		int kase = 0,sum = 0;
		for(int i = 0; i < 6; i++){
			scanf("%d", &a[i]);
			sum += a[i]*(i+1);
			if(a[i] != 0)
				kase = 1;
		}
		if(!kase)
			break;
		if(sum%2){
			printf("Collection #%d:\nCan't be divided.\n", cnt);
			continue;
		}
		int ans = sum/2;
	}
	return 0;
}