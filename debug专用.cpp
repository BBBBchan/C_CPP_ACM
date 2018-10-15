#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void game(int s)
{
	unsigned int b, c;                               //设定游戏猜测值
	printf("请输入一个一百以内的正整数\n");
	while (1)
	{
		c = scanf("%u", &b);
		if (c != 1)                                  //识别非法字符
		{
			printf("输入错误，请重新输入\n");
			fflush(stdin);
			break;
		}
		else {
			if (s > b)                               //通过猜测值与系统随机值比较，对猜测者提供反馈
				printf("guess small\n");
			if (s < b)
				printf("guess big\n");
			if (s == b)
			{
				printf("right！！！\n");
				break;                             //猜测正确时跳出循环
			}
		}


	}
	printf("游戏结束\n\n\n\n");

}

void meun()
{
	printf("********************************************************\n");
	printf("**********************   1.play   **********************\n");
	printf("**********************   0.exit   **********************\n");
	printf("********************************************************\n");
}
int main(){
	int a;                                //设置一个变量来选择游戏菜单
	do
	{
		meun();                           //显示游戏菜单
		srand((unsigned)time(NULL));      //初始随机数生成器
		int s = rand() % 101;             //生成随机数（%101生成100以内随机数）
		scanf("%d", &a);
		printf("%d \n", a);
		if (a == 1)                       //当变量a为1时，运行game函数
		{
			//printf("%d", s);
			game(s);
		}
	} while (a != 0);                     //设置循环只要a不为0，程序始终运行当变量a为1时，为0退出程序

	return 0;
}
