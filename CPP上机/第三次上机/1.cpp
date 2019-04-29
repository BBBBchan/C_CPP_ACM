#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
int count = 0;
using namespace std;
void find(string c){
	freopen(c.c_str(), "r", stdin);
	vector < string > G(1000000);
	string a, b = "#include",ou = "main";
	int temp  = 0;
	while(getline(cin,a)){
		G[temp] = a;
		temp++;
		if(a.find(ou) != string::npos)
			break;
	}
	for(int i = 0; i < temp; i++){
		a = G[i];
		string c,d;
		if(a.find(b) != string::npos){
			for(int i = 0; i < a.size(); i++){
				if(a[i] == '<'){
					int j = i+1;
					while(a[j] != '>' && j < a.size()){
						c+=a[j];
						j++;
					}
					break;
				}
				else if(a[i] == '"'){
					int j = i+1;
					while(a[j] != '"' && j < a.size()){
						d+=a[j];
						j++;
					}
					break;
				}
			}
		}
		if(!c.empty()){
			for(int i = 0; i < count; i++)
				cout << '\t';
			cout << c <<endl;
		}
		else if(!d.empty()){
			for(int i = 0; i < count; i++)
				cout << '\t';
			cout << d <<endl;
			count++;
			find(d);
			count--;
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("in.cpp", "r", stdin);
	vector < string > G(10000);
	string a;
	string b = "#include", ou = "main";
	int temp = 0;
	while(getline(cin,a)){
		string c;
		G[temp] = a;
		temp++;
		if(a.find(ou) != string::npos)
			break;
	}
	for(int i  = 0; i < temp; i++){
		a = G[i];
		string c,d;
		if(a.find(b) != string::npos){
			for(int i = 0; i < a.size(); i++){
				if(a[i] == '"'){
					int j = i+1;
					while(a[j] != '"' && j < a.size()){
						c+=a[j];
						j++;
					}
					break;
				}
			}
		}
		if(!c.empty()){
			count=1;
			cout << c <<endl;
			find(c);
		}
	}
	return 0;
}