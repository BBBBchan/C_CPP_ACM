#include <cstdio>
#include <cstring>
char a[10005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf(" %c", &a[i]);
	}
	for(int i = 0; i < n-1; i++)
		printf("%c ", a[i]);
	if(n!=0)
		printf("%c\n", a[n-1]);
	printf("%d\n", n);
	if(n != 0)
		printf("no\n");
	printf("%c\n", a[2]);
	for(int i = 0; i < n; i++)
		if(a[i] == 'a'){
			printf("%d\n", i+1);
		}
	for(int i = n; i >= 4; i--)
		a[i] = a[i-1];
	a[3] = 'f';
	n++;
	for(int i = 0; i < n-1; i++)
		printf("%c ", a[i]);
	printf("%c\n", a[n-1]);
	for(int i = 2; i < n-1; i++)
		a[i] = a[i+1];
	n--;
	for(int i = 0; i < n-1; i++)
		printf("%c ", a[i]);
	if(n!=0)
	printf("%c\n", a[n-1]);
	memset(a,0,sizeof(a));
	return 0;
}