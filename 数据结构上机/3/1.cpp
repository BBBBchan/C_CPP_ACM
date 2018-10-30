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
void print(SqString s){
	for(int i = 0; i < s.length; i++)
		printf("%c", s.ch[i]);
	printf("\n");
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
	for(int i = 0; i < s1->length && i < s2->length; i++){
		if(s1->ch[i] != s2->ch[i]){
			return s1->ch[i]-s2->ch[i];
		}
	}
	if(s1->length>s2->length)
		return 1;
	else if(s1->length < s2->length)
		return -1;
	return 0;
}
int StrIndex(SqString *s1, SqString *s2){
	int n = s1->length;
	int m = s2->length;
	if(m>n)
		return -1;
	int i = 0, j = 0;
	while(i < n && j <m){
		if(s1->ch[i] == s2->ch[j]){
			i++;
			j++;
		}
		else{
			i = i-j+1;
			j = 0;
		}
	}
	if(j == m)
		return(i-m)+1;
	return -1;
}
void StrInsert(SqString *s1, int i, SqString *s2){
	s1->length += s2->length;
	if(i+s2->length > MaxStrlen || i > s1->length)
		return;
	for(int j = s1->length-1; j >= i-1; j--){
		s1->ch[j+s2->length] = s1->ch[j];
	}
	for(int j = i-1; j<i-1+s2->length; j++){
		s1->ch[j] = s2->ch[j-(i-1)];
	}
}
void StrDelete(SqString *s, int i, int t){
	if(i<0|| i > s->length || i+t>s->length+1)
		return;
	for(int j = i+t-1; j < s->length; j++){
		s->ch[j-t] = s->ch[j];
	}
	s->length -= t;
}
void strRep(SqString *s1, SqString *s2, SqString *s3){
	int n = s1->length, m = s2->length, x = s2->length;
	int temp = StrIndex(s1,s2);
	print(*s3);
	while(temp!= -1){
		StrDelete(s1,temp,m);
		StrInsert(s1,temp,s3);
		temp = StrIndex(s1,s2);
	}
}
int main(int argc, char const *argv[])
{
	SqString s1, s2, s3, s4, s5;
	StrAssign(&s1,"abcd");
	StrAssign(&s2, "efgh");
	StrAssign(&s4, "efgh");
	StrAssign(&s5, "1234");
	print(s1);
	print(s2);
	StrConcat(&s1, &s2);
	print(s1);
	s3 = SubStr(&s1, 3, 4);
	print(s3);
	printf("%d\n", StrCmp(&s4, &s2));
	printf("%d\n", StrIndex(&s1, &s2));
	StrInsert(&s1, 4, &s5);
	print(s1);
	StrDelete(&s1,4,4);
	print(s1);
	StrConcat(&s1,&s4);
	strRep(&s1,&s2,&s5);
	print(s1);
	return 0;
}