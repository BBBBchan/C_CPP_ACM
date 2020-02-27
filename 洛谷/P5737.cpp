#include <cstdio>
int main(int argc, char const *argv[])
{
	int x, y,count1=0;
	int a[10000];
	scanf("%d %d", &x, &y);
	for(int i = x; i <= y; i++){
		if(((i%4==0) && (i%100!=0)) || i%400==0){
			a[count1] = i;
			count1++;
		}
	}
	printf("%d\n", count1);
	for(int i = 0; i < count1; i++){
		printf("%d ", a[i]);
	}
	return 0;
}