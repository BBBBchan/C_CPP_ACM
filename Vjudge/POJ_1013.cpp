#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int t,ans[12],count[12]={0};
	char a[7], b[7], c[5];
	scanf("%d", &t);
	while(t--){
		memset(ans,0,sizeof(ans));
		for(int p = 0; p < 3; p++){
			scanf("%s %s %s", a, b, c);
			if(c[0] == 'e'){
				for(int i = 0; i < strlen(a); i++)
					ans[a[i]-'A'] = 1;
				for(int j = 0; j < strlen(b); j++)
					ans[b[j]-'A'] = 1;
			}
			else if(c[0] == 'u'){
				for(int i = 0; i < strlen(a); i++){
					count[a[i]-'A'] = 1;
					if(ans[a[i]-'A'] == 1)
						continue;
					else if(ans[a[i]-'A'] == -1)
						ans[a[i]-'A'] = 1;
					else
						ans[a[i]-'A'] = 2;
				}
				for(int j = 0; j < strlen(b); j++){
					count[b[j]-'A'] = 1;
					if(ans[b[j]-'A'] == 1)
						continue;
					else if(ans[b[j]-'A'] == 2)
						ans[b[j]-'A'] = 1;
					else
						ans[b[j]-'A'] = -1;
				}
				for(int i = 0; i < 12; i++){
					if(count[i] == 0)
						ans[i] = 1;
				}
				memset(count,0,sizeof(count));
			}
			else if(c[0] == 'd'){
				for(int i = 0; i < strlen(a); i++){
					count[a[i]-'A'] = 1;
					if(ans[a[i]-'A'] == 1)
						continue;
					else if(ans[a[i]-'A'] == 2)
						ans[a[i]-'A'] = 1;
					else
						ans[a[i]-'A'] = -1;
				}
				for(int j = 0; j <strlen(b); j++){
					count[b[j]-'A'] = 1;
					if(ans[b[j]-'A'] == 1)
						continue;
					else if(ans[b[j]-'A'] == -1)
						ans[b[j]-'A'] = 1;
					else
						ans[b[j]-'A'] = 2;
				}
				for(int i = 0; i < 12; i++){
					if(count[i] == 0)
						ans[i] = 1;
				}
				memset(count,0,sizeof(count));
			}
		}
		for(int i = 0; i < 12; i++){
			if(ans[i] != 1){
				printf("%c is the counterfeit coin and it is ", i+'A');
				if(ans[i] == -1)
					printf("light.\n");
				else
					printf("heavy.\n");
			}
		}
	}
	return 0;
}