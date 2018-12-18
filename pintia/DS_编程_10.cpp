#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	char a[100],c;
	int b[128] = {0};
	int j = 0;
	while(scanf("%c", &c)!=EOF && c != '\n'){
		a[j] = c;
		j++;
	}
	for(int i = 0; i < j; i++){
		if(b[a[i]] == 0){
			b[a[i]] = 1;
		}
	}
	for(int i = 0; i < 128; i++)
		if(b[i] == 1)
			printf("%c", i);
	printf("\n");
	return 0;
}