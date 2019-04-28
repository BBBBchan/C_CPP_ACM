#include <cstdio>
#include <cstring>
char a[5000];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char b[5];
		scanf("%s", b);
		if(strlen(b) == 1){
			if(b[0] == '0')
				printf("X");
			else if((b[0]-'0') %2 == 0 || (b[0]-'0') == 7)
				printf("I");
			else
				printf("E");
		}
		else if(strlen(b) == 2){
			if(b[1] == '-'){
				if((b[0]-'0') %2 == 0 || (b[0]-'0') == 7)
					printf("I");
				else
					printf("E");
			}
			else if(b[1] == '+'){
				if((b[0]-'0') %2 == 0 || (b[0]-'0') == 7)
					printf("I");
				else
					printf("E");				
			}
		}
		else if(strlen(b) == 3){
			printf("E");
		}
	}
	return 0;
}