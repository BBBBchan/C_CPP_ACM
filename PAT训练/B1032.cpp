#include <cstdio>
int a[100010], max_score=0, max_num=0;
int main(int argc, char const *argv[])
{
	int n, num, score;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &num, &score);
		a[num] += score;
		if(a[num] > max_score){
			max_num = num;
			max_score = a[num];
		}
	}
	printf("%d %d\n", max_num, max_score);
	return 0;
}