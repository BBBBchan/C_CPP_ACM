#include <stdio.h>
void isWhatDay(int date_month, int date_day);
int main(){
	int month,date;
	scanf("%d %d",&month,&date);
	isWhatDay(month,date);
	return 0;
}
void isWhatDay(int date_month, int date_day){
	int day = 0;
	switch(date_month){
		case 1:	day =0;	break;
		case 2:	day =31;	break;
		case 3: day =31+28;	break;
		case 4:	day =31*2 + 28;	break;
		case 5: day =31*2 + 30 +28;	break;
		case 6: day =31*3 + 30 +28;	break;
		case 7: day =31*3 +30*2+28;	break;
		case 8: day =31*4 +30*2+28;	break;
		case 9:	day =31*5 +30*2+28;	break;
		case 10:day =31*5 +30*3+28;	break;
		case 11:day =31*6 +30*3+28;	break;
		case 12:day =31*6 +30*4+28;	break;
	}
	day += (date_day);
	day %= 7;
	switch(day){
		case 1:	printf("Monday\n");	break;	
		case 2:	printf("Tuesday\n");break;
		case 3: printf("Wednesday\n");break;
		case 4:	printf("Thursday\n");break;
		case 5:	printf("Friday\n");	break;
		case 6: printf("Saturday\n");break;
		case 0: printf("Sunday\n");	break; 
	}
}