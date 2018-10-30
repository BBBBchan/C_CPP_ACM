#include <stdio.h>
#include <stdlib.h>
#define MaxStrlen 100
typedef struct {
	char ch[MaxStrlen];
	int length;
}SqString;
int StrLength(SqString s){
	return s.length;
}
void StrAssign(SqString *s1, char *chars){
	int i;
	s1->length = 0;
	for(i = 0; chars[i] != '\0' ; i++){
		if(i>=MaxStrlen)
			return;
		s1->ch[i] = *(chars+i);
	}
	s1->length = i;
}
void StrConcat(SqString *s1, SqString *s2){
	int n = StrLength(*s1);
	int m = StrLength(*s2);
	if(n+m > MaxStrlen)
		return;
	for(int i = n; i < n+m; i++)
		s1->ch[i] = s2->ch[i-n];
	s1->length = n+m;
}
SqString SubStr(SqString *s, int i, int len){
	SqString ans;
	ans.length = 0;
	if(i+len>StrLength(*s))
		return ans;
	for(int j = i-1; j < i+len-1; j++){
		ans.ch[j-i+1] = s->ch[j];
	}
	ans.length = len;
	return ans;
}
int StrCmp(SqString *s1, SqString *s2){
	int kase = 1;
	if(s1->length != s2->length){
		return s1->length - s2->length;
	}
	for(int i = 0; i < s1->length; i++){
		if(s1->ch[i] != s2->ch[i]){
			kase = 0;
			break;
		}
	}
	if(kase)
		return 0;
	else
		return -1;
}
void print(SqString s){
	for(int i = 0; i < s.length; i++)
		printf("%c", s.ch[i]);
	printf("\n");
}
int main(int argc, char const *argv[])
{
	SqString s1, s2, s3, s4;
	StrAssign(&s1,"abcd");
	StrAssign(&s2, "efgh");
	StrAssign(&s4, "efgh");
	print(s1);
	print(s2);
	StrConcat(&s1, &s2);
	print(s1);
	s3 = SubStr(&s1, 3, 4);
	print(s3);
	printf("%d\n", StrCmp(&s4, &s2));
	return 0;
}