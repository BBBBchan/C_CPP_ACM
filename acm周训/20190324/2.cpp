#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 100010
using namespace std;

int qpow(int n, int m){
	if(m==0)return 1;
	int ans = 1, temp = n;
	while(m!=0){
		if(m&1)
			ans *= temp;
		temp = temp*temp;
		m>>=1;
	}
	return ans;
}
int main()
  {
  	int i,j,k;
  	string s;
  	while(cin>>s)
  	{
  		int l=s.length();
  		int ans1=0,ans2=0;
  		for(i=0;i<l;i++)
  		{
  			if(s[i]=='0'||s[i]=='2')
  				ans1+=0;
  			else
  				ans1+=qpow(2,l-i-1);
  		}
  		for(i=0;i<l;i++)
  		{
  			if(s[i]=='1'||s[i]=='0')
  				ans2+=0;
  			else
  				ans2+=qpow(2,l-i-1);
  		}
  	    printf("%d %d %d\n",l,ans1,ans2);
  	}
  	return 0;
  }
