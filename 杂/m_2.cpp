#include <stdio.h>
int main(int argc, char const *argv[])
{
	for(int i = 100; i<=999; i++){
		if((i-7)%7 == 0 && (i-8)%8==0 && (i-9)%9 == 0)
			printf("%d\n", i);
	}
	return 0;
}