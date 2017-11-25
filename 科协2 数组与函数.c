#include <stdio.h>
int swap(int x, int y); 
int main()
{
	int a[100];
	int m = 0;
	int count =0;
	printf("%d\n",m);
	double sum = 0; 
	while(m != -1){
		sum += m;
		a[count] = m;
		count += 1;
		scanf("%d", &m);
	}
	double average;
	average = sum / (count-1) ;
	printf("%lf\n", average);
	int i =0;
	for(i = 0;i <= count; i++)
	{
		if (a[i] > average)
			printf("%d ",a[i]);
	}
	/*循环*/
	// int i = 1;
	// for(i=0;i<5;i++){
	// 	if(i == 3)
	// 		break;
	// 	printf("BB\n");		//ctrl + c 终止循环
	// }
	// printf("\n");
	// i = 0;

	// while(i < 6)
	// {
	// 	i++;
	// 	printf("hello \n");

	// }

	// do{
	// 	i--;
	// 	printf("ni hao \n");
	// }while(i > 0);
	
	/*数位求和*/
	int x = 1234;
	int y =4567;
	swap(x ,y);
	printf("%d %d \n",x , y);
	// hanshu(x);
	// hanshu(y);
	return 0;
	getchar();
}
int swap(int x , int y)
{
	int t;
	t = x;
	x = y;
	y = t;
	printf("%d %d \n",x , y);
}
// int hanshu(int a)
// {
// 	int b , i ;
// 	i = 0;
// 	while(a != 0){
// 		b = a % 10 ;
// 		a = a / 10;
// 		i = i + b;
// 	}
// 	printf ("%d\n", i);
// }