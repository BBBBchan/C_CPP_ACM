#include <stdio.h>
int main()
{
	int a , b , c , t ;
	scanf("%d %d %d" ,&a , &b , &c );
	if(a > b){
		t = a ;  a = b ;  b = t ;  //执行后有a<=b
	}
	if(a > c){
		t = a ;  a = c ;  c = t ;  //执行后有a<=c且a<=b仍然成立
	}
	if(b > c){
		t = b ;  b = c ;  c = t ;
	}
	printf("%d %d %d ", a , b , c);
	return 0;

}
