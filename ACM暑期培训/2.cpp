#include <cstdio>
#include <cstring>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		char a[1005];
		int b[30];
		for(int i = 0; i < 30; i++)
			b[i] = 0; 
		int kase = 0;
		scanf("%s", a);
		for(int i = 0; i < strlen(a); i++){
			if(b[a[i]-'a'] == 0)
				kase += 1;
			b[a[i]-'a']++;
		}
		if(kase == 1){
			printf("-1\n");
			continue;
		}
		else{
			for(int j = 0; j < 30; j++){
				for(int k = 0; k < b[j]; k++)
					printf("%c", j+'a');
			}
			printf("\n");
		}
	}
	return 0;
}