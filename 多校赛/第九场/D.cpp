#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
long long n;
long long s;
long long a[40];
int book[MAXN];
long long b[MAXN];
void print(long long x){
    string s;
    while(x>0){
        long long tmp=x%2;
        s+=char(tmp+'0');
        x/=2;         
    }    
    cout<<s<<endl;
}
int main()
{
    scanf("%lld%lld",&n,&s);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    //sort(a+0,a+n);
    //cout<<(long long)(1<<(36))<<endl;
    long long i1=0LL,i2=(1LL<<n);
    while(i1<i2){
        i1++;i2--;
        long long sum=0LL;
        //cout<<((1<<n))<<" ";
       // print(i);
        for(long long j=0;j<n;j++){
            if(i1&(1<<j))sum+=a[j];
            if(sum>s||sum<0)break;
            if(sum==s){print(i1);return 0;}                 
        } 
        sum=0LL;
        for(long long j=0;j<n;j++){
            if(i2&(1<<j))sum+=a[j];
            if(sum>s||sum<0)break;
            if(sum==s){print(i2);return 0;}                 
        }       
    }
    //system("pause");
    return 0;
}