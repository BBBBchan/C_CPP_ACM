#include <cstdio>
int main(int argc, char const *argv[])
{
	char a;
	int ans = 0;
	while(scanf("%c", &a) != EOF){
		if(a != ' '&& a != '\n')
			ans++;
	}
	printf("%d", ans);
	return 0;
}