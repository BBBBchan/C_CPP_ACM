#include<string.h>
#include<algorithm>
#include<queue>
#include <stdio.h> 
using namespace std;
#define INF 0xffffff
#define MAXN 100005
struct node_1{
    int to;
    int val;
    int next;
};
struct node_2{
    int to;
    int g,f;
    bool operator<(const node_2 &r ) const{  
        if(r.f==f)  
            return r.g<g;  
        return r.f<f;  
    }   
};
node_1 edge[MAXN],edge2[MAXN];
int S,E,K,cnt,cnt2,ans;
int dis[1010],visit[1010],head[1010],head2[1010];
void addedge(int from,int to,int val){
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
void addedge2(int from,int to,int val){
    edge2[cnt2].to=to;
    edge2[cnt2].val=val;
    edge2[cnt2].next=head2[from];
    head2[from]=cnt2++;
}
bool spfa(int S,int n,int head[],node_1 edge[],int dist[])  {  
    queue<int>Q1;  
    int inq[1010];  
    for(int i=0;i<=n;i++)  {  
        dis[i]=INF;  
        inq[i]=0;  
    }  
    dis[S]=0;  
    Q1.push(S);  
    inq[S]++;  
    while(!Q1.empty()){  
        int q=Q1.front();  
        Q1.pop();  
        inq[q]--;  
        if(inq[q]>n)
            return false;  
        int k=head[q];  
        while(k>=0){  
            if(dist[edge[k].to]>dist[q]+edge[k].val){  
                dist[edge[k].to]=edge[k].val+dist[q];  
                if(!inq[edge[k].to]){  
                    inq[edge[k].to]++;  
                    Q1.push(edge[k].to);  
                }  
            }  
            k=edge[k].next;  
        }  
    }  
    return true;  
}
int A(int S,int t,int n,int k,int *head, node_1 *edge,int *dist){  
    node_2 e,ne;  
    int cnt=0;  
    priority_queue<node_2>Q;  
    if(S==t)
        k++;  
    if(dis[S]==INF)  
        return -1;  
    e.to=S;  
    e.g=0;  
    e.f=e.g+dis[e.to];  
    Q.push(e);
    while(!Q.empty()){  
        e=Q.top();  
        Q.pop();  
        if(e.to==t){  
            cnt++;  
        }  
        if(cnt==k){  
            return e.g;  
        }  
        for(int i=head[e.to]; i!=-1; i=edge[i].next)  {  
            ne.to=edge[i].to;  
            ne.g=e.g+edge[i].val;  
            ne.f=ne.g+dis[ne.to];  
            Q.push(ne);  
        }  
    }  
    return -1;  
}  
int main(){   
    int n, m, max, ans;
    while(scanf("%d%d",&n,&m) != EOF){
        memset(head,-1,sizeof(head));
        memset(head2,-1,sizeof(head2));
        cnt=cnt2=1;
        scanf("%d %d %d %d",&S, &E, &K, &max);
        for(int i=0; i<m; i++)
        {
            int a, b, c;
            scanf("%d %d %d",&a, &b, &c);
            addedge(a,b,c);
            addedge2(b,a,c);
        }
        spfa(E,n,head2,edge2,dis);
        ans=A(S,E,n,K,head,edge,dis);
        if(ans != -1 && ans <= max)
            printf("yareyaredawa\n");
        else
            printf("Whitesnake!\n");
    }
    return 0;
}