#include <cstdio>
int a[105];
int main(int argc, char const *argv[])
{
	int i = 0;
	while(scanf("%d", &a[i]) && a[i] != 0){
		i++;
	}
	for(int j = i-1; j >=0; j--)
		printf("%d ", a[j]);
	return 0;
}