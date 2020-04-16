#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int t,n,mem[5100],ant,ans;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<n+1;i++)
		{
			cin>>mem[i];
		}
		ant=0;
	    for(int i=1;i<n+1;i++)
	    {
	    	for(int j=i+2;j<n+1;j++)
	    	{
	    		if(mem[i]==mem[j]){
	    			ant=1;
	    			break;
				}
			}
			if(ant)
			break;
		}
		if(ant)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
