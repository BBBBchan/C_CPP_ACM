#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string a, b;
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> a >> b;
		int a1 = 0, b1 = 0;
			for(int i = b.size()-1; i >= 0; i--){
				if(b[i] == '1'){
					b1 = i;
					break;
				}
			}
			for(int i = a.size()-(b.size()-b1); i >= 0; i--){
				if(a[i] == '1'){
					a1 = i;
					break;
				}
			}
			cout << b1+(a.size()-b.size())-a1<<endl;
	}
	return 0;
}