#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	char a[12],b[12],c[10];
	int kase[12];
	while(t--){
		memset(kase,-1,sizeof(kase));
		for(int j = 0; j < 3; j++){
			scanf("%s %s %s", a, b, c);
			if(c[0] == 'e'){
				for(int i = 0; i < strlen(a); i++)
					kase[a[i]-'A'] = 1;
				for(int i = 0; i < strlen(b); i++)
					kase[b[i]-'A'] = 1;
			}
			else{
				for(int i = 0; i < strlen(a); i++){
					if(kase[a[i]-'A'] == 1)
						continue;
					else
						kase[a[i]-'A'] = 0;
				}
				for(int i = 0; i < strlen(b); i++){
					if(kase[b[i]-'A'] == 1)
						continue;
					else
						kase[b[i]-'A'] = 0;
				}
			}
		}
		for(int i = 0; i < 12; i++)
			if(kase[i] == 0){
				printf("%c is the counterfeit coin and it is light.\n", i+'A');
				break;
			}
	}
	return 0;
}

