#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int temp1,temp2,max = 0, count = 1;
	scanf("%d", &temp1);
	for(int i = 1; i < n; i++){
		scanf("%d", &temp2);
		if(temp2 > temp1){
			count++;
			if(count>max)
				max = count;
		}
		else{
			count = 1;
		}
		temp1 = temp2;
	}
	printf("%d\n", max);
	return 0;
}