#include <stdio.h>
int main()
{
	int n , m=0;
	scanf("%d",&n);
	while( n != 0 )		//行数
	{	
		
		for(int j = 0; j < m ; j++) 	//空格输出
			printf(" ");
		for( int i = 0; i < (2*n-1) ; i++)	//#号输出
			printf("#");
		
		printf("\n");
		n--;
		m++;
	}
	return 0;
}
