#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef long long ll;
using namespace std;
const int N = 2010000;
char s[N];
int fa[N],ch[N][26],len[N],siz[N];
int lst=1,node=1,l,t[N],A[N];
ll ans;
void Extend(int c){
		int f=lst,p=++node;
		lst=p;
		len[p]=len[f]+1;
		siz[p]=1;
		while(f&&!ch[f][c]) 
			ch[f][c]=p,f=fa[f];
		if(!f){fa[p]=1;
			return;
		}
		int x=ch[f][c],y=++node;
		if(len[f]+1==len[x]){
			fa[p]=x;
			node--;
			return;
		}
		len[y]=len[f]+1;
		fa[y]=fa[x];
		fa[x]=fa[p]=y;
		memcpy(ch[y],ch[x],sizeof(ch[y]));
		while(f&&ch[f][c]==x) 
			ch[f][c]=y,f=fa[f];
}
int main(){
		int M, N;
		while(scanf("%s",s)!=EOF){
		l=strlen(s);
		scanf("%d %d", &M, &N);
		for(int i=l;i>=1;i--) {s[i]=s[i-1];s[0]=0;}
		for(int i=1;i<=l;i++) Extend(s[i]-'a');
		for(int i=1;i<=node;i++) t[len[i]]++;
		for(int i=1;i<=node;i++) t[i]+=t[i-1];
		for(int i=1;i<=node;i++) A[t[len[i]]--]=i;
		ans = 0;
		int temp = 0;
		for(int i=node;i>=1;i--){
			int temp2 = 0;
			int now=A[i];siz[fa[now]]+=siz[now];
			printf("%d ", siz[now]);
			if(siz[now]>=M&&siz[now]<=N) 
				ans++;
		}
		printf("%lld\n",ans);
		lst = 1;
		node = 1;
		memset(A,0,sizeof(A));
		memset(ch,0,sizeof(ch));
		memset(len,0,sizeof(len));
		memset(siz,0,sizeof(siz));
		memset(t,0,sizeof(t));
	}
		return 0;
}