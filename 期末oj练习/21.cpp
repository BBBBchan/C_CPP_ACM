#include <stdio.h>
int shulie(int i){
	if(i == 0)
		return 7;
	else if(i == 1)
		return 11;
	else
		return (shulie(i-1) + shulie(i-2));
}
int main(){
	int t,a;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d",&a);
		int f;
		f = shulie(a);
		if(f%3 == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
