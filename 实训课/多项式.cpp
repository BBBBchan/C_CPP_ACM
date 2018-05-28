#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[1000] = {0};
	int n1, n2;
	scanf("%d",&n1);
	for(int i = 0; i < n1; i++){
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		a[temp2] = temp1;
	}
	scanf("%d", &n2);
	for(int i = 0; i<n2; i++){
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		a[temp2] += temp1;
	}
	int kase1 = 0, kase2 = 0;
	if(a[0] != 0)
		printf("%d", a[0]);
	for(int i = 1; i <= n1 || i <= n2; i++){
		if(a[i] != 0){
			kase2 = 1;
			if(kase1 == 0){
				kase1 = 1;
				if(a[i] != 1 && i != 1)
					printf("%dx%d", a[i], i);
				else if(a[i] == 1 && i != 1)
					printf("+x%d", i);
				else if(a[i] != 1 && i == 1)
					printf("%dx", a[i]);
				else printf("x");
			}
			else{ 
				if(a[i] != 1 && i != 1)
					printf("%+dx%d",a[i], i);
				else if(a[i] == 1 && i != 1)
					printf("+x%d", i);
				else if(a[i] != 1 && i == 1)
					printf("%+dx", a[i]);
				else printf("+x");
			}
		}
	}
	if(kase2 == 0)
		printf("0");
	return 0;
}