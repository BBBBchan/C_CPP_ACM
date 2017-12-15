#include <stdio.h>
#include <string.h>
char a[100];
int b[100];
int main(){
	while(scanf("%s",&a) == 1){
		int n = strlen(a);
		int sum = 0;
		for(int i = 0;i < n;i++){
			b[i] = a[i]-'0';
		}
		for(int i = 0;i<n;i++){
			int kase = 0;
			while(b[i] == 31){
				if(b[i++] == 31)	{
				
				kase++;sum += kase;
				}			
			}
		}
		printf("%d",sum);
	}
	return 0;
}
