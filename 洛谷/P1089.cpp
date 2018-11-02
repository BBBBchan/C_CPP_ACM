#include <cstdio>
int main(int argc, char const *argv[])
{
	int now = 0, a, kase = 1;
	float all = 0;
	for(int i = 1; i <= 12; i++){
		now+=300;
		scanf("%d", &a);
		now -= a;		
		if(now>=100){
			all += (now/100)*120;
			now-=(now/100)*100;
		}
		if(now < 0 && kase == 1){
			kase = 0;
			printf("%d\n", -1*i);
		}

	}
	if(kase == 1)
		printf("%.0f\n", all+now);
	return 0;
}