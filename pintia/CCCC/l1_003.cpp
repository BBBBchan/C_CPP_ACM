#include <cstdio>
#include <cstring>
char a[1005];
int b[10] = {0};
int main(int argc, char const *argv[])
{
	scanf("%s", a);
	for(int i = 0; i < strlen(a); i++){
		b[a[i]-'0']++;
	}
	for(int i = 0; i < 10; i++){
		if(b[i] != 0)
			printf("%d:%d\n", i, b[i]);
	}
	return 0;
}