#include <cstdio>
struct {
	char name[15];
	float money;
}x[10000];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	float a, b ,c;
	for(int i = 0; i < n; i++){
		scanf("%s %f %f %f", x[i].name, &a, &b, &c);
		x[i].money = a+b-c;
	}
	for(int i = 0; i < n; i++)
		printf("%s %.2f\n", x[i].name, x[i].money);
	return 0;
}