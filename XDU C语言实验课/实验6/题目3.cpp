#include <stdio.h>
int main(){
	struct info
	{
		char num[20];
		int score;
	}a[10],b;
	float sum = 0;
	for(int i = 0; i < 10; i++){
		scanf("%s %d",a[i].num, &a[i].score);
		sum += a[i].score;
	}
	float average = sum/10.0;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9-i; j++){
			if(a[j].score > a[j+1].score){
				b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	for(int i = 0; i < 10; i++)
		if(a[i].score > average*1.10)
			printf("%s %d 1\n",a[i].num, a[i].score);
		else if(a[i].score >average*1.05)
			printf("%s %d 2\n",a[i].num,a[i].score );
	return 0;

}