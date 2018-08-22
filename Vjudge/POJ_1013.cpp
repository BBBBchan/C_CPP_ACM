#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	char a[12],b[12],c[10];
	int kase[12],count[12];
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
			else if(c[0]=='u'){
				for(int i = 0; i < strlen(a); i++){
					if(kase[a[i]-'A'] == 1)
						continue;
					else if(kase[a[i]-'A'] == -1){
						kase[a[i]-'A'] = 2;
						count[a[i]-'A'] = 1;
					}
					else if(kase[a[i]-'A'] == -2){
						kase[a[i]-'A'] = 1;
						count[a[i]-'A'] = 1;
					}
					else if(kase[a[i]-'A'] == 2){
						kase[a[i]-'A'] = 0;
						count[a[i]-'A'] = 1;
					}
				}
				for(int i = 0; i < strlen(b); i++){
					if(kase[b[i]-'A'] == 1)
						continue;
					else if(kase[b[i]-'A'] == -1){
						kase[b[i]-'A'] = -2;
						count[b[i]-'A'] = 1;
					}
					else if(kase[b[i]-'A'] == -2){
						kase[b[i]-'A'] = 0;
						count[b[i]-'A'] = 1;
					}
					else if(kase[b[i]-'A'] == 2){
						kase[b[i]-'A'] = 1;
						count[b[i]-'A'] = 1;
					}
				}
				for(int i = 0; i < 12; i++){
					if(count[i] == 0)
						kase[i] = 1;
				}
			}
			else if(c[0]=='d'){
				for(int i = 0; i < strlen(a); i++){
					if(kase[a[i]-'A'] == 1)
						continue;
					else if(kase[a[i]-'A'] == -1){
						kase[a[i]-'A'] = -2;
						count[a[i]-'A'] = 1;
					}
					else if(kase[a[i]-'A'] == -2){
						kase[a[i]-'A'] = 0;
						count[a[i]-'A'] = 1;
					}
					else if(kase[a[i]-'A'] == 2){
						kase[a[i]-'A'] = 1;
						count[a[i]-'A'] = 1;
					}
				}
				for(int i = 0; i < strlen(b); i++){
					if(kase[b[i]-'A'] == 1)
						continue;
					else if(kase[b[i]-'A'] == -1){
						kase[b[i]-'A'] = 2;
						count[b[i]-'A'] = 1;
					}
					else if(kase[b[i]-'A'] == -2){
						kase[b[i]-'A'] = 1;
						count[b[i]-'A'] = 1;
					}
					else if(kase[b[i]-'A'] == 2){
						kase[b[i]-'A'] = 0;
						count[b[i]-'A'] = 1;
					}
				}
				for(int i = 0; i < 12; i++){
					if(count[i] == 0)
						kase[i] = 1;
				}								
			}
		}
		for(int i = 0; i < 12; i++)
			if(kase[i] == 0 || kase[i] == 2 || kase[i] == -2){
				printf("%c is the counterfeit coin and it is light.\n", i+'A');
				break;
			}
	}
	return 0;
}
