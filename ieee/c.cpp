#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXN 100010
using namespace std;
int t;
int f[MAXN];
bool book[20][20];
int main()
   { 
       int i,j,k;
       f[1]=1;
       f[0]=1;
       for(i=2;i<=100;i++)
       	   f[i]=(f[i-1]+f[i-2])%10;
       int pos=0;
       for(i=1;i<=100;i++)
       {
       	   if(book[f[i]][f[i-1]]==1)
       	   	  {pos=i-2;break;}
       	   book[f[i]][f[i-1]]=1;
       }
       scanf("%d",&t);
       while(t--)
       {
       	   int m;
       	   scanf("%d",&m);
       	   printf("%d\n",f[m%60]);
       }
       return 0;
   }

