#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define STACK_INIT_SIZE 5
#define INCREMENT 10
using namespace std;
char maze[20][20];
int m,n;
typedef struct{
    int x;
    int y;
}PosType;
typedef struct{
    int order;
    PosType seat;
    int di;
}SElemType;
typedef struct{
	SElemType *base;
	SElemType * top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S){
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
void Push(SqStack &S, SElemType e){
	if(S.top - S.base == S.stacksize){
		S.base = (SElemType*)realloc(S.base, (S.stacksize+INCREMENT)*sizeof(SElemType));
		if(!S.base)
			return;
		S.top = S.base + S.stacksize;
		S.stacksize += INCREMENT;
	}
	*(S.top) = e;
	S.top++;
}
void Pop(SqStack &S, SElemType &e){
	if(S.top == S.base)
		return ;
	S.top--;
	e = *(S.top);
}
void Mark(PosType curpos, int mode){
    if(mode == 1)
        maze[curpos.x][curpos.y] = '*';
    else if(mode == 0)
        maze[curpos.x][curpos.y] = '#';
}
PosType Nextpos(PosType curpos, int di){
    PosType nextpos;
    switch(di){
        case 1: nextpos.x= curpos.x+1; nextpos.y = curpos.y; break;
        case 2: nextpos.x= curpos.x; nextpos.y = curpos.y+1; break;
        case 3: nextpos.x= curpos.x-1; nextpos.y = curpos.y; break;
        case 4: nextpos.x= curpos.x; nextpos.y = curpos.y-1; break;
    }
    return nextpos;
}
void maze_solve(){
    SqStack S;
    InitStack(S);
    int curstep = 1;
    PosType curpos;
    curpos.x = 0; curpos.y = 0;
    do{
        if(curpos.x < m && curpos.x>=0 && curpos.y>=0 && curpos.y < n && maze[curpos.x][curpos.y] == '0'){
            Mark(curpos,1);
            SElemType e;
            e.order = curstep; e.seat = curpos; e.di = 1;
            Push(S,e);
            if(curpos.x == m-1 && curpos.y == n-1)
                break;
            curpos = Nextpos(curpos, 1);
            curstep++;
        }
        else{
            SElemType e;
            if(S.top != S.base)
                Pop(S,e);
            while(e.di == 4 && S.top != S.base){
                Mark(e.seat, 0);
                Pop(S,e);
            }
            if(e.di < 4){
                e.di++;
                Push(S,e);
                curpos = Nextpos(e.seat, e.di);
            }
        }
    }while(S.top != S.base);
    while(S.top!=S.base){
        SElemType e;
        Pop(S, e);
        printf("(%d, %d, %d)\n", e.seat.x+1, e.seat.y+1, e.di);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            printf("%c", maze[i][j]);;
        } 
        printf("\n");            
    }
}
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            cin>>maze[i][j];
        }
    maze_solve();
    return 0;
}
