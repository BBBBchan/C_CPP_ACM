#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int ans = 0;
	int i = 0;
	while(i < s.size()){
		int coun = 0;
		int j = i+1, temp = 0;
		while(j < s.size() && s[i] == s[j]){
			j++;
			coun++;
			if(coun == 2){
				temp++;
				i--;
				coun = 0;
				while(i-1>=0 && s[i] == s[i-1]){
					coun++;
					i -= 1;
				}	
				cout << i+1 << " " << j+1 <<endl;
			}
		}
		ans += temp;
		i  = j;
	}
	cout << ans<<endl;
	return 0;
}

-1 1 1 1 -1 1 1 1
1 -1 1 1 1 -1 1 1
1 1 -1 1 1 1 -1 1
1 1 1 -1 1 1 1 -1
1 1 