#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXN 500010
using namespace std;
int n,a[MAXN],b[MAXN],check1=0;
int check(int ll,int rr){
	//cout<<ll<<" "<<rr<<endl;
	//system("pause");
	if(check1==1)return 0;
	if(ll>=rr)return 1;
	int t1=a[ll],t2=b[ll],p1=ll,p2=ll;
	for(int i=ll;i<=rr;i++){
       if(a[i]<t1){
       	   t1=a[i];
       	   p1=i;
       }
       if(b[i]<t2){
       	   t2=b[i];
       	   p2=i;
       }
	}
	if(p1!=p2){check1=1;return 0;}
	if(check(ll,p1-1)==1&&check(p1+1,rr)==1)return 1;
	return 1;
}
int main()
{
    int i,j,k;
    while(~scanf("%d",&n)){
    	for(i=1;i<=n;i++)
    		scanf("%d",&a[i]);
    	for(i=1;i<=n;i++)
    		scanf("%d",&b[i]);
    	int l=1,r=n,mid=0;
    	while(l<=r){
    		mid=(l+r)>>1;
    		//cout<<l<<" "<<r<<endl;
    		check1=0;
    		if(check(1,mid)==1){
    			l=mid+1;
    		}else{
    			r=mid-1;
    		}
    	}
    	cout<<l-1<<endl;
    }
    return 0;
}