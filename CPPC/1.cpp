#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
string transform(int x,int y,long long sum){
    string res="";
    while(sum){
        char tmp=sum%y;
        sum/=y;
        if(tmp<=9){
           tmp+='0';           
        }else{
           tmp=tmp-10+'A';      
        }           
        res=tmp+res;
    }
    if(res.length()==0)res="0";
    return res;
}
int main(int argc, char const *argv[])
{
	int t;
	// scanf("%d", &t);
	// while(t--){
		long long a, b;
		long long  minn = 10000;
		long long minpos = 10000;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a&b);
		// for(int i = 1; i < 1000; i++){

		// 	if(((a^i)&(b^i)) < minn){
		// 		minn = (a^i)&(b^i);
		// 		printf("%d %lld\n", i,minn);
		// 		minpos = i;
		// 	}
		// }
		if((a&b) != 0){
			printf("%lld\n", a&b);
		}
		else{
			long long pos = 1000;
			string s1 = transform(10,2,a);
			string s2 = transform(10,2,b);
			cout << s1<<endl;
			cout<< s2<<endl;
			for(int i = 0; i < min(s1.size(), s2.size()); i++){
				if(s1[s1.size()-1-i] != s2[s2.size()-1-i]){
					pos = i;
					break;
				}
			}
			printf("%lld\n", 1LL<<pos);
		}
//	}
	return 0;
}
//6756 8328