#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define MAXN 100010
using namespace std;
long long gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
struct Fraction{
    long long num;
    long long den;
    Fraction(long long num=0,long long den=1){
    	if(den<0){
    		num=-num;
    		den=-den;
    	}
    	//assert(den!=0);
    	long long g=gcd(abs(num),den);
    	this->num=num/g;
    	this->den=den/g;
    }
    bool operator < (const Fraction &o)const{
    	return num*o.den<den*o.num;
    }
    bool operator == (const Fraction &o)const{
    	return num*o.den==den*o.num;
    }
};
int main()
{
    int i,j,k;
    long long a,b,c,d;
    while(cin>>a>>b>>c>>d){
    	if(Fraction(a,b)==Fraction(c,d)){
    		cout<<"="<<endl;
        }
        else if(Fraction(a,b)<Fraction(c,d)){
        	cout<<"<"<<endl;
        }
        else{
        	cout<<">"<<endl;
        }
    }
    return 0;
}