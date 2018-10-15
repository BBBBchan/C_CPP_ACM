#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void CreateList_L(LinkList &L, int &n){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    int temp,count = 0;
    while(scanf("%d", &temp) != EOF && temp != 0){
        count++;
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->data = temp;
        p->next = L->next;
        L->next = p;
    }
    n = count;
}
void Insert_L(LinkList &L, int i, int e){
    LinkList p = L;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return;
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
}
int GetElem_L(LinkList &L, int i, int &e){
    LinkList p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return -1;
    e = p->data;
    return 0;
}
void print_all(LinkList &L){
    LinkList p = L->next;
    if(!p)
        printf("empty list!");
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void ListDelete_L(LinkList &L, int i){
    LinkList p = L;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i)
        return;
    p->next = p->next->next;
}
int main(){
    LinkList L;
    int n;
    CreateList_L(L,n);
    int ans;
    GetElem_L(L,2,ans);
    print_all(L);
    Insert_L(L,1,999);
    print_all(L);
    for(int i = 0; i < n; i++){
        ListDelete_L(L,1);
        print_all(L);
    }
    return 0;
}
