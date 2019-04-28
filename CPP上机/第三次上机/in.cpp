#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("in.cpp", "r", stdin);
	string a;
	string b = "#include";
	while(getline(cin,a)){
		string c;
		if(a.find(b) != string::npos){
			for(int i = 0; i < a.size(); i++){
				if(a[i] == '<'){
					cout << "here"<<endl;
					int j = i+1;
					while(a[j] != '>' && j < a.size()){
						c+=a[j];
						j++;
					}
					break;
				}
			}
		}
		if(!c.empty())
			cout << c <<'	';
	}
	return 0;
}