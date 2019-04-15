#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int count[500][26];
int now[26] = {0};
int max_t = 0;
int main(int argc, char const *argv[])
{
	char a[105];
	memset(count,0,sizeof(count));
	while(scanf("%s", a) != EOF){
		for(int i = 0; i < strlen(a); i++){
			count[now[a[i]-'A']][a[i]-'A'] = 1;
			now[a[i]-'A']++;
		}
		p
	}
	for(int i = 0; i < 26; i++){
		max_t = max(max_t,now[i]);
	}
	printf("%d\n", max_t);
	for(int i = 0; i < max_t; i++){
		for(int j = 0; j < 26; j++){
			// if(count[i][j] == 1)
			// 	printf("*");
			// else
			// 	printf(" ");
			printf("%d ", count[i][j]);
		}
		printf("\n");
	}

	return 0;
}