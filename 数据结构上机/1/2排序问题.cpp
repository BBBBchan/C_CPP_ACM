#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void CreateList_L(LinkList &L, int n){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(int i = n; i > 0; i--){
        int temp;
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}
void GetElem_L(LinkList &L, int i, int &e){
    LinkList p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return;
    }
    e = p->data;
}
void Modify_L(LinkList &L, int i, int e){
    LinkList p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return;
    p->data = e;
}
void sort_L(LinkList &L, int n){
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            int temp1, temp2;
            GetElem_L(L,i,temp1);
            GetElem_L(L,j,temp2);
            if(temp1 < temp2){
                int q;
                Modify_L(L,i,temp2);
                Modify_L(L,j,temp1);
            }
        }
}
void print_all(LinkList &L){
    LinkList p = L->next;
    if(!p)
        printf("empty");
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    LinkList L;
    int n;
    scanf("%d", &n);
    CreateList_L(L,n);
    print_all(L);
    sort_L(L,n);
    print_all(L);
}
