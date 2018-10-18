#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define INCREMENT 10
typedef struct{
	int *base;
	int * top;
	int stacksize;
}SqStack;
void InitStack(SqStack &S){
	S.base = (int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void Push(SqStack &S, int e){
	if(S.top - S.base == S.stacksize){
		S.base = (int*)realloc(S.base, (S.stacksize+INCREMENT)*sizeof(int));
		if(!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top) = e;
	S.top++;
}
void Pop(SqStack &S, int &e){
	if(S.top == S.base)
		return ;
	S.top--;
	e = *(S.top);
}
void Trans(SqStack &S, int N, int d){
	InitStack(S);
	while(N){
		int mod = N%d;
		N/=d;
		Push(S,mod);
	}
	while(S.top != S.base){
		int temp;
		Pop(S,temp);
		printf("%d", temp);
	}
	printf("\n");
}
int main(int argc, char const *argv[]){
	SqStack S;
	int N, d;
	scanf("%d %d", &N, &d);
	Trans(S,N,d);
	return 0;
}