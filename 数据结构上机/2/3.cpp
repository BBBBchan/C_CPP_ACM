#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define INCREMENT 10
int n;
typedef struct{
    char mode;
    int num;
    int time;
}CAR;
typedef struct{
	CAR *base;
	CAR * top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S){
	S.base = (CAR*)malloc(STACK_INIT_SIZE*sizeof(CAR));
	if(!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void Push(SqStack &S, CAR e){
	if(S.top - S.base == S.stacksize){
		S.base = (CAR*)realloc(S.base, (S.stacksize+INCREMENT)*sizeof(CAR));
		if(!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top) = e;
	S.top++;
}
void Pop(SqStack &S, CAR &e){
	if(S.top == S.base)
		return ;
	S.top--;
	e = *(S.top);
}
void Park(SqStack &S, CAR car ){
    SqStack Q;
    InitStack(Q);
    if(car.mode == 'A'){
        int kase = 1;
        while(S.top != S.base){
            CAR e;
            Pop(S,e);
            Push(Q,e);
            if(e.num == car.num){
                kase = 0;
                printf("this car has been parked\n");
                break;
            }
        }
        while(Q.top != Q.base){
            CAR e;
            Pop(Q,e);
            Push(S,e);
        }
        if(kase){
            Push(S,car);
            if(S.top - S.base > n)
                printf("waiting position: %d\n", S.top-S.base);
            else
                printf("park position: %d\n", S.top-S.base);
        }
    }
    else if(car.mode == 'D'){
        int kase = 0;
        while(S.top != S.base){
            CAR e;
            Pop(S,e);
            if(e.num == car.num){
                kase = 1;
                printf("parking time: %d\n", car.time-e.time);
                break;
            }
            Push(Q,e);
        }
        if(kase == 1){
            while(Q.top != Q.base){
                CAR e;
                Pop(Q,e);
                Push(S,e);
            }
        }
    }
}
int main(){
    SqStack S;
    InitStack(S);
    char mode;
    CAR car;
    scanf("%d", &n);
    while(scanf("%c %d %d", &car.mode, &car.num, &car.time) != EOF){
        Park(S,car);
    }
    return 0;
}
