#include <stdio.h>
void quwei(int num,int h ,int z, int q){
	h = num % 10;
	z = (num/10)%10;
	q = num/100;
	}
int main()
{
	for(int i = 123; i <= 987; i++){
		int a , b ,c;
		quwei(i,a,b,c); 
		if(a == b || b == c || a == c)
			continue;
		printf("%d  ",i);
		for(int j = 123;j <= 987;j++){
			int x,y,z;
			quwei(j,x,y,z);
			if(x == y ||y == z||z == x||
			   x == a ||x == b||x == c||
			   y == a ||y == b||y == c||
			   z == a ||z == b||z == c)
				continue;
			for(int k =123;k<=987;k++){
				int l,m,n;
				quwei(k,l,m,n);
				if(l == m ||m == n || n == l||
				   l == a ||l == b||l == c||
			       m == a ||m == b||m == c||
			       n == a ||n == b||n == c||
			       l == x ||l == y||l == z||
			   	   m == x ||m == y||m == z||
			       n == x ||n == y||n == z )
					continue;
				if ( i*2 == j && i*3 == k)
					printf("%d %d %d\n",i, j, k);

			}
		}

	}
	return 0;
}
