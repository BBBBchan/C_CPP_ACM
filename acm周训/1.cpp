#include <cstdio>
int main(int argc, char const *argv[])
{
		int a, b ,c;
		while(scanf("%d %d %d", &a, &b, &c) != EOF){
			if((a*b*c) % 2 == 0)
				printf("Yes\n");
			else
				printf("No\n");
	}
		return 0;
}