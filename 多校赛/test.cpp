#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define MAXN 100010
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("test.in","w",stdout);
    cout<<1<<endl;
    int n=rand()%10;
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
       int x=rand()%1000,y=rand()%1000;
       if(x%2==0)x*=-1;
       if(y%2==0)y*=-1; 
       cout<<x<<" "<<y<<endl;       
    }    
    return 0;
}