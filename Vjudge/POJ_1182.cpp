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
        r[x] = (r[x]+r[f])%3;
    }
     return fa[x];
}
 
int main()
{
    scanf("%d %d",&n, &m);
    for(int i = 1  ; i <= n ; ++i)
        fa[i] = i;
    memset(r,0,sizeof(r));
    int cnt = 0;
    for(int i = 1; i <= m ; ++i)
    {
        int x, y, d;
        scanf("%d %d %d", &d, &x, &y);
        int a = find(x);
        int b = find(y);
        if(x>n || y>n || (d==2&&x==y))
            cnt++;
        else if(a == b){
            if(d==1 && r[x]!=r[y])
                cnt++;
            if(d==2 && (r[x]+1)%3 != r[y])
                cnt++;
        }
        else{
            fa[b] = a;
            r[b] = (r[x]-r[y]+3+(d-1))%3;
        }
    }
    printf("%d", cnt);
    return 0;
}