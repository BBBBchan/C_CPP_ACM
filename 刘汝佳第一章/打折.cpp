#include <stdio.h>
int main()
{
	int n;
	double price ;
	scanf("%d", &n);
	price = n * 95.0;
	if(price >= 300){
		price = price * 0.95 ;
		printf("%.2f" , price);
		}
	else 
		printf("%.2f", price);
	return 0 ;

}