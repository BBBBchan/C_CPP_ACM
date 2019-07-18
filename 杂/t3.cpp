#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 100010
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int i,j,k;
	cin>>i>>j;
	cout<<gcd(i,j)<<endl;
	long long x1,x2,x3,y1,y2,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		//double l1=0,l2=0,l3=0;
		cout<<(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3)/2<<endl;
	}
	return 0;
}