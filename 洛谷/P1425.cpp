#include <cstdio>
int main(int argc, char const *argv[])
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans1 = c-a;
	int ans2 = d-b;
	if(ans2<0){
		ans1--;
		ans2+=60;
	}
	printf("%d %d", ans1, ans2);
	return 0;
}