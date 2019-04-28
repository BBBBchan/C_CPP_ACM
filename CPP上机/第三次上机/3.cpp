#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
string upper(string a){
	for(int i = 0; i < a.size(); i++){
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] = a[i] - 'a' + 'A';
	}
	return a;
}
int main(int argc, char const *argv[])
{
	string a;
	cin >> a;
	a = upper(a);
	cout << a;
	return 0;
}