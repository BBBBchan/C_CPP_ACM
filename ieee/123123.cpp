#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<cstring>
#define MAXN 100010
using namespace std;
struct point{
	int id,len;
	string s[21];
}po[MAXN];
map<string,int>ma;
int cnt=0;
int main()
    {
    	int i,j,k,t;
    	while(~scanf("%d",&t))
    	{
    		string ss;
            po[++cnt].id=t;
            int cnt2=0;
    		while(cin>>ss)
    		{
                po[cnt].s[++cnt2]=ss;
                po[cnt].len=cnt2;
    		}
    	}
        int cnt3=0;
        for(i=1;i<=cnt;i++)
        {
            for(j=1;j<=po[i].len;j++)
            {
                if(!ma[po[i].s[j]])
                {
                    ma[po[i].s[j]]=++cnt3;
                }
            }
        }
        for(i=1;i<=cnt;i++)
        {
            printf("%d\n",po[i].id);
            for(j=1;j<=po[i].len;j++)
            {
                cout<<ma[po[i].s[j]]<<" ";
            }
            printf("\n");
        }
    	return 0;
    }
