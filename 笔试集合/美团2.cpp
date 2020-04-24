#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string a;
	while(cin >> a){
		// cout << a << endl;
		int kase2 = 0, kase3 = 0, count1 = 0, count2 = 0;
		for(int i = 0; i < a.size(); i++){
			if(a[i] == '.'){
				kase2 = 1;
				continue;
			}
			if(kase2){
				count2++;
				if(count2 == 2){
					break;
				}
			}
			else{
				count1++;
			}
		}
		// printf("%d\n", count1);
		if(a[0] == '-'){
			kase3 = 1;
		}
		string ans = "";
		if(kase3){
			ans += "($";	
		}
		else{
			ans += "$";
		}
		int num1 = count1/3, num2 = count1%3;
		for(int i = 1; i <= count1; i++){
			if(a[i-1] == '-')
				continue;
			ans+=a[i-1];
			if((i-num2) %3 == 0 && i!=count1){
				ans+=',';
			}
		}
		ans+='.';
		if(count2 == 0){
			ans+='0';
			ans+='0';
		}
		else if(count2 == 1){
			ans+=a[count1+1];
			ans+='0';
		}
		else{
			ans+=a[count1+1];
			ans+=a[count1+2];
		}		
		if(kase3)
			ans+=")";
		cout << ans <<endl;
	}
	return 0;
}