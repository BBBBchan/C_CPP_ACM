#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";		//	每个字母对应的暗号
const char* msg[] = {"not a palindromes","a regular palindromes","a mirrored string","a mirrored palindromes"};
char r(char ch){
	if(isalpha(ch)) return rev[ch - 'A'];//返回字母在rev中的位置
	return rev[ch - '0' + 25];			//返回数字在rev中的位置
} 
int main()
{
	char s[30];							
	while(scanf("%s",&s) == 1){			
		int len = strlen(s);
		int p = 1, m = 1;
		for(int i = 0;i < (len + 1)/2; i++){
			if(s[i] != s[len-1-i])  p = 0;//检测回文
			if(r(s[i]) != s[len-1-i])  m = 0;//检测镜像
		} 
		printf("%s -- %s.\n\n",s,msg[m*2+p]);
	}
	return 0;
}