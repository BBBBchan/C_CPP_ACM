#include <stdio.h>
void calender(int month);
int main(){
	int month;
	scanf("%d",&month);
	calender(month);
	return 0;
}
void calender(int month){
	printf("Calender 2007 - %02d\n",month);
	printf("----------------------------\n");
	printf("  Su  Mo  Tu  We  Th  Fr  Sa\n");
	printf("----------------------------\n");
	int day = 1;
	int i,max;
	switch(month){
		case 1:	day +=0;	max = 31; break;
		case 2:	day +=31;max = 28;break;
		case 3: day +=31+28;max =31;	break;
		case 4:	day +=31*2 + 28;	max = 30;break;
		case 5: day +=31*2 + 30 +28;	max = 31;break;
		case 6: day +=31*3 + 30 +28;	max = 30;break;
		case 7: day +=31*3 +30*2+28;	max = 31;break;
		case 8: day +=31*4 +30*2+28;	max = 31;break;
		case 9:	day +=31*5 +30*2+28;	max = 30;break;
		case 10:day +=31*5 +30*3+28;	max = 31;break;
		case 11:day +=31*6 +30*3+28;	max = 30;break;
		case 12:day +=31*6 +30*4+28;	max = 31;break;
	}
	day %= 7;
	for(int x = 0;x < day; x++)
		printf("    ");
	
	for(i = 1;i <= 7-day;i++)
		printf("%4d",i);
	printf("\n");
	while(i<max){
	 	for(int n=0;n<7;n++,i++)
	 		printf("%4d", i);
	 	printf("\n");
	 }	
}