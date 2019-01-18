#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define LIST_INIT_SIZE 100000
#define LISTINCREMENT 10
#define mod 256
#define lowbit(x) (x&(-x))
#define mem(a,b) memset(a,b,sizeof(a))
#define FRER() freopen("in.txt","r",stdin);
#define FREW() freopen("out.txt","w",stdout);
using namespace std;
const int maxn = 100000 + 7;
char s[maxn];
int n;
typedef struct LNode{
    char c;
    struct LNode* next;
}LNode,*LinkList;
void InitList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
}
void CreateList(LinkList L){
    for(int i=n-1;i>=0;--i){
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->c = s[i];
        p->next = L->next;
        L->next = p;
    }
}
void print(LinkList L){
    LinkList p = L->next;
    int i = 0;
    while(p!=NULL){
        if(i++) printf(" ");
        printf("%c",p->c);
        p = p->next;
    }
    printf("\n");
}
int GetLinkListLength(LinkList L){
    int ans = 0;
    LinkList p = L;
    while(p->next!=NULL){
        p = p->next;
        ans++;
    }
    return  ans;
}
char GetElem(LinkList L,int pos){
    int ans = 1;
    LinkList p = L->next;
    while(p&&ans<pos){
        p = p->next;
        ans++;
    }
    return  p->c;
}
int GetPos(LinkList L,char a){
    int ans = 1;
    LinkList p = L->next;
    while(p&&p->c!=a){ p = p->next;ans++;}
    return  ans;
}
void LinkListInsrt(LinkList L,int pos,char a){
    LinkList p,q;
    p = L;
    q = (LinkList)malloc(sizeof(LNode));
    q->c = a;
    int ans = 1;
    while(p->next&&ans<pos){
        ans++;
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}
void ListDstroy(LinkList&L){
    LinkList p = L;
    LinkList q;
    while(p->next){
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(L);
}
void LinkListDelete(LinkList L,int pos){
    LinkList p = L;
    int ans = 1;
    while(p->next&&ans<pos){
        ans++;
        p = p->next;
    }
    LinkList q = p->next;
    p->next = p->next->next;
    free(q);
}
bool IsEmpty(LinkList L){
    if(L->next==NULL) return  true;
    return  false;
}
int main(){
    LinkList L;
    InitList(L);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf(" %c",&s[i]);
    }
    CreateList(L);
    print(L);
    cout<<GetLinkListLength(L)<<endl;
    printf("%s\n",IsEmpty(L)?"yes":"no");
    printf("%c\n",GetElem(L,3));
    printf("%d\n",GetPos(L, 'a'));
    LinkListInsrt(L, 4, 'f');
    print(L);
    LinkListDelete(L, 3);
    print(L);
    ListDstroy(L);
}
