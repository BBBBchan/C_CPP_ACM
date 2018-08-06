#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 200005
int fa[maxn];
int n , m;
int r[maxn];
int find(int x)
{
    if( fa[x] != x ){
        int f = fa[x];
        fa[x] = find(fa[x]);
        r[x] = (r[x]+r[f])%2;
    }
     return fa[x];
}

void set(int n){
    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        r[i] = 0;
    }
}

void Union(int x, int y){
    int a = find(x);
    int b = find(y);
    fa[a] = b;
    r[a] = (r[x]+r[y]+1)%2;
}
 
int main()
{
    int t,i=0;
    scanf("%d", &t);
    while(t--){
        i++;
        scanf("%d %d", &n, &m);
        set(n);
        int x, y;
        int kase = 1;
        while(m--){
            scanf("%d %d", &x, &y);
            int a = find(x);
            int b = find(y);
            if(a == b){
                if(r[x] == r[y])
                    kase = 0;
                continue;
            }
            else{
                Union(x,y);
            }
        }

    printf("Scenario #%d:\n", i);
    if(kase) 
        printf("No suspicious bugs found!\n");
    else 
        printf("Suspicious bugs found!\n");
    printf("\n"); 
    }
    return 0;
}
