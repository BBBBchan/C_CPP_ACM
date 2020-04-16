#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int ans = 0;
string t;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin>>t;
		for(int j = 0; j < t.size(); j++){
			int coun = 0;
			while(t[j] == 'L'){
				coun++;
				j++;
				if(coun > ans){
					ans = coun;
				} 
			}
		}
		printf("%d\n", ans+1);
		ans = 0;
	}
	return 0;
}