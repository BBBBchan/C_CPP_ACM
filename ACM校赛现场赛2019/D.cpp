#include <cstdio>
int main(int argc, char const *argv[])
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		if((n&1) &&(m&1))
			printf("hht win\n");
		else
			printf("qko win\n");
	}	
	return 0;
}