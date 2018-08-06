#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 200005
int fa[maxn];
int n , m;
int sum[maxn];
int find(int x)
{
    if( fa[x] != x ){
        int f = fa[x];
        fa[x] = find(fa[x]);
        sum[x] += sum[f];
    }
     return fa[x];
}
 
int main()
{
    while(scanf("%d %d",&n, &m) != EOF)
    {
        for(int i = 1  ; i <= n ; ++i)
            fa[i] = i;
        memset(sum,0,sizeof(sum));
        int cnt = 0;
        for(int i = 1; i <= m ; ++i)
        {
            int a, b , c;
            scanf("%d %d %d", &a, &b, &c);
            a--;
            int x = find(a);
            int y = find(b);
            if( x == y )
            {
                if( sum[b] - sum[a] != c  )
                    cnt++;
            }
            else
            {
                fa[y] = x;
                sum[y] = sum[a] + c - sum[b];
            }
        }
        printf("%d\n", cnt);;
    }
}
