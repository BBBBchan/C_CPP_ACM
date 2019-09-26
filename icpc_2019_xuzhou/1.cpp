#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
int main(int argc, char const *argv[])
{
	int w;
	scanf("%d", &w);
	if(w % 2 == 0 && w != 2){
		printf("YES");
	}
	else
		printf("NO");
	return 0;
}