#include <cstdio>
int count = 0;
int n;
void get_num(int m){
	for(int i = 1; i <= n/2; i++){
		count++;
		int temp1 = m, temp3 = i;
		while(temp1 != 0){
			temp1 /= 10;
			temp3 *= 10;
		}
		temp3 += m;
		printf("%d ", temp3);
		get_num(temp3);
	}
}
int main(int argc, char const *argv[])
{
	
	scanf("%d", &n);
	get_num(n);
	printf("count = %d\n", count);
	return 0;
}