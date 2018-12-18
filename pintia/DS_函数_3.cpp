#include <stdio.h>
#define MAXS 20

void f( char *p );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    scanf("%s", s);
    f(s);
    printf("%s\n", s);

    return 0;
}
void f(char *p){
	int i = 0;
	while(p[i] != '\0'){
		i++;
	}
	for(int j = 0; j < i/2; j++){
		char temp = p[j];
		p[j] = p[i-j-1];
		p[i-j-1]=temp;
	}
}