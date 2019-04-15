#include <cstdio>
#include <cstring>
char a[15],b[1000005];
int first_kase = 0;
int ans =0, len=0,pos,kase = 0;
int main(int argc, char const *argv[])
{
	gets(a);
	gets(b);
	int len_a = strlen(a), len_b = strlen(b);
	for(int i = 0; i < len_a; i++){
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i]-'A'+'a';
	}
	for(int i = 0; i < len_b; i++){
		if(b[i] >= 'A' && b[i] <= 'Z')
			b[i] = b[i]-'A'+'a';
	}
	
	for(int i = 0; i < len_b; i++){
		kase = 1;
		for(int j = 0; j <len_a; j++){
			if(b[i] != '\0' && a[j] == b[i]){
				i++;
			}
			else
				kase = 0;
		}
		if(kase == 1 && (b[i] == ' ' || b[i] == '\0')){
			ans++;
			if(first_kase == 0){
				first_kase = 1;
				pos = i-len_a;
			}
		}
		while(b[i] != ' ' && b[i] != '\0')
			i++;
	}
	if(ans > 0)
		printf("%d %d", ans, pos);
	else
		printf("-1");
	return 0;
}