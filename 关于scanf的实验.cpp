#include <stdio.h>
int main(){
	int a,b,c,d,e,f;
	scanf("%d,%d,%d",&a,&b,&c);			//输入时要加,
	printf("%d,%d,%d\n",a,b,c);
	scanf("c=%d,d=%d,e=%d",&c,&d,&e);	//错误的写法
	printf("%d,%d,%d",c,d,e);
	return 0;
}