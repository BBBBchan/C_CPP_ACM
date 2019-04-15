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
			if(a[i] > 'Z' || a[i] < 'A')
				continue;
			count[now[a[i]-'A']][a[i]-'A'] = 1;
			now[a[i]-'A']++;
		}
	}
	for(int i = 0; i < 26; i++){
		max_t = max(max_t,now[i]);
	}
	for(int i = max_t-1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if(j != 25){
				if(count[i][j] == 1)
					printf("* ");
				else
					printf("  ");
			}
			else{
				if(count[i][j] == 1)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	for(int i = 0; i< 25; i++){
		printf("%c ", 'A'+i);
	}
	printf("Z");
	return 0;
}