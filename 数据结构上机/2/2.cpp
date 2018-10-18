#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define INCREMENT 10
typedef struct{
	char *base;
	char * top;
	int stacksize;
}SqStack;
void InitStack(SqStack &S){
	S.base = (char*)malloc(STACK_INIT_SIZE*sizeof(char));
	if(!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void Push(SqStack &S, char e){
	if(S.top - S.base == S.stacksize){
		S.base = (char*)realloc(S.base, (S.stacksize+INCREMENT)*sizeof(char));
		if(!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top) = e;
	S.top++;
}
void Pop(SqStack &S){
	if(S.top == S.base)
		return ;
	S.top--;
}
void Check(char *expr){
	SqStack S;
	InitStack(S);
	for(int i = 0; expr[i] != '\0'; i++){
		if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
			Push(S,expr[i]);
		else if((expr[i] == ')' && *(S.top - 1) == '(') || (expr[i] == ']' && *(S.top - 1)== '[') || (expr[i] == '}' && *(S.top - 1) == '{')){
			Pop(S);
		}
		else if(expr[i] != '(' || expr[i] != ')' || expr[i] != '[' || expr[i] != ']' || expr[i] != '{' || expr[i] != '}')
			continue;
		else{
			printf("No\n");
			return;
		}
	}
	if(S.top == S.base)
		printf("Yes\n");
	else
		printf("No\n");
}
int main(int argc, char const *argv[])
{
	char expr[100];
	scanf("%s", expr);
	Check(expr);
	return 0;
}