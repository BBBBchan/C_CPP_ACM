#include <stdio.h>
#include <string.h>
struct a{
	char name[20];
	char num[20];
	float a;

}info[10],temp;
int find(char *s, struct a *info){
	for(int i = 0; i < 10; i++)
		if(strcmp(info[i].num,s) == 0){
			return info[i].a;
		}
	return -1;
}
int main(){
	float sum =0,average = 0;
	for(int i = 0; i < 10; i++){
		scanf("%s %s %f", &info[i].name, &info[i].num, &info[i].a);
		sum += info[i].a;
	}
	average = sum/10.0;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9-i; j++){
			if(strcmp(info[j].num,info[j+1].num) > 0)
			{
				temp = info[j]; info[j] = info[j+1]; info[j+1] = temp;
			}
		}
	for(int i = 0; i < 10; i++)
		printf("%s\n", info[i].num);
	char s[20];
	scanf("%s",s);
	int k = find(s,info);
	if(k == -1)
		printf("not exist\n");
		else 
			printf("%d\n", k);
	temp = info[0];
	for(int i = 1; i < 10; i++){
		if(info[i].a > temp.a)
			temp = info[i];
	}
	printf("%s %s %d\n",temp.name,temp.num,temp.a );
	return 0;
}