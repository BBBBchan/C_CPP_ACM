#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string a;
string b;
string BinToHex(const string &strBin, bool bIsUpper = false)
{
    string strHex;
    for(int i = 0; i < 4; i++){
    	int temp = 0;
    	for(int j = 0; j < 4; j++){
    		if(strBin[i*4+j] == '1'){
    			temp += 1<<(3-j);
    		}
    	}
    	if(temp < 10){
    		strHex += char('0'+temp);
    	}
    	else{
    		strHex += char('a'+(temp-10));
    	}
    }
    return strHex;
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int times = 1; times <= t; times++){
		cin >> a;
		b = "";
		for(int i = 0; i < 8; i++){
			string temp = a.substr(i*16, 16);
			//cout << temp<<endl;
			temp = BinToHex(temp);
			int pos = 0;
			while(temp[pos] == '0'){
				pos++;
			}
			if(i != 0)
				b += ':';
			b += temp.substr(pos);
		}
	//	cout << b <<endl;
		int coun = 0, mcoun=2,pos = b.size();
		for(int i = 0; i < b.size(); i++){
			coun = 0;
			while(b[i+coun] == ':'){
				coun++;
				if(coun >= mcoun){
					mcoun = coun;
					pos = i;
				}
			}
		}
		string ans = "";
		if(pos != b.size()){
			 ans = b.substr(0,pos) + "h" +b.substr(pos+mcoun);
		}
		else{
			ans = b;
		}
	//	cout << ans << endl;
		cout << "Case #" << times <<": ";
		for(int i = 0; i < ans.size(); i++){
			if(i == 0 && ans[i] == ':'){
				cout << "0:";
				continue;
			}
			else if(ans[i] == ':' && ans[i-1] == ':'){
				cout << "0:";
				continue;
			}
			if(ans[i] == 'h'){
				cout << "::";
				continue;
			}
			else
				cout << ans[i];
			if(i == ans.size()-1 && ans[i] == ':'){
				cout << "0" ;
			}
		}
		cout << endl;
	}	
	return 0;
}
//00000000000000000000000000000000000000000000000000000000000000010000000000000001000000000000000100000000000000010000000000000001
//00000000000000010000000000000001000000000000000100000000000000010000000000000001000000000000000100000000000000010000000000000001
//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
//10000000000000000000000000000000000000000000000000000000000000010000000000000001000000000000000000000000000000000000000000000000


