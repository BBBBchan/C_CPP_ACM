#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char a[25],c[25];
	while(scanf("%s", a) != EOF){
		int n,max=0;
		scanf("%d", &n);
		while(n--){
			char b[15];
			scanf("%s", b);
			for(int i = 0; i <= strlen(a); i++)
				c[i] = a[i];
			int i;
			for(i = 0; i < strlen(b); i++){
				int j;
				for(j = 0; j < strlen(c); j++){
					if(c[j] == b[i]){
						c[j] = '=';
						break;
					}
				}
				if(j == strlen(c))
					break;
			}
			if(i == strlen(b))
				if(max < strlen(b))
					max = strlen(b);
		}
		printf("%d\n", max);
	}
	return 0;
}