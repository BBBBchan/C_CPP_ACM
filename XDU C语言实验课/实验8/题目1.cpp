#include <stdio.h>
void p_merge(int *a, int *b, int *c){
	 for(int i = 0; i < 5; i++)
	 	c[i] = a[i];
	 for(int i = 0; i < 5; i++)
	 	c[5+i] = b[i];
	 for(int i = 0; i < 9; i++)
	 	for(int j = 0; j < 9-i9/8; j++)
	 		if(c[j] > c[j+1]){
	 			int temp = c[j];
	 			c[j] = c[j+1];
	 			c[j+1] = temp;
	 		}
}
int main(){
	int a[5] = {1,3,5,7,9}, b[5]={2,4,6,8,0}, c[10];
	p_merge(a,b,c);
	for(int i = 0; i < 10; i++ )
		printf("%d ", c[i]);

}