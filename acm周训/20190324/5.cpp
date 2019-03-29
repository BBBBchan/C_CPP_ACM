#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
long long n;
long long b[MAXN][4];
long long a[MAXN][3];
long long ans[MAXN];
char ch[4]={'0','+','-','*'};
int main()
   {
   	  long long i,j,k;
   	  while(~scanf("%lld",&n))
   	  {
   	  	 map<long long,long long>ma;
         map<long long,long long>ma1;
         memset(b,0,sizeof(b));
         memset(a,0,sizeof(a));
         long long check=0;
         for(i=1;i<=n;i++)
         {
         	scanf("%lld%lld",&a[i][1],&a[i][2]);
         	b[i][1]=a[i][1]+a[i][2];
         	b[i][2]=a[i][1]-a[i][2];
         	b[i][3]=a[i][1]*a[i][2];
         	ma[b[i][1]]++;
         	ma[b[i][2]]++;
         	ma[b[i][3]]++;
         }
         for(i=1;i<=n;i++)
         	 {
                if(ma[b[i][1]]<=ma[b[i][2]]&&ma[b[i][1]]<=ma[b[i][3]]&&ma1[b[i][1]]!=1)
                {
                	ma1[b[i][1]]=1;
                	ans[i]=1;
                }
                else if(ma[b[i][1]]<=ma[b[i][2]]&&ma[b[i][1]]<=ma[b[i][3]]&&ma1[b[i][1]]==1)
                {
                	if(ma[b[i][2]]<=ma[b[i][3]]&&ma1[b[i][2]]!=1)
                	{
                		ma1[b[i][2]]=1;
                		ans[i]=2;
                		continue;
                	}
                	else if(ma[b[i][2]]>ma[b[i][3]]&&ma1[b[i][3]]!=1)
                	{
                		ma1[b[i][3]]=1;
                		ans[i]=3;
                		continue;
                	}
                	else
                	{
                		check=1;
                	    printf("impossible\n");
                	    break;
                	}
                }
                else if(ma[b[i][2]]<=ma[b[i][1]]&&ma[b[i][2]]<=ma[b[i][3]]&&ma1[b[i][2]]!=1)
                {
                	ma1[b[i][2]]=1;
                	ans[i]=2;
                }
                else if(ma[b[i][2]]<=ma[b[i][1]]&&ma[b[i][2]]<=ma[b[i][3]]&&ma1[b[i][2]]==1)
                {
                	if(ma[b[i][1]]<=ma[b[i][3]]&&ma1[b[i][1]]!=1)
                	{
                		ma1[b[i][1]]=1;
                		ans[i]=1;
                		continue;
                	}
                	else if(ma[b[i][1]]>ma[b[i][3]]&&ma1[b[i][3]]!=1)
                	{
                		ma1[b[i][3]]=1;
                		ans[i]=3;
                		continue;
                	}
                	else
                	{
                		check=1;
                	    printf("impossible\n");
                	    break;
                	}
                }
                else if(ma[b[i][3]]<=ma[b[i][2]]&&ma[b[i][3]]<=ma[b[i][1]]&&ma1[b[i][3]]!=1)
                {
                	ma1[b[i][3]]=1;
                	ans[i]=3;
                }
                else if(ma[b[i][3]]<=ma[b[i][1]]&&ma[b[i][3]]<=ma[b[i][2]]&&ma1[b[i][3]]==1)
                {
                	if(ma[b[i][1]]<=ma[b[i][2]]&&ma1[b[i][1]]!=1)
                	{
                		ma1[b[i][1]]=1;
                		ans[i]=1;
                		continue;
                	}
                	else if(ma[b[i][1]]>ma[b[i][2]]&&ma1[b[i][2]]!=1)
                	{
                		ma1[b[i][2]]=1;
                		ans[i]=2;
                		continue;
                	}
                	else
                	{
                		check=1;
                	    printf("impossible\n");
                	    break;
                	}
                }
                else{
                	check=1;
                	printf("impossible\n");
                	break;
                }
         	 }
         if(check!=1)
         {
         	for(i=1;i<=n;i++)
         	{
         		printf("%lld %c %lld = %lld\n",a[i][1],ch[ans[i]],a[i][2],b[i][ans[i]]);
         	}
         }
   	  }
   	 return 0;
   }

