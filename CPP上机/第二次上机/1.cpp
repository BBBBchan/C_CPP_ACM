#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char a[1000],b[1000];
string cat(char *a, char *b){
	int a_len = strlen(a), b_len = strlen(b);
	char *ans = new char[a_len+b_len+1];
	for(int i = 0; i < a_len; i++){
		ans[i] = a[i];
	}
	for(int i = a_len; i < a_len+b_len; i++){
		ans[i] = b[i-a_len];
	}
	ans[a_len+b_len] = '\0';
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%s %s", a, b);
	string ans = cat(a,b);
	cout << ans;
	return 0;
}