#include <cstdio>
struct sch
{
	int num;
	int seat[20][10];
}schools[120];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &schools[i].num);
	}
	return 0;
}