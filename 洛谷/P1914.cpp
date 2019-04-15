#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	char a[100];
	scanf("%s", a);
	for(int i = 0; i < strlen(a); i++){
		a[i] = (a[i]-'a'+n)%26 +'a';
		printf("%c", a[i]);
	}
	return 0;
}