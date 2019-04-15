#include <stdio.h>
#include <string.h>
char a[15], b[1000005];
int next[1000005];
int pos = 0, ans = 0, first_kase=0;

int main(int argc, char const *argv[])
{
	gets(a);
	gets(b);
	for(int i = 0; i < strlen(a); i++){
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i]-'A'+'a';
	}
	for(int i = 0; i < strlen(b); i++){
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i]-'A'+'a';
	}
	for(int i = 0; i < strlen(b); i++){
		int kase = 1;
		for(int j = 0; j < strlen(a); j++){
			if(b[i] == ' '){
				kase = 0;
				break;
			}
			else if(b[i] == a[j]){
				i++;
				if(i >= strlen(b))
					break;
			}
			else{
				kase = 0;
				break;
			}
		}
		if(kase && (i>=strlen(b) || b[i] == ' ')){
			if(first_kase == 0){
				pos = i-strlen(a);
				first_kase = 1;
			}
			ans++;
		}
		else{
			while(i < strlen(b) && b[i] != ' ')
				i++;
		}
	}
	if (ans == 0)
	{
		printf("-1");
	}
	else
		printf("%d %d", ans, pos);
	return 0;
}