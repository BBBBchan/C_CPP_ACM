#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    int num;
    int code;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreateList_L(int n){
    LinkList p, rear;
    p = (LinkList)malloc(sizeof(LNode));
    if(!p)
        return NULL;
    scanf("%d", &p->code);
    p->num = 1;
    p->next = p;
    rear = p;
    for(int i = 2; i <= n; i++){
        LinkList q = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &q->code);
        q->num = i;
        q->next = rear->next;
        rear->next = q;
        rear = q;
    }
    return rear;
}
void Joesph(LinkList &tail, int n, int m){
    LinkList pre, p;
    int k = 1;
    m = m%n ? m%n:n;
    pre = tail;
    p = tail->next;
    while(n>1){
        if(k == m){
            printf("%d ", p->num);
            pre->next = p->next;
            n--;
            m = (p->code)%n ? (p->code)%n : n;
            free(p);
            p = pre->next;
            k = 1;
        }
        else{
            k++;
            pre = p;
            p = p->next;
        }
    }
    printf("%d\n", p->num);
}
void print_all(LinkList head){
    LinkList p = head;
    do{
        printf("%d %d    ", p->num, p->code);
        p = p->next;
    }while(p!=head);
    printf("\n");
}
int main(){
    LinkList tail;
    int n, code1;
    scanf("%d %d", &n, &code1);
    tail = CreateList_L(n);
    print_all(tail->next);
    Joesph(tail,n,code1);
    return 0;
}
