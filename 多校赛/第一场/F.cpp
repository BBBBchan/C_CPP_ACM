#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 100010
using namespace std;
int main()
{
	int i,j,k;
	long long x1,x2,x3,y1,y2,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		//double l1=0,l2=0,l3=0;
		cout<<11*abs(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3)<<endl;
	}
	return 0;
}