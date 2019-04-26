#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char b[1000],a[1000];
char *rev(char *a){
	int a_len = strlen(a);
	for(int i = a_len-1; i >=0; i--){
		b[a_len-1-i] = a[i];
	}
	b[a_len] = '\0';
	for(unsigned int i = 0; i < strlen(b); i++){
		a[i] = b[i];
	}
	return a;
}
int main(int argc, char const *argv[])
{
	cin >> a;
	string ans = rev(a);
	cout << ans;
	return 0;
}